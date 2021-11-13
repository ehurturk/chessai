/* engine.cpp */

#include "../include/engine.h"
#include <cassert>
#include <cstddef>
#include <ncurses.h>

Engine::Engine(const std::string& initial): board(initial) { }

/* init */
void Engine::start() {
	term = create_term();
	print_board();
	print_pieces();
	/* game loop */
	update();
}

/* game loop*/
void Engine::update() {
	while (true) {
		move(term->row/2 + term->row/3, 0);
		echo();
		clrtoeol();
		curs_set(1);
 		printw("Enter the piece you want to play and where to play (e.g. p-e6-e7 or B-c1-e3): ");
		std::string input;
		int ch;
		while ((ch=getch()) != '\n') {
			input.push_back(ch);
		}
		move_piece(input.c_str(), "b1");
		noecho();
		curs_set(0);

		char c=getch();
		if (c==CTRL('q')) {
			break;
		}
 		refresh();
	}
}

void Engine::generate_moves() {
		
}

/*
 * initial board printing.
 * the borders would not be altered during the game
 * however, the pieces would be altered.
*/
void Engine::print_board() {
	/* UPPER LOGO IS 11x82 */
	mvprintw(term->row/2-30, term->col/2-49, C_1);
	mvprintw(term->row/2-29, term->col/2-49, C_2);
	mvprintw(term->row/2-28, term->col/2-49, C_3);
	mvprintw(term->row/2-27, term->col/2-49, C_4);
	mvprintw(term->row/2-26, term->col/2-49, C_5);
	mvprintw(term->row/2-25, term->col/2-49, C_6);
	mvprintw(term->row/2-24, term->col/2-49, C_7);
	mvprintw(term->row/2-23, term->col/2-49, C_8);
	mvprintw(term->row/2-22, term->col/2-49, C_9);
	mvprintw(term->row/2-21, term->col/2-49, C_10);
	mvprintw(term->row/2-20, term->col/2-49, C_11);

	for (int i = 0; i <	BOARD_HEIGHT + 1; i++) {
		std::string line = i % 4 == 0 ? B_LINE : P_LINE; 
		int row, col;
		row = term->row/2+i-15;
		col = (term->col-BOARD_WIDTH)/2;
		if (i % 4 == 2) {
			line = std::to_string((34-i)/4).append(" ").append(line);
			col -= 2;
		}
		mvprintw(row, col, line.c_str());
	}
	mvprintw(term->row/2+BOARD_HEIGHT-14, term->col /2 - BOARD_WIDTH/2, "     a         b         c         d         e         f         g         h     ");
}

std::pair<int, int> get_piece_loc(const char* loc) {
	if (loc == NULL || loc[0]> 0x68 || loc[0]<0x61 || loc[1] > 0x38 || loc[1] < 0x31) {
		return std::make_pair(LOC_UNDEFINED, LOC_UNDEFINED);
	}
	char loc1 = loc[0]; /* a */
	char loc2 = loc[1]; /* 3 */

	int x_offset = 35-10*(loc1-0x61);
	int y_offset = (3-(loc2-0x31))*4;
	y_offset = y_offset > 0 ? y_offset + 2 : y_offset - 2;
	return std::make_pair(x_offset, y_offset);
}

void Engine::print_piece(const char piece, const char* place) {


	std::pair<int, int> offsets = get_piece_loc(place);
	int x_offset = offsets.first;
	int y_offset = offsets.second;

	/*
	 * Unfortunately I couldn't use for loop since the ASCII art is defined using #define.
	 * Thus i can't actually retrieve the ASCII art using PAWN_i since i is being
	 * considered as the char i, not the value of i.
	*/
	switch(piece) {
		case 'p':	
			move(term->row/2+y_offset, term->col/2-x_offset-1);
			printw(PAWN_1);
			move(term->row/2+y_offset+1, term->col/2-x_offset-1);
			printw(WPAWN_2);
			move(term->row/2+y_offset+2, term->col/2-x_offset-1);
			printw(WPAWN_3);
			break;
		case 'k':
			move(term->row/2+y_offset, term->col/2-x_offset-2);
			printw(KNIGHT_1);
			move(term->row/2+y_offset+1, term->col/2-x_offset-2);
			printw(WKNIGHT_2);
			move(term->row/2+y_offset+2, term->col/2-x_offset-2);
			printw(WKNIGHT_3);
			break;
		case 'b':
			move(term->row/2+y_offset, term->col/2-x_offset-2);
			printw(BISHOP_1);
			move(term->row/2+y_offset+1, term->col/2-x_offset-2);
			printw(WBISHOP_2);
			move(term->row/2+y_offset+2, term->col/2-x_offset-2);
			printw(WBISHOP_3);
			break;
	}

	//addch(piece);
}


void Engine::move_piece(const char* loc, const char* des_loc) {
	std::pair<int, int> offsets = get_piece_loc(loc);
	int x_offset = offsets.first;
	int y_offset = offsets.second;

	std::pair<int, int> des_offsets = get_piece_loc(des_loc);
	int dx_offset = des_offsets.first;
	int dy_offset = des_offsets.second;

	if (dx_offset == LOC_UNDEFINED || y_offset == LOC_UNDEFINED || x_offset == LOC_UNDEFINED || dy_offset == LOC_UNDEFINED) {
		move(term->row/2 + term->row/3 + 1, 0);
		printw("Invalid input. Please try again.");
		return;
	}
	else {
		move(term->row/2 + term->row/3 + 1, 0);
		clrtoeol();
	}

	move(term->row/2+y_offset, term->col/2-x_offset-4); /* go to the very beginning of the cell */
	/* not for the entire line, get the current char and move it to the specified location */
		
	for (int i = 0; i < 3; i++) {
		std::string res;
		for (int j = 0; j < 8; j++) {
			char ch = inch();
			res += ch;
			addch(' ');
			move(term->row/2+y_offset+i, term->col/2-x_offset-4+j);
		}
		move(term->row/2+dy_offset+i, term->col/2-dx_offset-4);
		printw(res.substr(1, res.length()).c_str());
	}
}

void Engine::print_pieces() {
	print_piece('p', "a2");
	print_piece('k', "b2");
	print_piece('b', "c2");
	print_piece('p', "d2");
	print_piece('k', "e2");
	print_piece('b', "f2");
	print_piece('p', "g2");
	print_piece('k', "h2");
	print_piece('b', "a1");
	print_piece('p', "b1");
	print_piece('k', "c1");
	print_piece('b', "d1");
	print_piece('p', "e1");
	print_piece('k', "f1");
	print_piece('b', "g1");
	print_piece('p', "h1");
}

Engine::~Engine() {
	delete_term(term);
}

