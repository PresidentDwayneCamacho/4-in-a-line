#include "game.h"
#include "node.h"
#include "io.h"
#include "constants.h"
#include <iostream>

typedef Node* GameBoard;


enum MOVE {
	UP = -constants::DIMENSION,
	DOWN = constants::DIMENSION,
	RIGHT = 1,
	LEFT = -1
};


Game::Game() {
	for (int i = 0; i < constants::DIMENSION; ++i)
		score_counter_.row_[i] = score_counter_.col_[i] = 0;
}


Game::~Game() {
	
}



// call this method after response from other player
// TODO fill this method, which will try all the adjacent
//		moves from a selection of moves
Node* Game::query_next_move(Node* root) {
	
	this->query_adjacent(root);

	//while (!adjacent_spaces_.empty()) {

	//}


	return nullptr;
}


// check left, right, up, down for next best move
void Game::query_adjacent(Node* node) {
	Coordinate coord = adjacent_spaces_.front();
	bool up = true, down = true, left = true, right = true;
	for (int i = 1; i <= 3; ++i) {
		this->query_right(node, coord, i, right);
		this->query_left(node, coord, i*(-1), left);
		this->query_up(node, coord, i*(-1), up);
		this->query_down(node, coord, i, down);
	}
}




// are these less efficient than just checking?
void Game::query_right(Node* node, Coordinate& coord, int offset, bool& open) {
	int index = coord.row_*constants::DIMENSION+coord.col_+offset;
	if (index % constants::DIMENSION == 0)
		open = false;
	else if (open && node->config_[index] == SYMBOL::EMPTY)
		adjacent_spaces_.push({ SYMBOL::EMPTY, coord.row_, coord.col_+offset });
}


void Game::query_left(Node* node, Coordinate& coord, int offset, bool& open) {
	int index = coord.row_*constants::DIMENSION + coord.col_ + offset;
	if (index % constants::DIMENSION == constants::DIMENSION-1)
		open = false;
	else if (open && node->config_[index] == SYMBOL::EMPTY)
		adjacent_spaces_.push({ SYMBOL::EMPTY, coord.row_, coord.col_+offset });
}


void Game::query_up(Node* node, Coordinate& coord, int offset, bool& open) {
	int index = (coord.row_ + offset)*constants::DIMENSION + coord.col_;
	if (index / constants::DIMENSION == -1)
		open = false;
	else if (open && node->config_[index] == SYMBOL::EMPTY)
		adjacent_spaces_.push({ SYMBOL::EMPTY, coord.row_ + offset, coord.col_ });
}


void Game::query_down(Node* node, Coordinate& coord, int offset, bool& open) {
	int index = (coord.row_+offset)*constants::DIMENSION + coord.col_;
	if (index / constants::DIMENSION == constants::DIMENSION)
		open = false;
	else if (open && node->config_[index] == SYMBOL::EMPTY)
		adjacent_spaces_.push({ SYMBOL::EMPTY, coord.row_ + offset, coord.col_ });
}



int Game::sum_score_tracker() {
	int sum = 0;
	for (int i = 0; i < constants::DIMENSION; ++i)
		sum += score_counter_.row_[i] + score_counter_.col_[i];
	return sum;
}


// function returns the score which will be put into row of ScoreTracker
int Game::update_min_max_row(Node* node, int row, char player, char opponent) {
	int row_score = 0;
	int r = row*constants::DIMENSION;
	for (int c = 0; c <= constants::WIN; ++c) {
		int uninterrupted = 0;
		for (int i = 0; i < constants::WIN && uninterrupted != -1; ++i) {
			char symbol = node->config_[r + c + i];
			if (symbol == player)
				++uninterrupted;
			else if (symbol == opponent)
				uninterrupted = -1;
		}
		row_score += (uninterrupted != -1 ? uninterrupted : 0);
	}
	return row_score;
}


int Game::update_min_max_col(Node* node, int col, char player, char opponent) {
	int c = col;
	int column_score = 0;
	for (int r = 0; r <= constants::WIN; ++r) {
		int uninterrupted = 0;
		for (int i = 0; i < constants::WIN && uninterrupted != -1; ++i) {
			char symbol = node->config_[c + constants::DIMENSION*(r + i)];
			if (symbol == player)
				++uninterrupted;
			else if (symbol == opponent)
				uninterrupted = -1;
		}
		column_score += (uninterrupted != -1 ? uninterrupted : 0);
	}
	return column_score;
}



// TODO optimize this based on what leads to victory!
void Game::make_first_move(Node* node) {
	int row = 3, col = 3;
	this->place_symbol_by_indeces(node, SYMBOL::PLAYER, row, col);
	adjacent_spaces_.push({ SYMBOL::PLAYER, row, col });
}


// should be used when placing symbols using the row and col numbers
// that are indeces in the array
void Game::place_symbol_by_indeces(Node* node, char symbol, int row, int col) {
	node->config_[row*constants::DIMENSION+col] = symbol;
	adjacent_spaces_.push({ symbol, row, col });
}


// does this really need to be included..?
void Game::place_symbol_from_prompt(Node* node, char symbol, int row, int col) {
	node->config_[(row-1)*constants::DIMENSION+(col-1)] = symbol;
}







// TESTING FUNCTIONS

void Game::test_fill_score_tracker(Node* node) {

	for (int i = 0; i < constants::DIMENSION; ++i) {
		score_counter_.row_[i] = this->update_min_max_row(node, i, SYMBOL::PLAYER, SYMBOL::OPPONENT);
		score_counter_.col_[i] = this->update_min_max_col(node, i, SYMBOL::PLAYER, SYMBOL::OPPONENT);
	}

	std::cout << "  ";
	for (int i = 0; i < constants::DIMENSION; ++i)
		std::cout << score_counter_.col_[i] << " ";
	std::cout << "\n";
	for (int i = 0; i < constants::DIMENSION; ++i)
		std::cout << score_counter_.row_[i] << "\n";

}




Node* Game::test_node_01() {

	IO io;

	Node* node = new Node;

	GameBoard board = node;


	std::cout << "game board node" << std::endl;
	io.print_node(static_cast<Node*>(board));


	node->config_[3] = SYMBOL::PLAYER;
	node->config_[11] = SYMBOL::PLAYER;
	node->config_[19] = SYMBOL::PLAYER;
	node->config_[12] = SYMBOL::PLAYER;
	node->config_[13] = SYMBOL::PLAYER;
	node->config_[54] = SYMBOL::PLAYER;
	node->config_[56] = SYMBOL::PLAYER;
	node->config_[60] = SYMBOL::PLAYER;

	node->config_[4] = SYMBOL::OPPONENT;
	node->config_[5] = SYMBOL::OPPONENT;
	node->config_[13] = SYMBOL::OPPONENT;
	node->config_[42] = SYMBOL::OPPONENT;
	node->config_[43] = SYMBOL::OPPONENT;
	node->config_[44] = SYMBOL::OPPONENT;
	node->config_[51] = SYMBOL::OPPONENT;

	return node;

}


void Game::test_node_querying() {

	IO io;

	Node* node = this->test_node_01();
	io.print_node(node);
	this->test_fill_score_tracker(node);


	delete node;

}


