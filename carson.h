#ifndef CARSON_H
#define CARSON_H
#include <map>
#include "linkedlist.h"

template <typename T>
struct cNode {
	cNode* next = nullptr;
	cNode* prev = nullptr;
	T data;
};

template <typename T>
class cList {
	cNode<T>* head;
	cNode<T>* tail;
	int size;
public:
	cNode<T>* get_head() {return head;}
	int get_size() {return size;}
	cList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	~cList() {
		cNode<T>* temp = head;
		while (temp != nullptr) {
			cNode<T>* current = temp;
			temp = temp->next;
			delete current;
		}
		delete temp;
	}


	//add node
	void add(T d) {
		if (!head) {
			head = new cNode<T>;
			head->data = d;
			tail = head;
		}
		else {
			cNode<T>* temp = new cNode<T>;
			temp->data = d;
			temp->prev = tail;
			tail->next = temp;
		}
		size++;
	}
	//delete node
	void dlNode(cNode<T>* curr) {
		if (size == 0) return;
		else if (curr == nullptr) return;
		else if (size == 1) {
			cNode<T>* temp = curr;
			delete curr;
			size--;
			head = nullptr;
			tail = nullptr;
		}
		else if (curr == head) {
			auto temp = head;
			head = head->next;
			delete temp->prev;
			if (head) head->prev = nullptr;
			size--;
		}
	}
};

class static_mass {
	int x;
	int y;
	int mass;
	std::map<std::pair<int, int>, std::pair<double, double>> accelMap;
public:
	static_mass(int nx, int ny, int nmass);
	int get_x() {return x;}
	int get_y() {return y;}
	int get_mass() {return mass;}
	void map_accel(int rows, int cols);
};

class cParticle {
	double x;
	double y;
	double dx;
	double dy;
	double ax;
	double ay;
	char ch;
	Color c;
public:
	cParticle(double nx = 0, double ny = 0, double ndx = 0, double ndy = 0, double nax = 0, double nay = 0, char nch = '*', Color nc = Color{0, 255, 0}) : x(nx), y(ny), dx(ndx), dy(ndy), ax(nax), ay(nay), ch(nch), c(nc) {}
	void draw();
	void hide(int w, int k);
	void move();
	//hide move draw
	void hmd();
};

class cParticleSystem {
	int cols;
	int rows;
	cList<cParticle> particles;
public:
	cParticleSystem(int nrows, int ncols) {
		cols = ncols;
		rows = nrows;
	}
	void add(cParticle p);
	void moveAndDraw();
};

void carsoneffect();

#endif
