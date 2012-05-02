#include "player.h"
#include <iostream>

Player::Player()
{

image.load("player.png");	//load image

rect=image.rect();	//assign image
resetState();	//spawn/respawn
}

Player::~Player(){
std::cout<<("Player deleted\n");
}

void Player::resetState()
{
rect.moveTo(1100,900);	//spawn respawn location
}

QRect Player::getRect()
{
  return rect;
}

QImage & Player::getImage()
{
  return image;
}


void Player::moveLeft(int left)
{
    rect.moveTo(left, rect.top());
}

void Player::moveRight(int right)
{
    rect.moveTo(right, rect.top());
}

void Player::moveBottom(int bottom)
{
rect.moveBottom(bottom);
}

void Player::moveTop(int top)
{
  rect.moveTop(top);
}

