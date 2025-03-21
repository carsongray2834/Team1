#ifndef PARTSYS_H
#define PARTSYS_H

#include "linkedlist.h"
#include "particle.h"

//File Name: particleSystems.h


class ParticleSystem {
	int rows = 0;
	int columns = 0;
	List particles;
	ParticleGraphics graphics{Color{0, 0, 0}};
public:
	ParticleSystem(int nRows = 0, int nColumns = 0) {
		if (nRows < 0) nRows = 0;
		rows = nRows;
		if (nColumns < 0) nColumns = 0;
		columns = nColumns;
	}
	void loadParticles(Node* firstParticle);
	int get_rows() {return rows;}
	int get_columns() {return columns;}
	int numParticles() {return particles.get_size();}
	void moveAndDraw() {
		Node* temp = particles.get_head();
		for (int i = 0; i < particles.get_size(); i++) {
			temp->get_particle().move();
			draw(temp->get_particle());
			if ((temp->get_particle().get_type() == STREAMER) && (temp->get_particle().get_life() == 0) && firework(temp->get_particle().get_x(), temp->get_particle().get_y())){

			} 

	   		clearscreen();
		}
	}
	void draw(Particle pa) {
		if (pa.get_life() > 0){ 
		   ParticleGraphics pg;
		 pg.setColor(pa.get_color());
		 pg.drawPoint(pa.get_y(), pa.get_x());
		}
	}
	void drawParticles();
	void add(Particle p) {particles.insert_at_end(p);}
	bool firework(int x, int y);
	//This method was giving errors, and I don't think its necessary
	List returnParticlesList(){return particles;}

	//if this is your key I wouldn't put it here because it it public to github now
//>>>>>>> 1db294e4ef3ac28ddb9d3369a2e60c3b6909e52b

	//^^This is not my key I think git hub might have generated it idk. -Gurshan

};


#endif
