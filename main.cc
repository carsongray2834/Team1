#include <iostream>
#include <cassert>
#include "particleSystem.h"
using namespace std;

void particleTest();
void nodeTest();
void particleSystemTest();
void graphicsTest();
void particleTest2();

void die2(string s = "") {
	if(s == "") {
		cout << "BAD INPUT" << endl;
	}
	else {
		cout << s << endl;
	}
	exit(1);
}


int main(){
	int choice = 0;
	cout << "1. Run all tests\n";
	cout << "2. Add a particle to the particle system(list)\n";
	cout << "3. Draw all partices in particle system(list)\n";
	cout << "4. Run physics on added particles(loops)\n";
	// make a run physics for one frame?
	cout << "5. {insert name for your particle scene here} PartcleSystem#1\n";
	//I claim 1, Jackson
	cout << "6. {insert name for your particle scene here} PartcleSystem#2\n";
	//I'll take this second one, Carson
	cout << "7. {insert name for your particle scene here} PartcleSystem#3\n";
	cout << "8. {insert name for your particle scene here} PartcleSystem#4\n";
	//I claim this bottom one, Gurshan
	cout << "9. Run particle tests\n";
	cout << "10. Run node tests\n";
	cout << "11. Run particle system tests\n";
	cout << "12. Run graphics tests\n";
	cout.flush();

	cout << "Enter choice: " << endl;
	cin >> choice;
	if(!cin) die2("Choice must be a number!");
	if(cin.eof()) die2("EOF");

	
	ParticleSystem part(100,100);
	if(choice == 1) {
		//RUN TESTS HERE:
		graphicsTest();
		particleTest();
		nodeTest();
		//particleSystemTest();
		cout << "ALL TESTS PASSED" << endl;
	}
	else if(choice == 2) {
		srand(time(0));
		cout << "What particle location do you want? (type two, rows, cols)\n";
		int x, y = 0;
		cin >> x >> y;
		cout << "Type x velcity and y velocity\n";
		double dx, dy = 0.;
		cin >> dx >> dy;
		Color c(255, 0, 0);
		Particle prt(c, STREAMER, x, y, dx, dy, 100);
		part.add(prt);
		cout << "Particle added!" << endl;
	}
	else if(choice == 3) {
		
	}
	else if(choice == 4) {

	}
	else if(choice == 5) {

	}
	else if(choice == 6) {
		particleTest2();
	}
	else if(choice == 7) {

	}
	else if(choice == 8) {

	}
	else if(choice == 9) {
		particleTest();
	}
	else if(choice == 10) {
		nodeTest();
	}
	else if(choice == 11) {
		particleSystemTest();
	}
	else if(choice == 12) {
		graphicsTest();
	}
	else {
		die2("Choice must be from 1 to 8!");
	}


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
	Node* n1 = new Node(p1);
	n1->get_particle().set_type(BALLISTIC);
	assert(n1->get_particle().get_type() == BALLISTIC);
	cout << "NODE TESTS PASSED" << endl;
	Node* n2 = new Node(p1);
	n2->set_next(n1);
	assert(n2->get_next() == n1);
	delete n1;
	delete n2;
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
	
	clearscreen();//always clear the screen before using this class. It gets cursed. 
	
	p.setColor(Color{255,0,0});
	p.drawPoint(10,10);
	p.drawRect(11,11,11,15);
	p.drawOval(30,50,40,20);

	resetcolor();//always reset the color when you're done with graphics. 

	cout << "GRAPHICS TESTS PASSED" << endl;
}

void particleTest2() {
	srand(time(0));
	show_cursor(false);
	clearscreen();
	ParticleSystem p(100, 100);
	for (int i = 0; i < 100; i++) {
	p.add(Particle({0, 255, 100}, FIREWORK, (rand() % 100), 1, ((rand() % 6) - 3), 0, 5));
		p.moveAndDraw();
		usleep(50'000);
	}
	clearscreen();

	resetcolor();
	show_cursor(true);
}
