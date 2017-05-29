#include "core.h"
#include "test.h"
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

	Element* elem = test::init_elements(SYMBOL::EMPTY, 1, 2);
	Node* node = test::init_node(elem, nullptr, 50, 12);

	io.print_game_config(node);

	return 0;
}


