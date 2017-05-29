#pragma once
#include <iostream>
#include "node.h"



// the test namespace is used for running unit tests
// important so you don't have to snoop around project code
namespace test {


	void fill_element();
	void fill_node();

	Element* init_elements(char token, int player, int opponent);
	Node* init_node(Element* config, Node* parent, int max, int min);

	void printelem(Element& element);
	void printnode(Node* node);



	void fill_element() {

		Element a = { SYMBOL::EMPTY, 2, 3 };
		Element b = { SYMBOL::PLAYER, 1, 1 };
		Element c = { SYMBOL::OPPONENT, 0, 2 };

		printelem(a);
		printelem(b);
		printelem(c);

	}


	// tests how to create a new node for the game tree
	void fill_node() {

		Node* node_a = init_node(init_elements(SYMBOL::EMPTY, 1, 1), nullptr, 100, 10);
		Node* node_b = init_node(init_elements(SYMBOL::PLAYER, 2, 0), node_a, 30, 12);
		Node* node_c = init_node(init_elements(SYMBOL::OPPONENT, 1, 0), node_a, 54, 9);

		printnode(node_a);
		printnode(node_b);
		printnode(node_c);

		delete node_a;
		delete node_b;
		delete node_c;

	}



	Element* init_elements(char token, int player, int opponent) {
		Element* elem = new Element[SIZE];
		for (int i = 0; i < SIZE; ++i) {
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
		return node;
	}



	void printelem(Element& element) {
		std::cout << "Test print element:" << "\n";
		std::cout <<
			"Element: " << element.symbol_ << "\n" <<
			"Player: " << element.player_ << "\n" <<
			"Opponent: " << element.opponent_ << "\n" << std::endl;
	}



	void printnode(Node* node) {
		std::cout << "Test print node:" << "\n\n";
		for (int i = 0; i < SIZE; ++i) {
			std::cout << "Element NO. " << i << ".\n";
			printelem(node->config_[i]);
			std::cout << "Max: " << node->max_ << "\n";
			std::cout << "Min: " << node->min_ << "\n";
			std::cout << "\n" << std::endl;
		}
		std::cout << "\n\n" << std::endl;
	}


}


