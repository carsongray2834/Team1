#include "particleSystem.h"

#include <ctime>
#include <cstdlib>

void waterfall() {
	const Color = {173,173,173};
	auto [rows, cols] = get_terminal_size();
	ParticleSystem(rows - 1, cols - 1);
	clearscreen();
	show_cursor(false);
	
}	
