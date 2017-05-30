#include "core.h"
#include "test.h"
#include "node.h"
#include "game.h"
#include "io.h"


Core::Core() {

}


Core::~Core() {

}


// return negative value upon program failure
// return 0 upon program success
// note this is not relevant to whether you win the game or not
int Core::run() {

	Game game;
	IO io;
	
	Node* node = test::init_rand_empty_node(3, 3);
	io.print_game_config(node);
	game.calculate_min_max(node);
	std::cout << "max: " << node->max_ << std::endl;
	std::cout << "min: " << node->min_ << std::endl;
	
	return 0;
}



