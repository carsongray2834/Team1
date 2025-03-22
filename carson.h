#ifndef CARSON_H
#define CARSON_H
#include "particle.h"
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
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));
		ps.add(Particle({(rand() % 256), (rand() % 256), (rand() % 256)}, FIREWORK, (rand() % cols), (rand() % rows), ((rand() % 6) - 3), ((rand() % 6) - 3), (rand() % 10)));

		ps.moveAndDraw();
		usleep(100'000);
	}
	clearscreen();
	resetcolor();
	show_cursor(true);
}
#endif
