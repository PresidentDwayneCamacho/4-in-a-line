// "Four in a Line"
// by Trey Amador and Scott Matsumura
// CPP CS420 Artificial Intelligence
// Due: Monday June 5, 2017

#include "game.h"
#include "node.h"
#include "constant.h"
#include <iostream>

Game::Game() {
	for (int i = 0; i < constant::LENGTH; ++i)
		tracker_.row_[i] = tracker_.col_[i] = 0;
}

Game::~Game() {}

// function returns the score which will be put into row of ScoreTracker
int Game::update_min_max_row(Node* node, int row, char player, char opponent) {
	int row_score = 0;
	int r = row*constant::LENGTH;
	for (int c = 0; c <= constant::WIN; ++c) {
		int uninterrupted = 0;
		for (int i = 0; i < constant::WIN && uninterrupted != -1; ++i) {
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
	for (int r = 0; r <= constant::WIN; ++r) {
		int uninterrupted = 0;
		for (int i = 0; i < constant::WIN && uninterrupted != -1; ++i) {
			char symbol = node->config_[c + constant::LENGTH*(r + i)];
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
	node->config_[(row - 1)*constant::LENGTH + (col - 1)] = symbol;
}