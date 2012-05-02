#include "life.h"
#include <iostream>

Life::Life():Civilian()
{
Civilian::image.load("life.png");	//loads image
Civilian::rect = image.rect();	//assigns image	
}

Life::~Life() {

   std::cout << ("Life deleted\n");
}

