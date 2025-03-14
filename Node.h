#ifndef NODE_H
#define NODE_H

//Edited by Jackson Douglass
#include <iostream>

void die() {
	std::cout << "BAD INPUT SOMEWHERE!" << std::endl;
	exit(1);
}

struct Color {
	int r = 0;
	int g = 0;
	int b = 0;

	Color(int new_r, int new_g, int new_g) : r(new_r), g(new_g), b(new_b) {
		//r, g, and b must be greater than or equal to 0 and less than 255
	}
};

struct Data {
	//we could possibly put everything in here instead
	//of makeing five doubles
};


class Node {
	private:
	Node* next;
	Node* prev;
	Color c(100, 100, 50);
	/*
	char shape;
	double vel, accel;
	Color c;
	...
	...
	...
	or 
	Data data
	*/

	public:
	
	Node* get_next() const;
	void set_next(); //parameters needed

	Node* get_prev() const;
	void set_prev(); //parameters needed
	
};

Node* Node::get_next() const {
	Node* n = new Node(); 
	return n;
}
void Node::set_next {

}

Node* Node::get_prev() const {
	Node* n = new Node;
	return n;
}
void Node::set_prev() {

}

#endif
