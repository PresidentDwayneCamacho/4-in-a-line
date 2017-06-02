// "Four in a Line"
// by Trey Amador and Scott Matsumura
// CPP CS420 Artificial Intelligence
// Due: Monday June 5, 2017

#ifndef IO_H_
#define IO_H_

#include "game.h"
#include <string>

struct Node;

class IO {

public:
	IO();
	~IO();

	void welcome();
	void ask_time();
	void who_is_first();
	void prompt();
	void select_move(std::string& stringInput);
    bool ask_quit();

    void tempPrompt(); // Erase when finished

	void print_node(Node* node);

    void print_game_board();
	void print_playerX_heuristic();
	void print_playerO_heuristic();

private:
	Game* game;
	int timeSeconds_;
	char firstPlayer_;
	const int TIME_PARAMETERS[2] = {2, 30};
	const std::string MESSAGES[6] = {
			"Welcome to \"Four in a Line\".",
			"by Trey \"FuckFace\" Amador and Scott \"ShitBalls\" Matsumura",
			"Length of time in seconds for the computer to make a decision",
			"Select who goes first (X = computer, O = player): ",
			"[S]how board, [U]ndo, [Q]uit, or enter move: ",
            "Are you sure you want to quit, [y]es or [n]o? "
	};
	const std::string ERROR_MESSAGES[3] = {
			"Please enter an appropriate number.",
			"Please enter an appropriate player.",
			"Please enter an appropriate option."
	};
	static void print_board(char* config);
	static void print_heuristic(int* player);
};

#endif //IO_H_