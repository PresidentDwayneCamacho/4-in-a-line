#include "core.h"
#include "test.h"
#include "node.h"
#include "game.h"
#include "io.h"


Core::Core() {

}


Core::~Core() {

}


// return negative value upon program failure
// return 0 upon program success
// note this is not relevant to whether you win the game or not
int Core::run() {

	Game game;
	IO io;


	//Node* node = test::init_rand_empty_node(3, 3);
	//game.min_max_open_fours(node);


	Node* node = test_node_01();

	game.print_node(node);

	for (int r = 0; r < constants::DIMENSION; ++r) {
		test_row_heuristic_02(r);
	}

	for (int c = 0; c < constants::DIMENSION; ++c) {
		test_col_heuristic_01(c);
	}




	/*

	io.welcome();
	//io.print_game_config(node);
	std::cout << "\n\n";
	//game.calculate_min_max(node);
	//std::cout << "max: " << node->max_ << std::endl;
	//std::cout << "min: " << node->min_ << std::endl;
	game.count_adjacent_symbols(node);
	test::print_node_score(node);

	*/



	return 0;
}






/*

Core::Core() {

}


Core::~Core() {

}


int Core::run() {

	Node* node = this->init_empty_node();
	this->place_symbol(node, SYMBOL::PLAYER, SYMBOL::OPPONENT, 3, 3);
	this->print_config(node);
	std::cout << node->config_[3][3].right_ << std::endl;
	std::cout << node->config_[3][3].left_ << std::endl;
	std::cout << node->config_[3][3].up_ << std::endl;
	std::cout << node->config_[3][3].down_ << std::endl;


	// this->min_max_heuristic(node);

	this->print_config(node);

	//this->print_config(node);
	//this->place_symbol(node, SYMBOL::PLAYER, 2, 5);
	//this->print_config(node);




	delete node;

	return 0;
}



void Core::place_symbol(Node* node, char symbol, char oppose_symbol, int r, int c) {

	node->config_[c][r].symbol_ = symbol;

	// right
	bool uninterrupted = true;
	node->config_[c][r].right_ = true;
	int count = 0;
	for (int i = c + 1; i < c + constants::WIN && uninterrupted; ++i) {
		if (i >= constants::DIMENSION || node->config_[i][r].symbol_ == oppose_symbol) {
			node->config_[c][r].right_ = uninterrupted = false;
		}
		++count;
	}

	// left
	uninterrupted = true;
	node->config_[c][r].left_ = true;
	count = 0;
	for (int i = c - 1; i > c - constants::WIN && uninterrupted; --i) {
		if (i < 0 || node->config_[i][r].symbol_ == oppose_symbol) {
			node->config_[c][r].left_ = uninterrupted = false;
		}
		++count;
	}

	std::cout << "left count " << count << std::endl;

	// up
	node->config_[c][r].up_ = true;


	// down
	node->config_[c][r].down_ = true;

}



void Core::update_heuristic(Node* node, int row, int col) {

	char symbol = node->config_[row][col].symbol_;

	// move right
	int win = constants::WIN;
	int dim = constants::DIMENSION;
	for (int i = row + 1; i < row + win && i < dim; ++i) {
		if (i > dim) {
			// off board, update heuristic
			break;
		}
		char compare = node->config_[i][col].symbol_;
		if (compare != SYMBOL::EMPTY && symbol != compare) {
			node->config_[row][col].left_ = 0;
		}
	}


	// move left
	for (int i = row - 1; i >= row - win && i > 0; --i) {
		if (symbol == SYMBOL::OPPONENT && symbol != node->config_[i][col].symbol_) {

		}
	}


	// move up



	// move down



}


// not good anymore
void Core::init_heuristic(Node* node) {

	node->config_[3][3].symbol_ = SYMBOL::PLAYER;
	node->config_[3][3].up_ = true;
	node->config_[3][3].down_ = true;
	node->config_[3][3].left_ = true;
	node->config_[3][3].right_ = true;

}


void Core::min_max_heuristic(Node* node) {

	for (int r = 0; r < constants::DIMENSION; ++r) {
		for (int c = 0; c < constants::DIMENSION; ++c) {
			char symbol = node->config_[c][r].symbol_;
			if (symbol != SYMBOL::EMPTY) {

			}

			// query right
			for (int i = 1; i < constants::WIN; ++i) {

			}
		}
	}
}





void Core::min_max_heuristic(Node* node) {

	char symb_iter = '.';
	for (int r = 0; r < constants::DIMENSION; ++r) {
		int plyr = 0, oppn = 0, empt = 0;
		int player_score = 0, opponent_score = 0;
		for (int c = 0; c < constants::DIMENSION; ++c) {
			char symbol = node->config_[c][r].symbol_;
			if (symbol == SYMBOL::PLAYER) {
				player_score += (plyr + empt);
				oppn = empt = 0;
			}
			else if (symbol == SYMBOL::OPPONENT) {
				opponent_score += (oppn + empt);
				plyr = empt = 0;
			}
			else {
				if (empt < 3) {
					++empt;
				}
			}
		}
	}

	for (int c = 0; c < constants::DIMENSION; ++c) {
		for (int r = 0; r < constants::DIMENSION; ++r) {
			std::cout << node->config_[c][r].symbol_ << " ";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}





Node* Core::init_empty_node() {
	Node* node = new Node;
	node->config_ = new Element*[constants::DIMENSION];
	for (int r = 0; r < constants::DIMENSION; ++r)
		node->config_[r] = new Element[constants::DIMENSION];
	for (int r = 0; r < constants::DIMENSION; ++r)
		for (int c = 0; c < constants::DIMENSION; ++c)
			node->config_[r][c].symbol_ = SYMBOL::EMPTY;
	return node;
}


Node* Core::init_rand_empty_node(int x_place, int o_place) {
	Node* node = new Node;
	node->config_ = new Element*[constants::DIMENSION];
	for (int i = 0; i < constants::DIMENSION; ++i)
		node->config_[i] = new Element[constants::SIZE];
	for (int r = 0; r < constants::DIMENSION; ++r)
		for (int c = 0; c < constants::DIMENSION; ++c)
			if (std::rand() % x_place == 0)
				node->config_[c][r].symbol_ = SYMBOL::PLAYER;
			else if (std::rand() % o_place == 0)
				node->config_[c][r].symbol_ = SYMBOL::OPPONENT;
			else
				node->config_[c][r].symbol_ = SYMBOL::EMPTY;
	return node;
}


void Core::print_config(Node* node) {
	std::cout << "  ";
	for (int i = 0; i < constants::DIMENSION; ++i)
		std::cout << i << " ";
	std::cout << std::endl;
	for (int r = 0; r < constants::DIMENSION; ++r) {
		std::cout << static_cast<char>(r + 'A') << " ";
		for (int c = 0; c < constants::DIMENSION; ++c)
			std::cout << node->config_[c][r].symbol_ << " ";
		std::cout << "\n";
	}
	std::cout << std::endl;
}



//inline void Core::place_symbol(Node* node, char symbol, int r, int c) {
//	node->config_[c][r].symbol_ = symbol;
//}

*/


