#include "zombie3.h"
#include <iostream>

Zombie3::Zombie3()
{
xdir = 0;
  ydir = 5;

image.load("zombie3.png");//load image

rect=image.rect();//assign image
resetState();//respawn
}

Zombie3::~Zombie3(){
std::cout<<("Zombie3 deleted\n");
}

void Zombie3::resetState()
{
rect.moveTo(800,100);//location
}


void Zombie3::autoMove()//checks if zombie hits the window edge and "bounces" back
{
  rect.translate(xdir, ydir);

  if (rect.top() <= 0) { //if hit top edge, move down
    ydir = 5;
  }
  
  if (rect.bottom() >= 1000) { //if hit bottom edge, move up
    ydir= -5;
}
}


