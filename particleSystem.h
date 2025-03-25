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
	void set_rows(int r) {rows = r;}
	void set_columns(int c) {columns = c;}
	void set_color(int r, int g, int b) {
		graphics.setColor(r,g,b);
	}
	void set_color(Color c) {
		graphics.setColor(c);
	}
	Node* get_head() {
		return particles.get_head();
	}
	Node* get_tail() { 
		return particles.get_tail();
	}
	int numParticles() {return particles.get_size();}
	void moveAndDraw(); 
	void draw(Particle& pa) {
		//resetcolor();
		//graphics.drawPoint(pa.get_oy(), pa.get_ox(), ' ');
		graphics.setColor(pa.get_color());
		graphics.drawPoint(pa.get_y(), pa.get_x(), pa.get_shape());
		std::cout.flush();
	}
	void drawParticles();
	void add(Particle p) {particles.insert_at_end(p);}
	bool firework(int x, int y);
	void moveParticles();
	void drawRect(int x, int y, int w, int h) {
		graphics.drawRect(x, y, w, h);
	}
	void drawLine(int x1, int y1, int x2, int y2) {
		graphics.drawRect(x1,y1,x2,y2);
	}
	void drawOval(int x, int y, int w, int h) {
		graphics.drawOval(x,y,w,h);
	}
	void drawPolygon(std::vector<int>& vec) {
		graphics.drawPolygon(vec);
	}

	List returnParticlesList(){return particles;}

	void hunt();

	//if this is your key I wouldn't put it here because it it public to github now
	//>>>>>>> 1db294e4ef3ac28ddb9d3369a2e60c3b6909e52b

	//^^This is not my key I think git hub might have generated it idk. -Gurshan

};


#endif
