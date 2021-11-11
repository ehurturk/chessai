/* engine.cpp */

#include "../include/engine.h"
#include <ncurses.h>

Engine::Engine(const std::string& initial): board(initial) { }

void Engine::start() {
	term = create_term();
	print_board();
	printw("\n\n");
	/* game loop */
	while (true) {
		printw("\r");
		echo();
		clrtoeol();
 		printw("Enter the piece you want to play and where to play (e.g. p-e6 or P-e6): ");
		std::string input;
		int ch;
		while ((ch=getch()) != '\n') {
			input.push_back(ch);
		}
		noecho();
		curs_set(0);
		char c = getch();
		if (c == 'q') {
			break;
		}
 		refresh();
	}
}

void Engine::generate_moves() {
		
}

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

	for (int i = 0; i <	33; i++) {
			std::string line = i % 4 == 0 ? B_LINE : P_LINE; 
			int row, col;
			row = term->row/2+i-15;
			col = (term->col-(9+9*8))/2;
			if (i % 4 == 2) {
				line = std::to_string((34-i)/4).append(" ").append(line);
				col -= 2;
			}
			mvprintw(row, col, line.c_str());
	}
	mvprintw(term->row/2+32-14, term->col /2 -40, "     a         b         c         d         e         f         g         h     ");
}

Engine::~Engine() {
	delete_term(term);
}

