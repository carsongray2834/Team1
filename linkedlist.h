#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"



//Class made by Jackson Douglass


class List {
	Node* head;
	Node* tail;
	int size = 0;

	public: 
	List() {} //Node will do it for us 
	~List();
	//copy constructor here?

	int get_size() const; 
	Node* get_head() const {return head;}
	Node* get_tail() const {return tail;}
	void insert_at_end(Particle& p);
	void delete_current(Node* current);




};
#endif
