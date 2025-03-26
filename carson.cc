#include "carson.h"
#include "particle.h"
#include <unistd.h>

void carsoneffect() {
	clearscreen();
	show_cursor(false);
	auto [rows, cols] = get_terminal_size();
	ParticleSystem ps(rows - 1, cols - 1);
	for (int i = 0; i < 100; i++) {
		int ran = rand() % 255;
		for (int i = 0; i < 4; i++) {
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, 2, -1, 100));
		}
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols - 10, rand() % rows, 2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols -10, rand() % rows, 2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols - 10, rand() % rows, 2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols - 10, rand() % rows, 2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols - 10, rand() % rows, 2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols - 10, rand() % rows, 2, -1, 100));
		for (int i = 0; i < 4; i++) {
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
			ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows, -2, -1, 100));
		}
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows - 10, -2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows - 10, -2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows - 10, -2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows - 10, -2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows - 10, -2, -1, 100));
		ps.add(Particle(Color{ran, ran, ran}, STREAMER, rand() % cols, rand() % rows - 10, -2, -1, 100));

		ps.add(Particle(Color{255, ran, ran}, STREAMER, rand() % cols, rand() % rows, (rand() % 10) - 5, -3, 10));
		ps.cMoveAndDraw();
		usleep(100'000);
		ps.hunt();
	}
	clearscreen();
	show_cursor(true);
}

void ParticleSystem::cMoveAndDraw() {
	Node* temp = particles.get_head();
	//clearscreen();
	while (temp != nullptr) {
		temp->get_particle().move();
		if ((temp->get_particle().get_life() >= 0) && (temp->get_particle().get_x() >= 0) && (temp->get_particle().get_y() >= 0) && (temp->get_particle().get_x() <= columns) && (temp->get_particle().get_y() <= rows) && (temp->get_particle().get_y() + columns / 4 < temp->get_particle().get_x()) && ((-1 * temp->get_particle().get_x() + columns > temp->get_particle().get_y()))){	
			draw(temp->get_particle());
			if ((temp->get_particle().get_type() == FIREWORK) && (temp->get_particle().get_life() == 0) && firework(temp->get_particle().get_x(), temp->get_particle().get_y())){}
		}
		if ((temp->get_particle().get_life() < 0) || (temp->get_particle().get_y() + columns / 4 >= temp->get_particle().get_x()) || ((-1 * temp->get_particle().get_x() + columns <= temp->get_particle().get_y())) || (temp->get_particle().get_y() < 0)){
			//		Node* temp2 = temp->get_prev();
			Node* temp2 = temp;
			temp = temp->get_next();
			particles.delete_current(temp2);
			//		temp = temp2;
		}
		//temp->get_particle().move();
		else if(particles.get_size() > 0) {
			temp = temp->get_next();
		}
	}
}
