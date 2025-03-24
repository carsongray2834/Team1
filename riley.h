#include "particleSystem.h"
#include <cstdlib>
#include <ctime>

void scene3() {
    //we'll need:
    //      a polygonal light,
    //      a line connecting it to the top of the screen,
	//      a spark timer releasing ballistic particles from the center of the bottom edge of the light
    //for now:
    //      draw a rectangle
    //      then release one round of sparks
    //      then make lines and polygons
    //      then set the timer
    srand(time(0));
	Color grey = Color{170,170,170};
	Color spark = Color{230,230,0};
	Color light = Color{179,179,0};

	int fbs = 0;
	auto [rows,cols] = get_terminal_size();
	rows--;
	cols--;
	ParticleSystem ps(rows, cols);
	show_cursor(false);
	int a = static_cast<int>(cols * 0.2);
	int b = static_cast<int>(cols * 0.4);
	int c = static_cast<int>(cols * 0.6);
	int d = static_cast<int>(cols * 0.8);
	int e = static_cast<int>(rows * 0.2);
	int f = static_cast<int>(rows * 0.4);

	vector<int> polyvec = {b,e,c,e,d,f,a,f};

	for (int i = 0; i < 100; i++) {
		ps.graphics.drawPolygon(polyvec);
	}
}

