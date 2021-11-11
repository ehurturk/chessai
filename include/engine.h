#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>
#include <string>

#include "../include/term.h"

#define BLACK -1
#define WHITE 1

#define B_LINE "*---------*---------*---------*---------*---------*---------*---------*---------*"
#define P_LINE "|         |         |         |         |         |         |         |         |"

struct Piece {
	int type;
	int point;
};

class Engine {
	public:

		Engine(const std::string& initial);
		~Engine();
		void start();
		
	private:
		void print_board();	
		void generate_moves();
	

		std::string board;
		struct Term* term;
};

#endif /* ENGINE_H_ */
