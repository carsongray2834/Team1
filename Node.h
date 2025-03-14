#ifndef NODE_H
#define NODE_H

//Edited by Jackson Douglass
#include "particle.h" //includes iostream, particle, Color and die()


//NOTE: should we rewrite this to make Node reference a particle object? Right now, it is storing all the info itself, but we have a particle.h file to do that. 
class Node {//					|
	private://					|
	//							|
	// 							|
	//here is your particle < --i
	Particle p;

	Node* next;
	Node* prev;
	public:
	Node(Particle& new_p, Node* new_next = nullptr, Node* new_prev = nullptr) : p(new_p), next(new_next), prev(new_prev) {}

	
	
	Node* get_next() const;
	void set_next(Node* new_next); //parameters needed

	Node* get_prev() const;
	void set_prev(Node* new_prev); //parameters needed

	void set_particle(const Particle& new_p);
	

	//pass a Data struct object here and use the assignment = operator to set the internal .data member?
};

//Constructor is above

Node* Node::get_next() const {
	Node* n = new Node(); 
	return n;
}
void Node::set_next(Node* new_next) {

}

Node* Node::get_prev() const {
	return next;
}
void Node::set_prev(Node* new_prev) {
}

void Node::set_particle(const Particle& p) {
	p = new_p;
}


#endif



/*
struct Data {
	//we could possibly put everything in here instead
	//of makeing five doubles
	double x;//horizontal position, left is negative
	double y;//vertical positon, up is negative
	double vx;//horizontal velocity
	double vy;//vertical velocity
	double ax;//horizontal acceleration
	double ay;//vertical acceleration
	Data(double nx = 0, double ny = 0, double nvx = 0, double nvy = 0, double nax = 0, double nay = 0) {
		x = nx;
		y = ny;
		vx = nvx;
		vy = nvy;
		ax = nax;
		ay = nay;
	}
	void setData(double nx = 0, double ny = 0, double nvx = 0, double nvy = 0, double nax = 0, double nay = 0) {
		x = nx;
		y = ny;
		vx = nvx;
		vy = nvy;
		ax = nax;
		ay = nay;
	}
}; */

