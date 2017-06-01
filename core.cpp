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

	
	test_row_and_col_heuristic();

	//Node* node = new Node;
	//game.make_first_move(node);
	//io.print_node(node);
	//game.query_next_move(node);
	
	


	//game.test_node_querying();


	//Node* node = test_node_01();
	//io.print_node(node);
	//for (int r = 0; r < constants::DIMENSION; ++r) {
	//	test_row_heuristic_02(r);
	//}
	//for (int c = 0; c < constants::DIMENSION; ++c) {
	//	test_col_heuristic_01(c);
	//}
	
	/*

	io.welcome();
	//io.print_node(node);
	std::cout << "\n\n";
	//game.calculate_min_max(node);
	//std::cout << "max: " << node->max_ << std::endl;
	//std::cout << "min: " << node->min_ << std::endl;
	game.count_adjacent_symbols(node);
	test::print_node_score(node);

	*/

	return 0;
}


