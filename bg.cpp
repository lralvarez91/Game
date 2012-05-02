#include "bg.h"
#include <iostream>

Bg::Bg()
{
image.load("racetrack.png");	//loads image
rect = image.rect();	//assigns image

}

Bg::~Bg() {

   std::cout << ("Bg deleted\n");
}

void Bg::resetState()
{
rect.moveTo(0,15);	//spawn location
}

QRect Bg::getRect()
{
  return rect;
}

void Bg::setRect(QRect rct)
{
  rect = rct;
}

QImage & Bg::getImage()
{
  return image;
}
