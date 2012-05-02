#include "switch.h"
#include <iostream>

Switch::Switch():Life()
{
Life::image.load("button.png");	//loads image
Life::rect = image.rect();	//assigns image	
}

Switch::~Switch() {

   std::cout << ("Switch deleted\n");
}

