#include "zombie2.h"
#include <iostream>

Zombie2::Zombie2()
{
xdir = -5; //start moving 5 pixels left
  ydir = 5; //start moving 5 pixels up

image.load("zombie2.png"); //load image

rect=image.rect();//assign image
resetState();//spawn
}

Zombie2::~Zombie2(){
std::cout<<("Zombie2 deleted\n");
}

void Zombie2::resetState()
{
rect.moveTo(400,100); //location
}


void Zombie2::autoMove()	//checks if zombie hits the window edge and "bounces" back
{
	rect.translate(xdir, ydir);
	
	if ((rect.left() <= 0) || (rect.right() <= 0)) {	//if hit left edge, move right
		xdir = 3;
	}
	
	if ((rect.right() >= 1200) || (rect.left() >= 1200)){ //if hit right edge, move left
		xdir = -3;
	}
	
	if (rect.top() <= 0) { //if hit top edge, move down
		ydir = 3;
	}
	
	if (rect.bottom() >= 1000) { //if hit bottom edge, move up
		ydir= -5;
	}
}

