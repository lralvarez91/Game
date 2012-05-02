#include "shooter.h"
#include <iostream>

Shooter::Shooter()
{
xdir = 0;
  ydir = 5;

image.load("shooter.png");//load image

rect=image.rect();//assign image
resetState();//respawn
}

Shooter::~Shooter(){
std::cout<<("Shooter deleted\n");
}

void Shooter::resetState()
{
rect.moveTo(-1000,100);//location
}

QRect Shooter::getRect()
{
  return rect;
}

QImage & Shooter::getImage()
{
  return image;
}

void Shooter::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Shooter::moveTop(int top)
{
  rect.moveTop(top);
}


void Shooter::autoMove()//checks if zombie hits the window edge and "bounces" back
{
  rect.translate(xdir, ydir);

}

void Shooter::setXDir(int x)
{
  xdir = x;
}

void Shooter::setYDir(int y)
{
  ydir = y;
}

int Shooter::getXDir()
{
  return xdir;
}

int Shooter::getYDir()
{
  return ydir;
}
