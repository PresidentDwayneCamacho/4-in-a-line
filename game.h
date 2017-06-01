#ifndef GAME_H_
#define GAME_H_
#include "constants.h"
struct Node;


// keeps track of score for rows and columns
// 
struct ScoreTracker {
	int row_[constants::DIMENSION];
	int col_[constants::DIMENSION];
};


class Game {

	//	not all of the min-max functions should be used
	//		they are simply present to explore different options
	//			calculate_min_max is one such option, though insufficient
	//			min_max_vector is another option, and it seems better
	//		we should try others
	//			one example, put game board configuration in hierarchy where 
	//			number of 3 in a row lines is higher priority, followed by 2 in a row
	//


public:
	Game();
	~Game();

	int update_min_max_row(Node* node, int row, char player, char opponent);
	int update_min_max_col(Node* node, int col, char player, char opponent);

	void place_symbol_from_prompt(Node* node, char symbol, int row, int col);


private:
	ScoreTracker tracker_;


};


#endif

