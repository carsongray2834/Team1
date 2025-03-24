

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
	
	//prepares to draw
	clearscreen();
	show_cursor(false);
	Node* temp = particles.get_head();
	//draws the list && handles fireworks
	while (temp != nullptr) {
		//this does the culling
		if (((temp->get_particle().get_life() < 0) || (temp->get_particle().get_x() < 0) || (temp->get_particle().get_y() < 0) || (temp->get_particle().get_x() > columns) || (temp->get_particle().get_y() > rows)) && (temp != particles.get_head())) {
			Node* temp2 = temp->get_prev();
			particles.delete_current(temp);
			temp = temp2;
		}
		else {
			//this handles fireworks
			if ((temp->get_particle().get_type() == FIREWORK) && (temp->get_particle().get_life() == 0)) firework(temp->get_particle().get_x(), temp->get_particle().get_y());
			//draws all valid particles
			if (temp->get_particle().get_life() > 0) draw(temp->get_particle());
		}
		temp = temp->get_next();
	}
	//displays particles for 5 secs before continuing the program
	sleep(5);
	clearscreen();
	show_cursor(true);
	movecursor(0, 0);
}

// Uncomment this when moveParticles() is ready in particleSystem.h
void ParticleSystem::moveParticles(){
	Node* temp = particles.get_head();

	while (temp != nullptr) {
		temp->get_particle().move();
		temp = temp->get_next();
	}
}

void ParticleSystem::hunt() {
	Node* temp = particles.get_head();
	while (temp != nullptr) {
		set_color(Color{0,0,0});
		graphics.drawPoint(temp->get_particle().get_y(), temp->get_particle().get_x());
	}
}


