#include <iostream> //For debugging via cout
#include "linkedlist.h"
#include "particleSystem.h"

//File Name: particleSystem.cc

ParticleSystem mainParticleSystem;

void PartSystems.loadParticals(Node* firstParticle){
   for(Node* currentParticle = firstParticle; currentParticle != nullptr; currentParticle = currentParticle -> next){
	mainParticleSystem->add(currentParticle); //Add each particle to the particles list
   }
}

void PartSystems::drawParticles(){ //First element in LL so we can loop thru the rest
   for(int i = 0; i < mainParticlesSystem->size();i++)){
	 currentParticle->draw(); //calling the draw() method on particle as listed in particle.h
   }
}

void PartSystems::moveParticles(Node* firstParticle,double newdx, double, newdy){ //I am going to assume that move means we are moving with gravity.
  //Function paramater: the first element in LL because we need to move them all not just one. We need to go over the list.


}



