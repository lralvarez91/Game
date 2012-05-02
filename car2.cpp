#include "car2.h"
#include <iostream>

Car2::Car2()
{
xdir=30; //moves left
ydir=0;  //doesnt move up or down

image.load("car2.png");
rect=image.rect();	//assigns image to object
resetState();		//respawn
}

Car2::~Car2()
{
std::cout<<("Car2 deleted\n");
}

void Car2::resetState()
{
rect.moveTo(-1000,270);	//respawn location
}

void Car2::autoMove()
{

  rect.translate(xdir, ydir);

  if (rect.left() >= 1200) {	//if object moves to edge of screen or off screen
    xdir=30;
					//change image to simulate other Car2s
rect.moveTo (-1000,270);		//move and move in other direction
  }
}


