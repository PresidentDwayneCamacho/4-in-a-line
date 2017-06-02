// "Four in a Line"
// by Trey Amador and Scott Matsumura
// CPP CS420 Artificial Intelligence
// Due: Monday June 5, 2017

#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <queue>
#include <functional>
#include "constant.h"
struct Node;


// keeps track of score for rows and columns
// 

struct Coordinate {
	char symbol_;
	int row_;
	int col_;
};


struct ScoreCounter {
	int row_[constant::LENGTH];
	int col_[constant::LENGTH];
};


class Game {

public:
	Game();
	~Game();

	void make_first_move(Node* node);

	// TODO remove these test functions
	void test_fill_score_tracker(Node* node);
	void test_node_querying();
	Node* test_node_01();
	// test functions


	Node* query_next_move(Node* root);
	void query_adjacent(Node* node);
	void query_up(Node* node, Coordinate& coord, int offset, bool& open);
	void query_down(Node* node, Coordinate& coord, int offset, bool& open);
	void query_right(Node* node, Coordinate& coord, int offset, bool& open);
	void query_left(Node* node, Coordinate& coord, int offset, bool& open);


	int update_min_max_row(Node* node, int row, char player, char opponent);
	int update_min_max_col(Node* node, int col, char player, char opponent);
	int sum_score_tracker();

	void place_symbol_by_indeces(Node* node, char symbol, int row, int col);
	void place_symbol_from_prompt(Node* node, char symbol, int row, int col);


    void print_node(void (*func)(char*));
    void print_player_X(void (*func)(int*));
    void print_player_O(void (*func)(int*));

private:
    typedef Node* GameBoard;
    GameBoard board;
	std::queue<Coordinate> adjacent_spaces_;


	// TODO perhaps have a player and opponent tracker ..?
	ScoreCounter score_counter_;


};

#endif //GAME_H_

