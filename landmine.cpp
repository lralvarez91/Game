#include "landmine.h"
#include <iostream>

Landmine::Landmine(int x,int y)
{
image.load("landmine.png");	//loads image
rect = image.rect();	//assigns image
	
}

Landmine::~Landmine() {

   std::cout << ("Landmine deleted\n");
}

void Landmine::resetState()
{
rect.moveTo(850,800);	//spawn location
}

QRect Landmine::getRect()
{
  return rect;
}

void Landmine::setRect(QRect rct)
{
  rect = rct;
}

QImage & Landmine::getImage()
{
  return image;
}
