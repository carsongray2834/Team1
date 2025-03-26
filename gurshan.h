#include <iostream> //debugging via cout / cerr (if needed)
#include "particleSystem.h" // meant for particle movement, drawing, and physics, has litterally all of the #includes we need such as graphics.h
#include <ctime> // meant to manage framerate
#include <cstdlib> // RNG (random number generation) 

const Color faucetGrey = {100,100,100};
const Color waterBlue = {0,150,255};
const Color explosionRed = {240,60,60};

const int rectWidth = 60;
const int rectHeight = 10;
const int waterOffset = 1;



void drawFaucet(ParticleSystem particleSys){
   particleSys.set_color(faucetGrey);
   particleSys.drawRect(0,rectWidth,rectHeight,5);
   
}

void startDripping(ParticleSystem particleSys){
	std::cout << std::endl;
	std::cout << "Insert dripping here" << std::endl;
}

void compileShenanigans(){

	auto [rows, columns] = get_terminal_size();

	ParticleSystem mainParticleSystem(rows,columns);

	show_cursor(false);

	clearscreen();

	drawFaucet(mainParticleSystem);
    startDripping(mainParticleSystem);

	clearscreen();
	show_cursor(true);

}



