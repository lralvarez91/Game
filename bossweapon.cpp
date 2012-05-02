#include "bossweapon.h"
#include <iostream>

BossWeapon::BossWeapon()
{
image.load("axe.png");	//loads image
rect = image.rect();	//assigns image
resetState();

xdir = -0;	//start moving right 1 pixel at a time
  ydir = 0;	//start moving down 1 pixel at a time
}

BossWeapon::~BossWeapon() {

   std::cout << ("BossWeapon deleted\n");
}

void BossWeapon::resetState()
{
rect.moveTo(-200,-200);	//spawn location
image.load("axe.png");
}

QRect BossWeapon::getRect()
{
  return rect;
}

void BossWeapon::setRect(QRect rct)
{
  rect = rct;
}

QImage & BossWeapon::getImage()
{
  return image;
}

void BossWeapon::setXDir(int x)
{
  xdir = x;
}

void BossWeapon::setYDir(int y)
{
  ydir = y;
}

int BossWeapon::getXDir()
{
  return xdir;
}

int BossWeapon::getYDir()
{
  return ydir;
}


void BossWeapon::autoMove()	//checks if Boss hits the window edge and "bounces" back
{
  rect.translate(xdir, ydir);

  if (rect.bottom() >= 600){// || (rect.right() ==0)) {	//if hit left edge, move right
image.load("axe2.png");    
ydir = 4;
  }

  if (rect.bottom() >= 650){// || (rect.left() ==800)){ //if hit right edge, move left
    ydir = 4;
image.load("axe3.png");
  }

   if (rect.bottom() >= 700){// || (rect.left() ==800)){ //if hit right edge, move left
    ydir = 4;
image.load("axe4.png");
  }
}
