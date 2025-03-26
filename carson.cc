#include <stdlib.h>
#include <time.h>
#include "carson.h"
#include <cmath>

void carsoneffect() {
	//Prepares to render particles
	std::srand(time(0));
	auto [rows, cols] = get_terminal_size();
	rows--;
	cols--;
	cParticleSystem ps(rows, cols);
	clearscreen();
	show_cursor(false);
	
	ps.add(cParticle(2, 2, 1, 1));
	ps.add(cParticle(2, 3, 1, 1));
	ps.add(cParticle(2, 4, 1, 1));
	//ps.add(cParticle(2, 5, 1, 1));
	//ps.add(cParticle(2, 6, 1, 1));
	for (int i = 0; i < 100; i++) {
		ps.moveAndDraw();
		usleep(100'000);
	}

	//Main loop for drawing particles
	clearscreen();
	resetcolor();
	show_cursor(true);
	movecursor(0, 0);
}

static_mass::static_mass(int nx, int ny, int nmass) {
	x = nx;
	y = ny;
	if (nmass > 10) {nmass = 10;}
	if (nmass < 1) {nmass = 1;}
	mass = nmass;
}
void static_mass::map_accel(int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			accelMap[std::pair(j, i)] = std::pair(1.0, 2.0);
		}
	}
}



//my classes methods definitions

void cParticle::draw() {
	movecursor(std::round(y), std::round(x));
	setcolor(c.r, c.g, c.b);
	if (ch == ' ') setbgcolor(c.r, c.g, c.b);
	std::cout << ch;
	resetcolor();
}

void cParticle::hide(int w, int k) {
	movecursor(w, k);
	resetcolor();
	std::cout << ' ';
}

void cParticle::move() {
	dx += ax;
	dy += ay;
	x += dx;
	y += dy;
}

void cParticle::hmd() {
	int tx = x;
	int ty = y;
	move();
	hide(ty, tx);
	draw();
	std::cout.flush();
}


void cParticleSystem::add(cParticle p) {
	particles.add(p);
}
void cParticleSystem::moveAndDraw(){
	for (cNode<cParticle>* temp = particles.get_head(); temp != nullptr; temp = temp->next) {
		temp->data.hmd();
	}
}

