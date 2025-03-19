#include "linkedlist.h"

List::~List() {
	Node* temp = head;
	while(temp != nullptr) {
		Node* current = temp;
		temp = temp->get_next();
		delete current;
	}
	delete temp;
}

int List::get_size() const {
	return size;
}

void List::insert_at_end(Particle& p) {
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
	size++;
}

void List::delete_current() {
	return; 
}
