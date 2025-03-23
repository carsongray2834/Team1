

#include <iostream> //For debugging via cout
#include "linkedlist.h"
#include "particleSystem.h"

//File Name: particleSystem.cc


ParticleSystem mainParticleSystem;

bool ParticleSystem::firework(int x, int y) {
	srand(time(0));
	for (int i = 0; i < 50; i++) {
		Particle p(Color{(rand() % 256), (rand() % 256), (rand() % 256)}, STREAMER, x, y, ((rand() % 6) - 3), ((rand() % 6) - 3), ((rand() % 8) + 2));
		particles.insert_at_end(p);
	}
	return true; //in particleSystem.h the if statment checks for the creation of the firework we have to return true otherise its void 
}


void ParticleSystem::loadParticles(Node* firstParticle){
	for(Node* currentParticle = firstParticle; currentParticle != nullptr; currentParticle = currentParticle -> get_next()){
		mainParticleSystem.add(currentParticle->get_particle()); //Add each particle to the particles list
	}
}

void ParticleSystem::drawParticles(){ 
//	List listOfParticles = mainParticleSystem.returnParticlesList();
	//Particle holder = particles.get_tail()->get_particle();
	clearscreen();
	show_cursor(false);

	for(Node* temp = particles.get_head(); temp; temp = temp->get_next()){
		Particle current = temp->get_particle();
		if(current.get_life() > 0) {
			graphics.setColor(current.get_color());
			graphics.drawPoint(current.get_x(), current.get_y());
		} 
		else {
			temp = temp->get_next();
			particles.delete_current(temp->get_prev());
		}

		//does not delete them if life < 0!!!!!
	//	graphics.drawPoint(current.get_y(),current.get_x()); //calling draw() method as defined in particle.h
	//	holder.move();
	//	holder = particles.get_tail()->get_particle(); //lets move on to the tail of where its pointing so we can draw the next particle
	}
//	show_cursor(true); this line bugs the screen out
}

// Uncomment this when moveParticles() is ready in particleSystem.h
void ParticleSystem::moveParticles(Node* firstParticle,double newdx, double newdy){ //I am going to assume that move means we are moving with gravity.
	//Function paramater: the first element in LL because we need to move them all not just one. We need to go over the list.

	List listOfParticles = mainParticleSystem.returnParticlesList();
	Particle holder = listOfParticles.get_head()->get_particle();

	for(int i = 0; i < listOfParticles.get_size();i++){ 

		//This is where we set x and y

		holder = listOfParticles.get_tail()->get_particle(); //lets move on to the tail of where its pointing so we can draw the next particle
	}


}



