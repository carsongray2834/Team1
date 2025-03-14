#ifndef PART_H
#define PART_H

//we can probably move the Data struct into this file, since this class will probably take it instead of Node. 

class Particle {
	//Data data; holding off on this for now
	char shape;
	int lifeFramesLeft;
	Color c(100,10,150);//feel free to change the default color
}
#endif
