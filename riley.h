#include "particleSystem.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void scene3() {
    //we'll need:
    //      a polygonal light,
    //      a line connecting it to the top of the screen,
	//      a spark timer releasing ballistic particles from the center of the bottom edge of the light
	std::srand(time(0));
	clearscreen();
	Color grey = Color{170,170,170};
	Color spark = Color{230,230,0};
	Color light = Color{179,179,0};

	int fbs = 0;
	auto [rows,cols] = get_terminal_size();
	rows--;
	cols--;
	std::cout << rows << std::endl << cols << std::endl;
	ParticleSystem ps(rows, cols);
	show_cursor(false);
	/*int a = static_cast<int>(cols * 0.2);
	int b = static_cast<int>(cols * 0.4);
	int c = static_cast<int>(cols * 0.6);
	int d = static_cast<int>(cols * 0.8);
	int e = static_cast<int>(rows * 0.2);
	int f = static_cast<int>(rows * 0.4);

	std::cout << a << std::endl << b << std::endl << c << std::endl << d << std::endl << e << std::endl << f << std::endl;

	ps.set_color(spark);
	ps.drawRect(b,e,1,1);
	ps.drawRect(c,e,1,1);
	ps.drawRect(d,f,1,1);
	ps.drawRect(a,f,1,1);*/

	std::vector<int> polyvec = {b,e,c,e,d,f,a,f};
	polyvec = {b,e,a,f,d,f,c,e};

	
	for (int i = 0; i < 100; i++) {
		clearscreen();
		ps.set_color(grey);
		ps.drawPolygon(polyvec);
		//ps.set_color(spark);
		if (fbs <= 0) {
			for (int j = 0; j < rand() % 15 + 1; j++) {
				ps.add(Particle(spark, BALLISTIC, static_cast<int>(cols * 0.5), static_cast<int>(rows * 0.4), rand() % 7 - 3, -1 * (rand() % 2 + 1), rand() % 6));
			}
		}
		ps.moveAndDraw();
		usleep(100'000);
	}
}

