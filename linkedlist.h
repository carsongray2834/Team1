#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"



//Class made by Jackson Douglass


class List {
	Node* head;
	Node* tail;
	Node* middle;
	int size = 0;

	public: 
	List() {} //Node will do it for us 
	~List();
	//copy constructor here?

	int get_size const { 
		return size; 
	}
	void insert_at_begin(const Particle& p);
	void delete_back();




};
#endif
