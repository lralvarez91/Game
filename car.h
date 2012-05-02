#ifndef CAR_H
#define CAR_H

#include <QImage>
#include <QRect>


class Car
{
public:
    Car(); //constructor
    ~Car(); //destructor

public:
    void resetState();// initial location
    void moveLeft(int);
    void moveRight(int);
    QRect getRect();
    QImage & getImage();

void autoMove();	//handles automatic movement
    void setXDir(int); //handles whether object moves right or left
    void setYDir(int); //handles whether object moves up or down
    int getXDir(); //gets value
    int getYDir(); //gets value

  //private:
    QImage image;
    QRect rect;
	int xdir,ydir;
	

};

#endif

