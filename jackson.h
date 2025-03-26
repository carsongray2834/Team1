#ifndef JACKSON_H
#define JACKSON_H

#include "particleSystem.h"
#include <ctime>
#include <cstdlib>

const Color cyan = {12, 245, 237};
const Color light_gray = {200, 200, 200};

namespace Jackson {
		
	auto [rows, cols] = get_terminal_size();
	ParticleSystem pa(rows - 1, cols - 1); //Rows is y, columns is x

	void addWater() {
		for(int i = 0; i < 30; i++) { //make 30 waters lol
			Particle p(cyan, BALLISTIC, 6, 15, rand() % 10 + rand() % 12 - rand() % 5, 0, 10000); //rand isn't really random after doing it 50 times the weird + and - rand stuff is my attempt at making it more random
			p.set_ay(2 - rand() % 2); //set gravity to 0-2m/s (cause it's water)
			pa.add(p);
		}
	
	}
	void addRiver() {//	rows(y)
		for(int i = 1; i <= 4; i++) { //v   v cols(x)
			Particle p(cyan, STREAMER, 10, 46 + i, 1, 0, 10000); //4 particles for river
			pa.add(p);
		}
	}
	void waterfall() {
		clearscreen();
		show_cursor(false);
			for(Node* temp = pa.get_head(); temp != nullptr; temp = temp->get_next()) {
				pa.set_color(light_gray);
				pa.drawRect(15,0 , 10, rows - 15);
				pa.set_color(cyan);	
				/*	if(temp->get_particle().get_y() > 30) { //Need to figure out how to skip this if it's already set to the values below
					temp->get_particle().set_type(STREAMER);
					temp->get_particle().set_ay(0.0);
					temp->get_particle().set_dx(1.0);
					temp->get_particle().set_dy(0.0);
				}*/
				pa.moveAndDraw();
				usleep(1'000'000 / 5);
				pa.hunt(); //Goes to last particle location and resets it color "deleteing" the particle from the screen
				addWater();
				addRiver();

			}
	}
}
	
#endif
