#include "shot.h"
#include <iostream>

Shot::Shot()
{
xdir = 0;
  ydir = 0;

image.load("bullet1.png");//load image

rect=image.rect();//assign image
resetState();//respawn
}

Shot::~Shot(){
std::cout<<("Shot deleted\n");
}

void Shot::resetState()
{
rect.moveTo(800,100);//location
}

QRect Shot::getRect()
{
  return rect;
}

QImage & Shot::getImage()
{
  return image;
}

void Shot::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Shot::moveTop(int top)
{
  rect.moveTop(top);
}


void Shot::autoMove()//checks if zombie hits the window edge and "bounces" back
{
  rect.translate(xdir, ydir);
}

void Shot::setXDir(int x)
{
  xdir = x;
}

void Shot::setYDir(int y)
{
  ydir = y;
}

int Shot::getXDir()
{
  return xdir;
}

int Shot::getYDir()
{
  return ydir;
}
