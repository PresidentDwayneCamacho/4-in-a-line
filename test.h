#ifndef TEST_H_
#define TEST_H_
#include <iostream>
#include "node.h"
#include "constants.h"


// the test namespace is used for running unit tests
// important so you don't have to snoop around project code
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


#endif

