#include "particleSystem.h"
#include <ctime>
#include <cstdlib>

const Color cyan = {12, 245, 237};
const Color light_gray = {200, 200, 200};

namespace Jackson {
		
	auto [rows, cols] = get_terminal_size();
	ParticleSystem pa(cols - 1, rows - 1); //Rows is y, columns is x

	void addWater() {
		for(int i = 0; i < 30; i++) { //make 30 waters lol
			Particle p(cyan, BALLISTIC, 15, 11, rand() % 10 + rand() % 12 - rand() % 5, 0, 5000); //rand isn't really random after doing it 50 times																																			//the weird + and - rand stuff is my attempt at making it more random
			p.set_ay(2 - rand() % 2); //set gravity to 0-2m/s (cause it's water)
			pa.add(p);
		}
	
	}
	void moveAndDraw() {
		for(Node* temp = pa.get_head(); temp; temp = temp->get_next()) {

		}

	}
	void waterfall() {
		clearscreen();
		show_cursor(false);
		pa.set_color(light_gray);
		pa.drawRect(15,0 , 10, rows - 20);	
		pa.set_color(cyan);
			for(Node* temp = pa.get_head(); temp; temp = temp->get_next()) {
				pa.set_color(light_gray);
				pa.drawRect(15,0 , 10, rows - 10);
				pa.set_color(cyan);
			//	pa.moveAndDraw();
				if(temp->get_particle().get_x() >= cols - 20) {
					temp->get_particle().set_type(STREAMER);
					temp->get_particle().set_ay(0.0);
					temp->get_particle().set_dx(1.0);
					temp->get_particle().set_dy(0.0);
				}
				usleep(500'000);
				pa.moveAndDraw();


				 // v makes it lag lol, I was trying to get it to stop at 20 and flow like a river
				/*
				if(temp->get_particle().get_x() >= cols + 100) {
					temp->get_particle().set_type(STREAMER);
					temp->get_particle().set_ay(0.0);
					temp->get_particle().set_dx(1.0);
					temp->get_particle().set_dy(0.0);
				//	temp->get_particle().set_y(cols - 5 + rand() % 3);
				} */
			}	
	}
}
	
	
