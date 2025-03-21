#ifndef CARSON_H
#define CARSON_H
#include "particleSystem.h"
#include <stdlib.h>
#include <time.h>
void carsoneffect() {
	//Prepares to render particles
	std::srand(time(0));
	auto [rows, cols] = get_terminal_size();
	rows--;
	cols--;
	ParticleSystem ps(rows,cols);
	clearscreen();
	show_cursor(false);
	
	//Main loop for drawing particles
	for (int i = 0; i < 100; i++) {
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, STREAMER, (rand() % 100), (rand() % 50), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 25)));
		
		ps.moveAndDraw();
		usleep(50'000);
	}
	clearscreen();
	resetcolor();
	show_cursor(true);
}
#endif
