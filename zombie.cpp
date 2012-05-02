#include "zombie.h"
#include <iostream>

Zombie::Zombie()
{

xdir = 4;	//start moving right 1 pixel at a time
  ydir = -0;	//start moving down 1 pixel at a time

image.load("zombie.png");	//load image

rect=image.rect(); //assign image
resetState(); //spawn
}

Zombie::~Zombie(){
std::cout<<("Zombie deleted\n");
}

void Zombie::resetState()
{
rect.moveTo(500,500); //location
}

QRect Zombie::getRect()
{
  return rect;
}

QImage & Zombie::getImage()
{
  return image;
}

void Zombie::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Zombie::moveTop(int top)
{
  rect.moveTop(top);
}

void Zombie::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Zombie::moveRight(int right)
{
  rect.moveRight(right);
}


void Zombie::autoMove()	//checks if zombie hits the window edge and "bounces" back
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {	//if hit left edge, move right
    xdir = 4;
  }

  if (rect.right() >= 1200) { //if hit right edge, move left
    xdir = -4;
  }

  if (rect.top() <= 0) { //if hit top edge, move down
    ydir = 0;
  }
  
  if (rect.bottom() >= 1000) { //if hit bottom edge, move up
    ydir= -0;
}
}

void Zombie::setXDir(int x)
{
  xdir = x;
}

void Zombie::setYDir(int y)
{
  ydir = y;
}

int Zombie::getXDir()
{
  return xdir;
}

int Zombie::getYDir()
{
  return ydir;
}
