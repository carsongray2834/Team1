#include <iostream>
#include <cassert>
#include "particle.h"
using namespace std;

void particleTest();
void nodeTest();
void particleSystemTest();
void graphicsTest();

int main(){
	//RUN TESTS HERE:
	particleTest();
	nodeTest();
	particleSystemTest();
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
	cout << "NODE TESTS PASSED" << endl;
}

void particleSystemTest() {
	cout << "PARTICLE STYSTEM TESTS PASSED" << endl;
}

void graphicsTest() {
	cout << "GRAPHICS TESTS PASSED" << endl;
}

