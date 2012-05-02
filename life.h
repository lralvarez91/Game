#ifndef LIFE_H
#define LIFE_H

#include <QImage>
#include <QRect>
#include "civilian.h"

class Life: public Civilian
{

public:
 Life();
~Life();

   //void resetState();// initial location

};

#endif

