/* engine.cpp */

#include "../include/engine.h"
#include <cstddef>
#include <ncurses.h>

Engine::Engine(const std::string& initial): board(initial) { }

/* init */
void Engine::start() {
	term = create_term();
	print_board();
	print_pieces();
	move(term->row/2 + term->row/3, term->col/2 + term->col/3);
	/* game loop */
	update();
}

/* game loop*/
void Engine::update() {
	while (true) {
		printw("\r");
		echo();
		clrtoeol();
		curs_set(1);
 		printw("Enter the piece you want to play and where to play (e.g. p-e6 or P-e6): ");
		std::string input;
		int ch;
		while ((ch=getch()) != '\n') {
			input.push_back(ch);
		}
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

void Engine::print_piece(const char piece, const char* place) {
	if (place == NULL) {
		return;
	}

	char loc1 = place[0]; /* a */
	char loc2 = place[1]; /* 3 */

	int x_offset, y_offset;

	x_offset = 35-10*(loc1-0x61);
	y_offset = (3-(loc2-0x31))*4;
	y_offset = y_offset > 0 ? y_offset + 2 : y_offset - 2;

	move(term->row/2+y_offset+1, term->col/2-x_offset);
	addch(piece);
}

void Engine::print_pieces() {
	print_piece('p', "a2");
	print_piece('p', "b2");
	print_piece('p', "c2");
	print_piece('p', "d2");
	print_piece('p', "e2");
	print_piece('p', "f2");
	print_piece('p', "g2");
	print_piece('p', "h2");
	print_piece('p', "a1");
	print_piece('p', "b1");
	print_piece('p', "c1");
	print_piece('p', "d1");
	print_piece('p', "e1");
	print_piece('p', "f1");
	print_piece('p', "g1");
	print_piece('p', "h1");
}

Engine::~Engine() {
	delete_term(term);
}

