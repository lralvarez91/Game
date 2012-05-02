#include "car.h"
#include <iostream>

Car::Car()
{
xdir=-5; //moves left
ydir=0;  //doesnt move up or down

image.load("zomcar.png");
rect=image.rect();	//assigns image to object
resetState();		//respawn
}

Car::~Car()
{
std::cout<<("Car deleted\n");
}

void Car::resetState()
{
rect.moveTo(410,495);	//respawn location
}

QRect Car::getRect()
{
  return rect;
}

QImage & Car::getImage()
{
  return image;
}

void Car::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.right() <= 0) {	//if object moves to edge of screen or off screen
    xdir = -5;
						//change image to simulate other Cars
rect.moveTo(1200,495);		//move and move in other direction
  }
}


void Car::setXDir(int x)
{
  xdir = x;
}

void Car::setYDir(int y)
{
  ydir = y;
}

int Car::getXDir()
{
  return xdir;
}

int Car::getYDir()
{
  return ydir;
}

