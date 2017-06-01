// "Four in a Line"
// by Trey Amador and Scott Matsumura
// CPP CS420 Artificial Intelligence
// Due: Monday June 5, 2017

#ifndef NODE_H_
#define NODE_H_
#include "constant.h"

// indicates the symbol of each tile space
// we should clarify the syntax
// here I'm assuming the 'player' is your machine
// and the 'opponent' would be the other machine
enum SYMBOL {
	EMPTY = '.',
	PLAYER = 'X',
	OPPONENT = 'O'
};

// a node represents each part of a tree
// ptr to parent_ may be necessary to prune tree
// 

struct Node {

	// only really necessary for first node
	Node() :
		config_(new char[constant::SIZE]),
        playerX_(new int[constant::SIZE]),
        playerO_(new int[constant::SIZE]),
		max_(0), min_(0), parent_(nullptr)
	{
		for (int i = 0; i < constant::SIZE; ++i) {
            this->config_[i] = SYMBOL::EMPTY;
            this->playerX_[i] = 0;
            this->playerO_[i] = 0;
        }
	}

	Node(Node* parentNode) :
		config_(new char[constant::SIZE]),
        playerX_(new int[constant::SIZE]),
        playerO_(new int[constant::SIZE]),
        parent_(parentNode)
	{
		for (int i = 0; i < constant::SIZE; ++i) {
            this->config_[i] = parentNode->config_[i];
            this->playerX_[i] = parentNode->playerX_[i];
            this->playerO_[i] = parentNode->playerO_[i];
        }
		this->max_ = parentNode->max_;
		this->min_ = parentNode->min_;
	}

	~Node() {
		if (this->config_ != nullptr) {
			delete[] config_;
            delete[] playerX_;
            delete[] playerO_;
			config_ = nullptr;
            playerX_ = nullptr;
            playerO_ = nullptr;
		}
	}

	char* config_;
    int* playerX_;
    int* playerO_;
	int max_;
	int min_;
	Node* parent_;

};

#endif //NODE_H_