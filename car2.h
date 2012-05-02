#ifndef Car2_H
#define Car2_H

#include <QImage>
#include <QRect>
#include "car.h"

class Car2:public Car
{
public:
    Car2(); //constructor
    ~Car2(); //destructor

public:
    void resetState();// initial location
void autoMove();	//handles automatic movement
    

};

#endif

