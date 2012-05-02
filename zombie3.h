#ifndef ZOMBIE3_H
#define ZOMBIE3_H

#include <QImage>
#include <QRect>
#include "zombie.h"

class Zombie3:public Zombie
{

public:
    Zombie3();
    ~Zombie3();

public:
    void resetState();//spawn location

	void autoMove();	//handles automatic movement
    
};

#endif

