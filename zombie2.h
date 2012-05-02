#ifndef ZOMBIE2_H
#define ZOMBIE2_H

#include <QImage>
#include <QRect>
#include "zombie.h"

class Zombie2:public Zombie
{

public:
    Zombie2();
    ~Zombie2();

void resetState();// spawn location
void autoMove();	//handles automatic movement

};

#endif

