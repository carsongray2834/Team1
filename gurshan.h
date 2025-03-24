#include <iostream> //debugging via cout / cerr (if needed)
#include "particleSystem.h" // meant for particle movement, drawing, and physics, has litterally all of the #includes we need such as graphics.h
#include <ctime> // meant to manage framerate
#include <cstdlib> // RNG (random number generation) 

const Color faucetGrey = {100,100,100};
const Color waterBlue = {0,150,255};
const Color explosionRed = {240,60,60};

const int rectWidth = 30;
const int rectHeight = 45;

ParticleSystem myMainParticleSystem(75, 90);

//myMainParticleSystem.set_rows(75);
//myMainParticleSystem.set_columns(90);



void drawFaucet(){
 // ParticleGraphics::drawRect(50,0,rectWidth,rectHeight); 
}

void startDripping(){

}



