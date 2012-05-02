#include "civilian.h"
#include <iostream>

Civilian::Civilian()
{
xdir=-5; //moves left
ydir=0;  //doesnt move up or down

image.load("civilian.png");
rect=image.rect();	//assigns image to object
resetState();		//respawn
}

Civilian::~Civilian()
{
std::cout<<("Civilian deleted\n");
}

void Civilian::resetState()
{
rect.moveTo(400,300);	//respawn location
}

QRect Civilian::getRect()
{
  return rect;
}

QImage & Civilian::getImage()
{
  return image;
}

void Civilian::autoMove()
{
  rect.translate(xdir, ydir);

  if ((rect.left() <= 0) || (rect.right() <= 0)){	//if object moves to edge of screen or off screen
    xdir = 5;
image.load("civilian2.png");						//change image to simulate other civilians
rect.moveTo(10,20);		//move and move in other direction
  }

	if ((rect.right() >= 1200) || (rect.left() >= 1200)) { //if object moves to edge of screen or off screen
    xdir = -5;
image.load("civilian.png");		//change image again
rect.moveTo(1100,700);
  }
}

void Civilian::setXDir(int x)
{
  xdir = x;
}

void Civilian::setYDir(int y)
{
  ydir = y;
}

int Civilian::getXDir()
{
  return xdir;
}

int Civilian::getYDir()
{
  return ydir;
}

