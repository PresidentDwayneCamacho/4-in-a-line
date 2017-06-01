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
	void print_node(Node* node);


	void calculate_min_max(Node* node);
	void count_adjacent_symbols(Node* node);





	// fxn which counts adjacent by row, then by column
	//void min_max_open_fours(Node* node);

	//bool check_four_adjacent(Node* node, int begin, int bound, int offset);

	//bool four_open_right(Node* node, char symbol, int index, int offset);
	//bool four_open_left(Node* node, int index);
	//bool four_open_up(Node* node, int index);
	//bool four_open_down(Node* node, int index);

	//bool four_open_spaces(Node* node, char symbol, int index, int offset);
	//int count_four_adjecent_symbol(Node* node, char symbol, int index);


private:
	ScoreTracker tracker_;


	inline bool can_check_right(int i);
	inline bool can_check_down(int i);
	inline bool can_check_left(int i);
	inline bool can_check_up(int i);

	void query_adjacent_element(Node* node, int index, int offset);
	void query_adjacent_min_max(Node* node, int index, int offset);
	

private:



};


#endif

