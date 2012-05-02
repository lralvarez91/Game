#include "boss.h"
#include <iostream>

Boss::Boss()
{

xdir = -5;	//start moving right 1 pixel at a time
  ydir = 0;	//start moving down 1 pixel at a time

image.load("ganonu.png");	//load image

rect=image.rect(); //assign image
resetState(); //spawn
}

Boss::~Boss(){
std::cout<<("Boss deleted\n");
}

void Boss::resetState()
{
rect.moveTo(300,29); //location
image.load("ganonu.png");
}

QRect Boss::getRect()
{
  return rect;
}

QImage & Boss::getImage()
{
  return image;
}

void Boss::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Boss::moveTop(int top)
{
  rect.moveTop(top);
}

void Boss::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Boss::moveRight(int right)
{
  rect.moveRight(right);
}


void Boss::autoMove()	//checks if Boss hits the window edge and "bounces" back
{
  rect.translate(xdir, ydir);

  if ((rect.left() <= 0) || (rect.right() ==0)) {	//if hit left edge, move right
    xdir = 5;
  }

  if ((rect.right() >= 1200) || (rect.left() ==800)){ //if hit right edge, move left
    xdir = -5;
  }

  if (rect.top() == 0) { //if hit top edge, move down
    ydir = 0;
  }
  
  if (rect.bottom() == 800) { //if hit bottom edge, move up
    ydir= 0;
}
}

void Boss::setXDir(int x)
{
  xdir = x;
}

void Boss::setYDir(int y)
{
  ydir = y;
}

int Boss::getXDir()
{
  return xdir;
}

int Boss::getYDir()
{
  return ydir;
}
