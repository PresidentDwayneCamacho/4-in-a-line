#include <iostream>
#include "io.h"
#include "node.h"



IO::IO() {

}


IO::~IO() {

}


void IO::print_game_config(Node* node) {

	std::cout << "  ";
	for (int i = 0; i < DIMENSION; ++i)
		std::cout << static_cast<char>('a'+i) << " ";

	for (int i = 0; i < SIZE; ++i) {
		if (i % DIMENSION == 0)
			std::cout << "\n" << i / DIMENSION << " ";
		std::cout << node->config_[i].symbol_ << " ";
	}

	std::cout << "\n" << std::endl;
}


