#include "core.h"
#include "test.h"
#include "node.h"
#include "io.h"


Core::Core() {

}


Core::~Core() {

}


// return negative value upon program failure
// return 0 upon program success
// note this is not relevant to whether you win the game or not
int Core::run() {

	IO io;
	
	Node* node = test::init_rand_empty_node(3,3);
	io.print_game_config(node);
	
	return 0;
}


// calculates min-max heuristics
void Core::calculate_min_max(Node* node) {

	int max = 0, min = 0;
	int dim = DIMENSION;
	for (int i = 0; i < SIZE; ++i) {



	}

}




