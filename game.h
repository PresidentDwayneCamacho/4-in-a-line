#ifndef GAME_H_
#define GAME_H_
struct Node;


class Game {

public:
	Game();
	~Game();

	void calculate_min_max(Node* node);
	void count_adjacent_symbols(Node* node);

private:
	inline bool can_check_right(int i);
	inline bool can_check_down(int i);
	inline bool can_check_left(int i);
	inline bool can_check_up(int i);

	void query_adjacent_element(Node* node, int index, int offset);
	void query_adjacent_min_max(Node* node, int index, int offset);
	

private:



};


#endif

