#include <iostream>
#include "io.h"
#include "node.h"



IO::IO() {

}


IO::~IO() {

}


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
		std::cout << MESSAGES[2] << " (" << timeParameters[0] << " - " << timeParameters[1] << "): ";
		getline(std::cin, stringInput);
		try {
			timeSeconds_ = std::stoi(stringInput);
			if (timeSeconds_ >= timeParameters[0] && timeSeconds_ <= timeParameters[1]) {
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
    if (row < 0 || row > DIMENSION || column < 0 || column > DIMENSION) {
        std::cout << ERROR_MESSAGES[2] << std::endl;
    } else {

    }
	std::cout << row << " " << column << std::endl;
}

void IO::print_game_config(Node* node) {
	std::cout << "  ";
	for (int i = 0; i < DIMENSION; i++) {
		std::cout << i << " ";
	}

	for (int i = 0; i < SIZE; i++) {
		if (i % DIMENSION == 0) {
			std::cout << "\n" << static_cast<char>('A' + (i / DIMENSION)) << " ";
		}
		std::cout << node->config_[i].symbol_ << " ";
	}
}

//	void IO::print_game_config(Node* node) {
//	std::cout << "  ";
//	for (int i = 0; i < DIMENSION; ++i)
//		std::cout << static_cast<char>('a'+i) << " ";
//
//	for (int i = 0; i < SIZE; ++i) {
//		if (i % DIMENSION == 0)
//			std::cout << "\n" << i / DIMENSION << " ";
//		std::cout << node->config_[i].symbol_ << " ";
//	}
//
//	std::cout << "\n" << std::endl;


