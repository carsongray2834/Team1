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
	pa.set_columns(pa.get_columns() - 10);
	for(int i = 0; i < 2; i++) {
		Particle p(cyan, BALLISTIC, 15, 10, rand() % 15 + 1, 1, 1440);
		pa.add(p);
	}
	for(int j = 0; j < 100; j++) {
		pa.moveAndDraw();
		usleep(100'000);
	}
	
}	
