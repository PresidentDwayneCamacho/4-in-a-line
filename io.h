#ifndef IO_H_
#define IO_H_
struct Node;


class IO {


public:
	IO();
	~IO();

	void welcome();
	void ask_time();
	void who_is_first();
	void prompt();
	void print_game_config(Node* node);
	void select_move(std::string& stringInput);


private:
	int timeSeconds_;
	char firstPlayer_;
	const int timeParameters[2] = {5, 100};
	const std::string messages_[5] = {
			"Welcome to Four in a Line.",
			"by Trey \"FuckFace\" Amador and Scott \"ShitBalls\" Matsumura",
			"Length of time in seconds for the computer to make a decision",
			"Select who goes first (X = computer, O = player): ",
			"[S]how board, [U]ndo, [Q]uit, or enter move: "
	};
	const std::string errorMessages_[3] = {
			"Please enter an appropriate number.",
			"Please enter an appropriate player.",
			"Please enter an appropriate option."
	};
};


#endif

