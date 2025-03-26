#ifndef JACKSON_H
#define JACKSON_H

#include "particleSystem.h"
#include <ctime>
#include <cstdlib>

const Color cyan = {12, 245, 237};
const Color light_gray = {200, 200, 200};
const Color orange = {245, 157, 42};

//I put it in namespace in order to make a custom draw function, but I decided to scrap that idea
namespace Jackson {
		
	auto [rows, cols] = get_terminal_size();
	ParticleSystem pa(rows - 1, cols - 1); //Rows is y, columns is x

	void addWater() {
		for(int i = 0; i < 30; i++) { //make 30 water particles
			Particle p(cyan, BALLISTIC,0, 13, rand() % 10 + rand() % 12 - rand() % 5, 1 - rand() % 3, 500); //rand isn't really random after doing it 50 times the weird + and - rand stuff is my attempt at making it more random
			p.set_ay(2 - rand() % 2); //set gravity to 0-2m/s (cause it's water)
			pa.add(p);
		}
	
	}
	//Makes four particles every frame for the river that scroll across the screen
	void addRiver() {			//	rows(y)
		for(int i = 1; i <= 4; i++) { //v   v cols(x)
			Particle p(cyan, STREAMER, 10, rows - 6 + i, 1, 0, 10000); //4 particles for river
			pa.add(p);
		}
	}
	void addFireworks() {
		pa.add({orange, FIREWORK, cols - 50, rows - 20, -8, -5, 5});
	}
	void waterfall() {
		clearscreen();
		show_cursor(false);
		addFireworks();
			for(Node* temp = pa.get_head(); temp != nullptr; temp = temp->get_next()) {//I am always adding more particles, this is technially an infinate loop, but I am not going to bank on it
				pa.set_color(light_gray); //Set color to light gray and then draw the cliff
				pa.drawRect(15,0 , 10, rows - 15);
				pa.set_color(cyan);	//set it back to cyan draw the water
				pa.moveAndDraw();
				usleep(1'000'000 / 5); //Five frames per second
				pa.hunt(); //Goes to last particle location and resets it color "deleteing" the particle from the screen
				addWater(); 
				addRiver();
				if(rand() % 10 == 0) addFireworks(); //Randomly add fireworks
			}
	}
}
	
#endif
