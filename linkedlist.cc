#include "linkedlist.h"

List::~List() {
	
}

int List::get_size() const {
	return size;
}

void List::insert_at_begin(const Particle& p) {
	Node* ins(p, nullptr, head);
	head->set_prev(ins);
	head = ins;
}

void List::delete_back() {
	return; 
}
