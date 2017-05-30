#ifndef CORE_H_
#define CORE_H_
struct Node;


class Core {


public:
	Core();
	~Core();

	int run();


private:
	void calculate_min_max(Node* node);
	void calculate_adjacent_element();


};


#endif

