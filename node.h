#ifndef NODE_H_
#define NODE_H_


namespace {
	const int DIMENSION = 8;
	const int SIZE = DIMENSION * DIMENSION;
	const int SENTINEL = -1;
}


// indicates the symbol of each tile space
enum SYMBOL {
	EMPTY = '.',
	OPPONENT = 'X',
	PLAYER = 'O'
};


// token is how each tile is filled
// player is 'O', opponents is 'X', empty is '.'
// as shown from TOKEN enum above
struct Element {
	char symbol_;
	int player_;
	int opponent_;
};


// a node represents each part of a tree
// ptr to parent_ may be necessary to prune tree
// 
struct Node {

	Node() : 
		config_(nullptr), parent_(nullptr),
		max_(SENTINEL), min_(SENTINEL)
	{}

	Node(Element* config, Node* parent, int max = 0, int min = 0) :
		config_(config), parent_(parent), max_(max), min_(min)
	{}

	// parent_ will be deleted upon calling next destructor
	// do not delete it here
	~Node() {
		if (config_ != nullptr) {
			delete[] config_;
			config_ = nullptr;
		}
	}

	Element* config_;
	int max_;
	int min_;
	Node* parent_;

};


#endif
