#include "game.h"
#include "node.h"
#include "constants.h"
#include <iostream>


namespace {

	const int RIGHT = 1;
	const int LEFT = -1;
	const int UP = -constants::DIMENSION;
	const int DOWN = constants::DIMENSION;

	

}



Game::Game() {
	for (int i = 0; i < constants::DIMENSION; ++i)
		tracker_.row_[i] = tracker_.col_[i] = 0;
}



Game::~Game() {

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



// TODO perhaps ensure that this does not go out of bounds
void Game::place_symbol_from_prompt(Node* node, char symbol, int row, int col) {
	node->config_[(row - 1)*constants::DIMENSION + (col - 1)] = symbol;
}


// works
void Game::print_node(Node* node) {
	std::cout << "  ";
	for (int i = 0; i < constants::DIMENSION; ++i)
		std::cout << i + 1 << " ";
	for (int i = 0; i < constants::SIZE; ++i) {
		if (i % constants::DIMENSION == 0)
			std::cout << "\n" <<
			static_cast<char>('A' + i / constants::DIMENSION) << " ";
		std::cout << node->config_[i] << " ";
	}
	std::cout << "\n" << std::endl;
}










/*

void Game::count_adjacent_symbols(Node* node) {
	for (int i = 0; i < constants::SIZE; ++i) {
		node->config_[i].player_ = node->config_[i].opponent_ = 0;
		if (this->can_check_up(i)) {
			this->query_adjacent_element(node, i, UP);
		}
		if (this->can_check_down(i)) {
			this->query_adjacent_element(node, i, DOWN);
		}
		if (this->can_check_right(i)) {
			this->query_adjacent_element(node, i, RIGHT);
		}
		if (this->can_check_left(i)) {
			this->query_adjacent_element(node, i, LEFT);
		}
	}
}


void Game::query_adjacent_element(Node* node, int index, int offset) {
	char symbol = node->config_[index].symbol_;
	char adjacent = node->config_[index + offset].symbol_;
	if (symbol == SYMBOL::PLAYER)
		if (adjacent == SYMBOL::PLAYER)
			++node->config_[index].player_;
		else if (adjacent == SYMBOL::OPPONENT)
			++node->config_[index].opponent_;
	else if (symbol == SYMBOL::OPPONENT)
		if (adjacent == SYMBOL::OPPONENT)
			++node->config_[index].player_;
		else if (adjacent == SYMBOL::PLAYER)
			++node->config_[index].opponent_;
}



// a heuristic function which calculates the number of similar adjacent symbols
// two o's next to each other means a point for the player
// two x's next to each other means a point for the opponent
void Game::calculate_min_max(Node* node) {
	node->max_ = node->min_ = 0;
	for (int i = 0; i < constants::SIZE; ++i) {
		if (this->can_check_right(i))
			this->query_adjacent_min_max(node, i, RIGHT);
		if (this->can_check_down(i))
			this->query_adjacent_min_max(node, i, DOWN);
	}
}


inline bool Game::can_check_right(int i) {
	return i % constants::DIMENSION != constants::DIMENSION - 1;
}


inline bool Game::can_check_down(int i) {
	return i / constants::DIMENSION != constants::DIMENSION - 1;
}


inline bool Game::can_check_up(int i) {
	return i / constants::DIMENSION != 0;
}


inline bool Game::can_check_left(int i) {
	return i % constants::DIMENSION != 0;
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




// this could be revised to hold the current move
// and simply update the heuristic upon next move
// concern is that if it changes the total row,
// you'd have to have a record of where the points came from
// if you have to iterate though to determine this, 
// then you may end up saving little time
// but we should test it to be certain












/*

void Game::min_max_open_fours(Node* node) {

	int iter = 0;
	node->max_ = node->min_ = 0;
	
	for (int i = 0; i < constants::SIZE; ++i) {

		// move right
		std::cout << "Move right: ";
		for (int j = 1; j < constants::WIN_SIZE; ++j) {

			if ((i+j)%constants::DIMENSION == 0) {
				break;
			}
			else {
				std::cout << " " << i + j << " ";
			}

		}
		std::cout << std::endl;


		// move left
		std::cout << "Move left:  ";
		for (int j = -1; j > -constants::WIN_SIZE; --j) {
			
			if ((i + j) % constants::DIMENSION == constants::DIMENSION-1) {
				break;
			}
			else {
				std::cout << " " << i + j << " ";
			}


		}
		std::cout << std::endl;

		// move up
		std::cout << "Move up:    ";
		for (int j = -constants::DIMENSION; j > -constants::WIN_SIZE*constants::DIMENSION; j -= constants::DIMENSION) {
			
			if ((i + j) / constants::DIMENSION == 0) {
				break;
			}
			else {
				std::cout << " " << i + j << " ";
			}

		}
		std::cout << std::endl;

		// move down
		std::cout << "Move down:  ";
		for (int j = constants::DIMENSION; j < constants::WIN_SIZE*constants::DIMENSION; j += constants::DIMENSION) {
			
			if ((i + j) / constants::DIMENSION == constants::DIMENSION - 1) {
				break;
			}
			else {
				std::cout << " " << i + j << " ";
			}

		}
		std::cout << std::endl;

	}

	std::cout << std::endl;

}



bool Game::check_four_adjacent(Node* node, int begin, int bound, int offset) {

	int iterations = 0;
	char symbol = node->config_[begin].symbol_;
	for (int i = begin + offset; i != bound; i += offset) {
		if (symbol == node->config_[i].symbol_)
			++iterations;
	}
	return iterations >= constants::WIN_SIZE - 1;

}





bool Game::four_open_right(Node* node, char symbol, int index, int offset) {

	int i = index + offset;
	for (int j = 0; j < constants::WIN_SIZE; ++j) {
		if (!this->can_check_right(i) || symbol != node->config_[i].symbol_) {
			return false;
		}
		i += offset;
	}
	return true;


	//for (int i = index+1; i < constants::WIN_SIZE+index; ++i) {
	//	if (!this->can_check_right(i) || symbol != node->config_[i].symbol_) {
	//		return false;
	//	}
	//}
	//return true;
}





void Game::min_max_open_fours(Node* node) {

	node->max_ = node->min_ = 0;
	for (int i = 0; i < constants::SIZE; ++i) {
		int score = 0;
		char symbol = node->config_[i].symbol_;
		if (symbol == SYMBOL::PLAYER) {
			if (this->four_open_spaces(node, symbol, i, RIGHT)) {
				++score;
			}
			if (this->four_open_spaces(node, symbol, i, LEFT)) {
				++score;
			}
			if (this->four_open_spaces(node, symbol, i, UP)) {
				++score;
			}
			if (this->four_open_spaces(node, symbol, i, DOWN)) {
				++score;
			}
			node->max_ += score;
		}
		else if (symbol == SYMBOL::OPPONENT) {
			if (this->four_open_spaces(node, symbol, i, RIGHT)) {
				++score;
			}
			if (this->four_open_spaces(node, symbol, i, LEFT)) {
				++score;
			}
			if (this->four_open_spaces(node, symbol, i, UP)) {
				++score;
			}
			if (this->four_open_spaces(node, symbol, i, DOWN)) {
				++score;
			}
			node->min_ += score;
		}
	}

}



bool Game::four_open_spaces(Node* node, char symbol, int index, int offset) {
	for (int i = 1; i < constants::WIN_SIZE; ++i) {
		int p = index + i*offset;
		
	}
	return true;
}



//int Game::count_four_adjecent_symbol(Node* node, char symbol, int index) {
//	int score = 0;
//	if (this->four_open_spaces(node, symbol, index, RIGHT)) {
//		++score;
//	}
//}

*/

