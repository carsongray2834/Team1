#ifndef PARTSYS_H
#define PARTSYS_H
#include <list>
#include "particle.h"

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
};

#endif
