#include <iostream> //For debugging via cout
#include "linkedlist.h"
#include "particleSystem.h"

//File Name: particleSystem.cc



bool ParticleSystem::firework(int x, int y) {
	srand(time(0));
	for (int i = 0; i < 50; i++) {
		Particle p(Color{(rand() % 256), (rand() % 256), (rand() % 256)}, STREAMER, x, y, ((rand() % 6) - 3), ((rand() % 6) - 3), ((rand() % 8) + 2));
	particles.insert_at_end(p);
	}
	return true; //in particleSystem.h the if statment checks for the creation of the firework we have to return true otherise its void 
}


//NOTE this code was giving errors

ParticleSystem mainParticleSystem;

void ParticleSystem::loadParticles(Node* firstParticle){
   for(Node* currentParticle = firstParticle; currentParticle != nullptr; currentParticle = currentParticle -> get_next()){
	mainParticleSystem.add(currentParticle->get_particle()); //Add each particle to the particles list
   }
}

void ParticleSystem::drawParticles(){ 
	List listOfParticles = mainParticleSystem.returnParticlesList();

   for(int i = 0; i < mainParticleSystem.numParticles();i++){
	   Particle holder = std::advance(listOfParticles,i);
	   holder->draw(); //calling draw() method as defined in particle.h
   }


}

void ParticleSystem::moveParticles(Node* firstParticle,double newdx, double, newdy){ //I am going to assume that move means we are moving with gravity.
  //Function paramater: the first element in LL because we need to move them all not just one. We need to go over the list.


}



