#ifndef PARTSYS_H
#define PARTSYS_H

#include <list>
#include "particle.h"

//<<<<<< HEAD
//class particleSystem {

	
//=======:

//

class ParticleSystem {
	int rows = 0;
	int columns = 0;
	std::list<Particle> particles; //placeholder list
public:
	ParticleSystem(int nRows = 0, int nColumns = 0) {
		if (nRows < 0) nRows = 0;
		rows = nRows;
		if (nColumns < 0) nColumns = 0;
		columns = nColumns;
	}
	int get_rows() {return rows;}
	int get_columns() {return columns;}
	int numParticles() {return particles.size();}
	void moveParticles() {}
	void add(Particle p) {particles.push_back(p);}
	void drawParticles() {}
	//if this is your key I wouldn't put it here because it it public to github now
//>>>>>>> 1db294e4ef3ac28ddb9d3369a2e60c3b6909e52b
};


#endif
