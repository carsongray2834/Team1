#include <iostream>
#include <cassert>
#include "particleSystem.h"
using namespace std;

void particleTest();
void nodeTest();
void particleSystemTest();
void graphicsTest();

int main(){
	//RUN TESTS HERE:
	particleTest();
	nodeTest();
	//particleSystemTest();
	graphicsTest();

	cout << "ALL TESTS PASSED" << endl;
	return 0;
}

void particleTest() {
	Particle p1({255, 255, 255}, STREAMER, 50, 51, 1, 1, 10);
	assert((((p1.get_color().r == 255) && (p1.get_color().b == 255)) && (p1.get_color().g == 255)) && "COLOR TEST");
	assert((p1.get_type() == STREAMER) && "TYPE TEST 1");
	p1.set_type(BALLISTIC);
	assert((p1.get_type() == BALLISTIC) && "TYPE TEST 2");
	assert((p1.get_x() == 50) && "X TEST 1");
	p1.set_x(500);
	assert((p1.get_x() == 500) && "X TEST 2");
	p1.set_y(-4);
	assert((p1.get_y() == 0) && "Y TEST");
	assert((1 == p1.get_dx()) && (1 == p1.get_dy()) && "VELOCITY TEST 1");
	p1.set_dy(-5);
	assert((p1.get_dy() == -5) && "VELOCITY TEST 2");
	assert((p1.get_life() == 10) && "LIFE TEST 1");
	p1.set_life(-1);
	assert((p1.get_life() == 0) && "LIFE TEST 2");

	cout << "PARTICLE TESTS PASSED" << endl;
}

void nodeTest() {	
	Particle p1({255, 255, 255}, STREAMER, 50, 51, 1, 1, 10);
	Node n1(p1);
	n1.get_particle().set_type(BALLISTIC);
	assert(n1.get_particle().get_type() == BALLISTIC);
	cout << "NODE TESTS PASSED" << endl;
	Node n2(p1);
	n2.set_next(&n1);
	assert(n2.get_next() == &n1);
}

void particleSystemTest() {
	ParticleSystem p(10, 10);
	p.add(Particle({255, 255, 255}, STREAMER, 50, 51, 1, 1, 10));
	assert(p.numParticles() == 1);
	assert(p.get_rows() == 10);
	ParticleSystem c(-10, -10);
	assert(c.get_rows() == 0);
	assert(c.get_columns() == 0);

	cout << "PARTICLE STYSTEM TESTS PASSED" << endl;
}

void graphicsTest() {
	ParticleGraphics p(Color{255, 0, 9});
	p.setColor(Color{0,0,0});
	assert(p.getColor().r == 0);
	assert(p.getColor().b == 0);
	assert(p.getColor().g == 0);
	
	//clear_screen();//always clear the screen before using this class. It gets cursed. 
	p.setColor(Color{255,0,0});
	p.drawPoint(10,10);
	//reset_color();

	cout << "GRAPHICS TESTS PASSED" << endl;
}

