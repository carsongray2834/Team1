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
		
		ps.moveAndDraw();
		//usleep(500'000);
	}
	clearscreen();
	resetcolor();
	show_cursor(true);
	movecursor(0, 0);
}
