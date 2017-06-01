#include "game.h"
#include "node.h"
#include "constants.h"
#include <iostream>



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

