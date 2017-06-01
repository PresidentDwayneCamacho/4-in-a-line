// "Four in a Line"
// by Trey Amador and Scott Matsumura
// CPP CS420 Artificial Intelligence
// Due: Monday June 5, 2017

#include <iostream>
#include "io.h"
#include "node.h"
#include "constant.h"


IO::IO() {}

IO::~IO() {}

void IO::welcome() {
	std::cout << MESSAGES[0] << std::endl;
	std::cout << MESSAGES[1] << std::endl;
	this->ask_time();
	this->who_is_first();
	this->prompt();
}

void IO::ask_time() {
	bool leaveMenu = false;
	std::string stringInput;
	while(!leaveMenu) {
		std::cout << MESSAGES[2] << " (" << TIME_PARAMETERS[0] << " - " << TIME_PARAMETERS[1] << "): ";
		std::getline(std::cin, stringInput);
		try {
			timeSeconds_ = std::stoi(stringInput);
			if (timeSeconds_ >= TIME_PARAMETERS[0] && timeSeconds_ <= TIME_PARAMETERS[1]) {
				leaveMenu = true;
			} else {
				std::cout << ERROR_MESSAGES[0] << std::endl;
			}
		}
		catch (const std::exception e) {
			std::cout << ERROR_MESSAGES[0] << std::endl;
		}
	}
}

void IO::who_is_first() {
	bool leaveMenu = false;
	std::string stringInput;
	while(!leaveMenu) {
		std::cout << MESSAGES[3];
		getline(std::cin, stringInput);
		stringInput[0] = toupper(stringInput[0]);
		if (stringInput[0] == 'X' || stringInput[0] == 'O') {
			leaveMenu = true;
		} else {
			std::cout << ERROR_MESSAGES[1] << std::endl;
		}
	}
}

void IO::prompt() {
	bool leaveMenu = false;
	std::string stringInput;
	while(!leaveMenu) {
		std::cout << MESSAGES[4];
		getline(std::cin, stringInput);
		stringInput[0] = toupper(stringInput[0]);

		switch (stringInput[0]) {
			case 'S':
				//this->print_game_config(node);
				break;
			case 'U':
				break;
			case 'Q':
				leaveMenu = true;
				break;
			default:
				this->select_move(stringInput);
		}
	}
}

void IO::select_move(std::string& stringInput) {
	int row = (int) stringInput[0] - 65;
	int column = (int) stringInput[1] - 48;
    if (row < 0 || row > constant::LENGTH || column < 0 || column > constant::LENGTH) {
        std::cout << ERROR_MESSAGES[2] << std::endl;
    } else {

    }
	std::cout << row << " " << column << std::endl;
}

void IO::print_node(Node* node) {
	std::cout << "  ";
	for (int i = 0; i < constant::LENGTH; ++i)
		std::cout << i + 1 << " ";
	for (int i = 0; i < constant::SIZE; ++i) {
		if (i % constant::LENGTH == 0)
			std::cout << "\n" <<
			static_cast<char>('A' + i / constant::LENGTH) << " ";
		std::cout << node->config_[i] << " ";
	}
	std::cout << "\n" << std::endl;
}