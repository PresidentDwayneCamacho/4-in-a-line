#ifndef TEST_H_
#define TEST_H_
#include "core.h"
#include "node.h"
#include "game.h"
#include "constants.h"
#include <iostream>


Node* test_node_01();

void test_row_heuristic_01();
void test_row_heuristic_02(int row);
void test_row_heuristic_03(int row);

void test_col_heuristic_01(int col);
void test_col_heuristic_02(int col);


void test_row_heuristic_01() {

	Game game;
	Node* node = test_node_01();
	game.print_node(node);
	int row = 2;
	int row_score = game.update_min_max_row(node, row, SYMBOL::PLAYER, SYMBOL::OPPONENT);
	std::cout << "row " << row << ", heuristic row score: " << row_score << "\n" << std::endl;
	delete node;

}



void test_row_heuristic_02(int row) {

	Game game;
	Node* node = test_node_01();
	game.print_node(node);
	int row_score = game.update_min_max_row(node, row, SYMBOL::PLAYER, SYMBOL::OPPONENT);
	std::cout << "row " << row << ", heuristic row score: " << row_score << "\n" << std::endl;
	delete node;

}



void test_row_heuristic_03(int row) {

	Game game;
	Node* node = test_node_01();
	game.print_node(node);
	int row_score = game.update_min_max_row(node, row, SYMBOL::OPPONENT, SYMBOL::PLAYER);
	std::cout << "row " << row << ", heuristic row score: " << row_score << "\n" << std::endl;
	delete node;

}



void test_col_heuristic_01(int col) {

	Game game;
	Node* node = test_node_01();
	game.print_node(node);
	int col_score = game.update_min_max_col(node, col, SYMBOL::PLAYER, SYMBOL::OPPONENT);
	std::cout << "col " << col << ", heuristic col score: " << col_score << "\n" << std::endl;
	delete node;

}


void test_col_heuristic_02(int col) {

	Game game;
	Node* node = test_node_01();
	game.print_node(node);
	int col_score = game.update_min_max_col(node, col, SYMBOL::OPPONENT, SYMBOL::PLAYER);
	std::cout << "col " << col << ", heuristic col score: " << col_score << "\n" << std::endl;
	delete node;

}




Node* test_node_01() {

	Node* node = new Node;
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






// the test namespace is used for running unit tests
// important so you don't have to snoop around project code











/*


namespace test {


	void fill_element();
	void fill_node();

	void iterate_nodes();

	Element* init_elements(char token, int player, int opponent);
	Node* init_node(Element* config, Node* parent, int max, int min);

	Node* init_rand_empty_node(int x_place, int o_place);

	void print_elem(Element& element);
	void print_node(Node* node);

	void print_node_score(Node* node);


	// SUCCESS
	void fill_element() {

		Element a = { SYMBOL::EMPTY, 2, 3 };
		Element b = { SYMBOL::PLAYER, 1, 1 };
		Element c = { SYMBOL::OPPONENT, 0, 2 };

		print_elem(a);
		print_elem(b);
		print_elem(c);

	}


	// SUCCESS
	// tests how to create a new node for the game tree
	void fill_node() {

		Node* node_a = init_node(init_elements(SYMBOL::EMPTY, 1, 1), nullptr, 100, 10);
		Node* node_b = init_node(init_elements(SYMBOL::PLAYER, 2, 0), node_a, 30, 12);
		Node* node_c = init_node(init_elements(SYMBOL::OPPONENT, 1, 0), node_a, 54, 9);

		print_node(node_a);
		print_node(node_b);
		print_node(node_c);

		delete node_a;
		delete node_b;
		delete node_c;

	}


	// SUCCESS
	// tests if iterating through parent pointers works successfully
	void iterate_nodes() {

		Node* node_a = init_node(init_elements(SYMBOL::EMPTY, 1, 1), nullptr, 100, 10);
		Node* node_b = init_node(init_elements(SYMBOL::PLAYER, 2, 0), node_a, 30, 12);
		Node* node_c = init_node(init_elements(SYMBOL::OPPONENT, 1, 0), node_b, 54, 9);

		Node* node = node_c;
		while (node != nullptr) {
			print_node(node);
			node = node->parent_;
		}

		delete node_a;
		delete node_b;
		delete node_c;

	}


	Element* init_elements(char token, int player, int opponent) {
		Element* elem = new Element[constants::SIZE];
		for (int i = 0; i < constants::SIZE; ++i) {
			elem[i] = { token, player, opponent };
		}
		return elem;
	}


	// inits each value in the node with arguments passed in
	// this is just for testing purposes
	Node* init_node(Element* config, Node* parent, int max, int min) {
		Node* node = new Node;
		node->config_ = config;
		node->max_ = max;
		node->min_ = min;
		node->parent_ = parent;
		return node;
	}


	// this can be used for testing heuristic function
	// 
	Node* init_rand_empty_node(int x_place, int o_place) {
		Node* node = new Node;
		node->config_ = new Element[constants::SIZE];
		for (int i = 0; i < constants::SIZE; ++i) {
			char c;
			if (std::rand() % x_place == 0)
				c = SYMBOL::OPPONENT;
			else if (std::rand() % o_place == 1)
				c = SYMBOL::PLAYER;
			else
				c = SYMBOL::EMPTY;
			node->config_[i] = { c, 0, 0 };
		}
		return node;
	}


	void print_elem(Element& element) {
		std::cout << "Test print element:" << "\n";
		std::cout <<
			"Element: " << element.symbol_ << "\n" <<
			"Player: " << element.player_ << "\n" <<
			"Opponent: " << element.opponent_ << "\n" << std::endl;
	}



	void print_node(Node* node) {
		std::cout << "Test print node:" << "\n\n";
		for (int i = 0; i < constants::SIZE; ++i) {
			std::cout << "Element NO. " << i << ".\n";
			print_elem(node->config_[i]);
			std::cout << "Max: " << node->max_ << "\n";
			std::cout << "Min: " << node->min_ << "\n";
			std::cout << "\n" << std::endl;
		}
		std::cout << "\n\n" << std::endl;
	}


	void print_node_score(Node* node) {
		std::cout << "Printing scores per node:" << "\n";
		for (int i = 0; i < constants::SIZE; ++i) {
			if (i % constants::DIMENSION == 0) {
				std::cout << "\n";
			}
			std::cout <<
				"(" << i / constants::DIMENSION << "x" << i%constants::DIMENSION << ") = " <<
				node->config_[i].player_ << ", " <<
				node->config_[i].opponent_ << "  ";
		}
	}


}


*/

#endif

