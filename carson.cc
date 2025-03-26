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
	resetcolor();
	cParticleSystem ps(rows, cols);
	clearscreen();
	show_cursor(false);
	ps.mapAccel(rows / 2, cols / 2, 10);
	for (int i = 0; i < 100; i++) {
		ps.add(cParticle((cols - 3) - (rand() % 5), (rows - 3) - (rand() % 5), -3 /*- (rand() % 5)*/, -5 /*- (rand() % 5)*/, 0, 0, ' ', {(rand() % 50), (rand() % 50), 240}));
		ps.add(cParticle(rand() % 5, rand() % 5, 3 /*- (rand() % 5)*/, 5 /*- (rand() % 5)*/, 0, 0, ' ', {(rand() % 50), (rand() % 50), 240}));
		ps.add(cParticle((cols - 3) - (rand() % 5), (rand() % 5), -3 /*- (rand() % 5)*/, 5 /*- (rand() % 5)*/, 0, 0, ' ', {(rand() % 50), (rand() % 50), 240}));
		ps.add(cParticle(rand() % 5, (rows - 3) - (rand() % 5), 3 /*- (rand() % 5)*/, -5 /*- (rand() % 5)*/, 0, 0, ' ', {(rand() % 50), (rand() % 50), 240}));
		ps.moveAndDraw();
		usleep(100'000);
	}

	//Main loop for drawing particles
	clearscreen();
	resetcolor();
	show_cursor(true);
	movecursor(0, 0);
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
	if (w != -1) movecursor(w, k);
	else movecursor(y, x);
	resetcolor();
	std::cout << ' ';
}

void cParticle::move() {
	dx += ax;
	dy += ay;
	const int speedLimit = 3;
	if (dx > speedLimit) dx = speedLimit;
	if (dy > speedLimit) dy = speedLimit;
	if (dx < -speedLimit) dx = -speedLimit;
	if (dy < -speedLimit) dy = -speedLimit;
	x += dx;
	y += dy;
}

void cParticle::hmd() {
	tx = x;
	ty = y;
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
		if ((temp->data.x > 0) && (temp->data.y > 0) && (temp->data.x < cols) && (temp->data.y < rows)) {
			auto [jx, jy] = accelMap[std::pair(temp->data.x, temp->data.y)];
			temp->data.ax += jx;
			temp->data.ay += jy;

			temp->data.move();
			temp->data.draw();
			temp->data.hide(temp->data.ty, temp->data.tx);
		}
		else {
			temp->data.hide(temp->data.ty, temp->data.tx);
		}
	}
}

void cParticleSystem::mapAccel(int x, int y, int mass) {
	const double G = 100;
	double ax;
	double ay;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (j > x) {
				//+x,+y
				if (i > y) {
					ay = 1;
					ax = -1;
				}
				//+x,-y
				else {
					ay = 1;
					ax = -1;
				}
			}
			else {
				//-x,+y
				if (i > y) {
					ay = 1;
					ax = 1;
				}
				//-x,-y
				else {
					ax = 1;
					ay = 1;
				}
			}

			double dx = x - j;
			double dy = y - i;
			double r2 = dx * dx + dy * dy;
			if (r2 == 0) continue;

			double r = std::sqrt(r2);
			double accel = (G * mass) / r2;
			ax *= std::abs(accel * (dx / r));
			ay *= std::abs(accel * (dy / r));

			accelMap[{j, i}] = {ax, ay};
			//auto [t1, t2] = accelMap[{j, i}];
			//std::cout << j << ',' << i << ' '<< t1 << ',' << t2 << std::endl;
		}
	}

}
