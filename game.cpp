#include "game.h"
#include "node.h"
#include <iostream>


namespace {
	const int RIGHT_ELEM = 1;
	const int LEFT_ELEM = -1;
	const int UP_ELEM = -DIMENSION;
	const int DOWN_ELEM = DIMENSION;

}



Game::Game() {

}



Game::~Game() {

}


void Game::count_adjacent_symbols(Node* node) {

	for (int i = 0; i < SIZE; ++i) {
		if (this->can_check_up(i)) {

		}
		if (this->can_check_down(i)) {

		}
		if (this->can_check_right(i)) {

		}
		if (this->can_check_left(i)) {

		}


	}
}


void Game::query_adjacent_element(Node* node, int index, int offset) {

}



// a heuristic function which calculates the number of similar adjacent symbols
// two o's next to each other means a point for the player
// two x's next to each other means a point for the opponent
void Game::calculate_min_max(Node* node) {
	node->max_ = node->min_ = 0;
	for (int i = 0; i < SIZE; ++i) {
		if (this->can_check_right(i))
			this->query_adjacent_min_max(node, i, RIGHT_ELEM);
		if (this->can_check_down(i))
			this->query_adjacent_min_max(node, i, DOWN_ELEM);
	}
}


inline bool Game::can_check_right(int i) {
	return i % DIMENSION != DIMENSION - 1;
}


inline bool Game::can_check_down(int i) {
	return i / DIMENSION != DIMENSION - 1;
}


inline bool Game::can_check_up(int i) {
	return i / DIMENSION != 0;
}


inline bool Game::can_check_left(int i) {
	return i % DIMENSION != 0;
}



// can probably be combined with the method that checks all 4 adjacent symbols
void Game::query_adjacent_min_max(Node* node, int index, int offset) {
	char symbol = node->config_[index].symbol_;
	if (symbol == node->config_[index + offset].symbol_) {
		if (symbol == SYMBOL::PLAYER) {
			++node->max_;
		}
		else if (symbol == SYMBOL::OPPONENT) {
			++node->min_;
		}
	}
}


