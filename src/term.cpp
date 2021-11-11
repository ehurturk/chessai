#include "../include/term.h"

struct Term* create_term() { 
	struct Term* term = new struct Term();
	term->win = stdscr;
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	int row, col;
	getmaxyx(stdscr, row, col);
	term->row = row;
	term->col = col;
	
	return term;
}

void delete_term(const struct Term* term) {
	curs_set(1);
	endwin();
	delete term;
}
