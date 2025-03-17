#include "linkedlist.h"

List::~List() {
	
}

int List::get_size() const {
	return size;
}

void List::insert_at_end(const Particle& p) {
	Node* ins(p, nullptr, nullptr); //p, next, prev
	if(!tail) {
		head = ins;
		tail = ins;
	}
	else {
		ins->set_prev(tail);
		tail->set_next(ins);
		tail = ins;
	}
}

void List::delete_back() {
	return; 
}
