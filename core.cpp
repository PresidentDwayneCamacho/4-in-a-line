// "Four in a Line"
// by Trey Amador and Scott Matsumura
// CPP CS420 Artificial Intelligence
// Due: Monday June 5, 2017

#include "core.h"
#include "test.h"
#include "node.h"
#include "game.h"
#include "io.h"

Core::Core() {}

Core::~Core() {}

// return negative value upon program failure
// return 0 upon program success
// note this is not relevant to whether you win the game or not
int Core::run() {

	Game game;
	IO io;

	//io.welcome();
	//test_row_and_col_heuristic();
    io.tempPrompt();

	return 0;
}


