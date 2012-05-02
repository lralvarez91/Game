#include "pshot.h"
#include <iostream>

Pshot::Pshot()
{
xdir = 0;
  ydir = 0;

image.load("pshot.png");//load image

rect=image.rect();//assign image
resetState();//respawn
}

Pshot::~Pshot(){
std::cout<<("Pshot deleted\n");
}

void Pshot::resetState()
{
rect.moveTo(800,100);//location
}

QRect Pshot::getRect()
{
  return rect;
}

QImage & Pshot::getImage()
{
  return image;
}

void Pshot::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Pshot::moveTop(int top)
{
  rect.moveTop(top);
}


void Pshot::autoMove()//checks if zombie hits the window edge and "bounces" back
{
  rect.translate(xdir, ydir);
}

void Pshot::setXDir(int x)
{
  xdir = x;
}

void Pshot::setYDir(int y)
{
  ydir = y;
}

int Pshot::getXDir()
{
  return xdir;
}

int Pshot::getYDir()
{
  return ydir;
}
