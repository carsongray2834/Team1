#include "particleSystem.h"
#include <ctime>
#include <cstdlib>

const Color cyan = {12, 245, 237};
const Color light_gray = {173, 173, 173};
void waterfall() {
	srand(time(0));
	auto [rows, cols] = get_terminal_size();
	ParticleSystem pa(rows - 1, cols - 1);
	clearscreen();
	show_cursor(false);
	pa.set_color(light_gray);
	pa.drawRect(15,0 , 10, rows - 20);	
	pa.set_color(cyan);

	//pa.set_rows(rows + 10);
	pa.set_rows(rows + 10); //I am trying to keep the rectangle
	for(int i = 0; i < 50; i++) { //make 50 waters lol
		Particle p(cyan, BALLISTIC, 15, 11, rand() % 20 + 1, 1, 1440);
	//	p.set_ay(2); //set gravity to 4m/s (cause it's water)
		pa.add(p);
	}
	for(int j = 0; j < 100; j++) {
		pa.moveAndDraw();
		usleep(250'000); // 4 fps
	//	pa.drawRect(15,0 , 10, rows - 20);	
	}
	
}	
