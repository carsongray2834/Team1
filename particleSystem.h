#ifndef PARTSYS_H
#define PARTSYS_H

#include "linkedlist.h"
#include "particle.h"

//File Name: particleSystems.h

class ParticleSystem {
	int rows = 0;
	int columns = 0;
	List particles;
public:
	ParticleSystem(int nRows = 0, int nColumns = 0) {
		if (nRows < 0) nRows = 0;
		rows = nRows;
		if (nColumns < 0) nColumns = 0;
		columns = nColumns;
	}
	int get_rows() {return rows;}
	int get_columns() {return columns;}
	int numParticles() {return particles.get_size();}
	void moveParticles() {}
	void add(Particle p) {particles.insert_at_end(p);}
	void drawParticles() {}
	//This method was giving errors, and I don't think its necessary
	//std::list returnParticlesList(){return particles;}

	//if this is your key I wouldn't put it here because it it public to github now
//>>>>>>> 1db294e4ef3ac28ddb9d3369a2e60c3b6909e52b

	//^^This is not my key I think git hub might have generated it idk. -Gurshan

};


#endif
