#ifndef NODE_H_
#define NODE_H_
#include "constants.h"


// indicates the symbol of each tile space
// we should clarify the syntax
// here I'm assuming the 'player' is your machine
// and the 'opponent' would be the other machine
// 
enum SYMBOL {
	EMPTY = '.',
	PLAYER = 'X',
	OPPONENT = 'O'
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

	// only really necessary for first node
	Node() :
		config_(new char[constants::SIZE]),
		max_(0), min_(0), parent_(nullptr)
	{
		for (int i = 0; i < constants::SIZE; ++i)
			this->config_[i] = SYMBOL::EMPTY;
	}

	Node(Node* node) :
		config_(new char[constants::SIZE]), parent_(node)
	{
		for (int i = 0; i < constants::SIZE; ++i)
			this->config_[i] = node->config_[i];
		this->max_ = node->max_;
		this->min_ = node->min_;
	}

	~Node() {
		if (this->config_ != nullptr) {
			delete[] config_;
			config_ = nullptr;
		}
	}

	char* config_;
	int max_;
	int min_;
	Node* parent_;

};


#endif

