#include "particle.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

Particle::Particle (Color newC, Type newType, int newX, int newY, double newDx, double newDy, int newLife){
	c = newC;
	type = newType;
	if (newX < 0) newX = 0;
	x = newX;
	if (newY < 0) newY = 0;
	y = newY;
	dx = newDx;
	dy = newDy;
	if (newLife < 0) newLife = 0;
	life = newLife;
	if (type == BALLISTIC) ay = .981;
}
Color Particle::get_color() {return c;}
void Particle::set_color(Color newC) {c = newC;}
int Particle::get_x(){return x;}
int Particle::get_y(){return y;}
void Particle::set_x(int nX) {
	if (nX < 0) nX = 0;
	x = nX;
}
void Particle::set_y(int nY) {
	if (nY < 0) nY = 0;
	y = nY;
}
double Particle::get_dx() {return dx;}
double Particle::get_dy() {return dy;}
void Particle::set_dx(double new_dx) {dx = new_dx;}
void Particle::set_dy(double new_dy) {dy = new_dy;}
Type Particle::get_type() {return type;}
void Particle::set_type(Type nType) {type = nType;}
int Particle::get_life() {return life;}
void Particle::set_life(int newLife) {
	if (newLife < 0) newLife = 0;
	life = newLife;
}
void Particle::set_ax(double n) {ax = n;}
void Particle::set_ay(double n) {ay = n;}
double Particle::get_ax() {return ax;}
double Particle::get_ay() {return ay;}
//NOTE: Move function takes a particleSystem by reference in order to do the FIREWORK effect
void Particle::move() {
	const int dt = 1; //amount of "frames" since last move() call
	//could be used to change the time scale
	dx += std::round(ax * dt);
	dy += std::round(ax * dt);
	x += std::round(dx * dt);
	y += std::round(dy * dt);
	life--;
	if ((type == FIREWORK) && (life == 0)) {
		for (int i = 0; i < 50; i++) {
			srand(time(0));
			Particle p(Color{(rand() % 256), (rand() % 256), (rand() % 256)}, STREAMER, x, y, ((rand() % 4) - 3), ((rand() % 4) - 3), ((rand() % 9) + 2));
		}
	}
}
//if life < 0, then the particles should stop being drawn, I don't think there's a delete function yet
void Particle::draw() {}
