/* engine.cpp */

#include "../include/engine.h"
#include <ncurses.h>

Engine::Engine(const std::string& initial): board(initial) { }

void Engine::start() {
	term = create_term();
	print_board();
	char ch;

	while ((ch = getch()) != 'q')
 		refresh();
 		
	endwin();
}

void Engine::generate_moves() {
		
}

void Engine::print_board() {
	for (int i = 0; i <	33; i++) { 
			if (i % 4 == 0)
				mvprintw(term->row/2+i-15, (term->col-(9+9*8))/2, B_LINE);
			else
				mvprintw(term->row/2+i-15, (term->col-(9+9*8))/2, P_LINE);
	}
}

Engine::~Engine() {
	delete_term(term);
}

