#include <iostream> //For debugging via cout
#include "linkedlist.h"
#include "particleSystem.h"

//File Name: particleSystem.cc



void ParticleSystem::firework(int x, int y) {
	srand(time(0));
	for (int i = 0; i < 50; i++) {
		Particle p(Color{(rand() % 256), (rand() % 256), (rand() % 256)}, STREAMER, x, y, ((rand() % 6) - 3), ((rand() % 6) - 3), ((rand() % 8) + 2));
	particles.add(p);
	}
}


//NOTE this code was giving errors
/*
ParticleSystem mainParticleSystem;

void particleSystem::loadParticles(Node* firstParticle){
   for(Node* currentParticle = firstParticle; currentParticle != nullptr; currentParticle = currentParticle -> next){
	mainParticleSystem->add(currentParticle); //Add each particle to the particles list
   }
}

void particleSystem::drawParticles(){ 
	list listOfParticles = mainParticlesSystem->returnParticlesList();

   for(int i = 0; i < mainParticlesSystem->numParticles();i++)){
	   Particle holder = std::advance(listOfParticles,i);
	   holder->draw(); //calling draw() method as defined in particle.h
   }


}

void PartSystems::moveParticles(Node* firstParticle,double newdx, double, newdy){ //I am going to assume that move means we are moving with gravity.
  //Function paramater: the first element in LL because we need to move them all not just one. We need to go over the list.


}

*/

