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

	/*
	Particle& get_particle() {
		Particle p(Color{0, 0, 0}, STREAMER, 0, 0, 0);
		return p;
	} */ 
	//Definitons have to be in order, this could have caused an error
	Node* get_next() const {
		return next;
	}
	void set_next(Node* new_next) {
		next = new_next;
	}

	Node* get_prev() const {
		return prev;	
	}
	void set_prev(Node* new_prev) {
		prev = new_prev;
	}

	void set_particle(const Particle& new_p) {
		p = new_p;
	}
	Particle& get_particle() {
		return p;
	}
    bool operator==(const Node* other) {return next == other->get_next() && prev == other->get_prev();}
//also my bad I forgot to define it here before putting it below -Jackson

	//pass a Data struct object here and use the assignment = operator to set the internal .data member?
};
//I got a multiple definitions error for all of these function, maybe move them into the class definition
//should be ok now

#endif

