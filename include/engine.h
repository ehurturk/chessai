#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>
#include <string>

#include "../include/term.h"

#define BLACK -1
#define WHITE 1

#define BOARD_WIDTH 81
#define BOARD_HEIGHT 32

#define B_LINE "*---------*---------*---------*---------*---------*---------*---------*---------*"
#define P_LINE "|         |         |         |         |         |         |         |         |"

#define C_1 " .----------------.  .----------------.  .----------------.  .----------------.  .----------------. "
#define C_2 "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |"
#define C_3 "| |     ______   | || |  ____  ____  | || |  _________   | || |    _______   | || |    _______   | |"
#define C_4 "| |   .' ___  |  | || | |_   ||   _| | || | |_   ___  |  | || |   /  ___  |  | || |   /  ___  |  | |"
#define C_5 "| |  / .'   \\_|  | || |   | |__| |   | || |   | |_  \\_|  | || |  |  (__ \\_|  | || |  |  (__ \\_|  | |"
#define C_6 "| |  | |         | || |   |  __  |   | || |   |  _|  _   | || |   '.___`-.   | || |   '.___`-.   | |"
#define C_7 "| |  \\ `.___.'\\  | || |  _| |  | |_  | || |  _| |___/ |  | || |  |`\\____) |  | || |  |`\\____) |  | |"
#define C_8 "| |   `._____.'  | || | |____||____| | || | |_________|  | || |  |_______.'  | || |  |_______.'  | |"
#define C_9 "| |              | || |              | || |              | || |              | || |              | |"
#define C_10 "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |"
#define C_11 " '----------------'  '----------------'  '----------------'  '----------------'  '----------------' "

#define PAWN_1  " _ "
#define WPAWN_2 "( )"
#define WPAWN_3 "/ \\"

#define KNIGHT_1  " ,^. "
#define WKNIGHT_2 "(  '\\"
#define WKNIGHT_3 "|  \\ "

#define BISHOP_1  " o  "
#define WBISHOP_2 "( /)"
#define WBISHOP_3 "/  \\)"

#define GET_CX(x) 

#ifndef CTRL
#define CTRL(c) ((c) & 037)
#endif


struct Piece {
	int type;
	int point;
};

class Engine {
	public:

		Engine(const std::string& initial);
		~Engine();
		void start();
		void update();
	private:
		void print_board();	
		void print_pieces();
		void print_piece(const char piece, const char* place);
		void generate_moves();
		void move_piece(const char* loc, const char* des_loc);
	

		std::string board;
		struct Term* term;
};

#endif /* ENGINE_H_ */
