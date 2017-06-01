// "Four in a Line"
// by Trey Amador and Scott Matsumura
// CPP CS420 Artificial Intelligence
// Due: Monday June 5, 2017

#ifndef IO_H_
#define IO_H_
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
	//void print_game_config(Node* node);
	void select_move(std::string& stringInput);

	void print_node(Node* node);

private:
	int timeSeconds_;
	char firstPlayer_;
	const int TIME_PARAMETERS[2] = {2, 30};
	const std::string MESSAGES[5] = {
			"Welcome to \"Four in a Line\".",
			"by Trey \"FuckFace\" Amador and Scott \"ShitBalls\" Matsumura",
			"Length of time in seconds for the computer to make a decision",
			"Select who goes first (X = computer, O = player): ",
			"[S]how board, [U]ndo, [Q]uit, or enter move: "
	};
	const std::string ERROR_MESSAGES[3] = {
			"Please enter an appropriate number.",
			"Please enter an appropriate player.",
			"Please enter an appropriate option."
	};
};

#endif //IO_H_