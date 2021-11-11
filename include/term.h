#ifndef TERM_H_
#define TERM_H_

#include <ncurses.h>

struct Term {
	int row, col;
	WINDOW* win;

};


struct Term* create_term();
void delete_term(const struct Term* term);

#endif
