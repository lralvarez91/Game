#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QImage>
#include <QRect>


class Zombie
{

public:
    Zombie();
    ~Zombie();

public:
    void resetState(); //spawn location
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);

	void autoMove();	//handles automatic movement
    void setXDir(int); //handles whether object moves right or left
    void setYDir(int); //handles whether object moves up or down
    int getXDir(); //gets value
    int getYDir(); //gets value
    QRect getRect();
    QImage & getImage();

  //private:
    QImage image;
    QRect rect;
    int xdir,ydir;

};

#endif

