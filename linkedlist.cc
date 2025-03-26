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
	Node* ins = new Node(p, nullptr, nullptr); //p, next, prev
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

void List::delete_current(Node* current) {
      if(size == 0) return;
      else if (size == 1) {
          delete current;
	      size--;
		  head = nullptr;
		  tail = nullptr;
      }
  
      else if(head == current) {
		  Node* temp = head;
          head = head->get_next();
          delete temp;
          head->set_prev(nullptr);
          size--;
      }
      else if(tail == current) {
		  Node* temp = tail;
          tail = tail->get_prev();
          delete temp;;
          tail->set_next(nullptr);
		  size--;
      }
      else {
          Node* temp = current;
          temp->get_prev()->set_next(temp->get_next());
          temp->get_next()->set_prev(temp->get_prev());
          delete temp;
		  size--;
      }
  
 }

