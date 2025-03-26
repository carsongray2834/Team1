#include "particleSystem.h"
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include "carson.h"

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

void carsoneffect() {
	//Prepares to render particles
//	std::srand(time(0));
	auto [rows, cols] = get_terminal_size();
	rows--;
	cols--;
	ParticleSystem ps(rows,cols);
	clearscreen();
	show_cursor(false);
	
	//Main loop for drawing particles
	for (int i = 0; i < 100; i++) {
		
		ps.moveAndDraw();
		//usleep(500'000);
	}
	clearscreen();
	resetcolor();
	show_cursor(true);
	movecursor(0, 0);
}
