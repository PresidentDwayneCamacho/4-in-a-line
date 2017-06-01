// "Four in a Line"
// by Trey Amador and Scott Matsumura
// CPP CS420 Artificial Intelligence
// Due: Monday June 5, 2017

#ifndef TEST_H_
#define TEST_H_
#include "core.h"
#include "node.h"
#include "game.h"
#include "io.h"
#include "constant.h"
#include <iostream>

Node* test_node_01();

void test_row_heuristic_01();
void test_row_heuristic_02(int row);
void test_row_heuristic_03(int row);

void test_col_heuristic_01(int col);
void test_col_heuristic_02(int col);


void test_row_heuristic_01() {

	Game game;
	IO io;
	Node* node = test_node_01();
	io.print_node(node);
	int row = 2;
	int row_score = game.update_min_max_row(node, row, SYMBOL::PLAYER, SYMBOL::OPPONENT);
	std::cout << "row " << row << ", heuristic row score: " << row_score << "\n" << std::endl;
	delete node;

}



void test_row_heuristic_02(int row) {

	Game game;
	IO io;
	Node* node = test_node_01();
	io.print_node(node);
	int row_score = game.update_min_max_row(node, row, SYMBOL::PLAYER, SYMBOL::OPPONENT);
	std::cout << "row " << row << ", heuristic row score: " << row_score << "\n" << std::endl;
	delete node;

}



void test_row_heuristic_03(int row) {

	Game game;
	IO io;
	Node* node = test_node_01();
	io.print_node(node);
	int row_score = game.update_min_max_row(node, row, SYMBOL::OPPONENT, SYMBOL::PLAYER);
	std::cout << "row " << row << ", heuristic row score: " << row_score << "\n" << std::endl;
	delete node;

}



void test_col_heuristic_01(int col) {

	Game game;
	IO io;
	Node* node = test_node_01();
	io.print_node(node);
	int col_score = game.update_min_max_col(node, col, SYMBOL::PLAYER, SYMBOL::OPPONENT);
	std::cout << "col " << col << ", heuristic col score: " << col_score << "\n" << std::endl;
	delete node;

}


void test_col_heuristic_02(int col) {

	Game game;
	IO io;
	Node* node = test_node_01();
	io.print_node(node);
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

#endif //NODE_H_