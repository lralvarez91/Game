#ifndef BOSSWEAPON_H
#define BOSSWEAPON_H

#include <QImage>
#include <QRect>

class BossWeapon
{

public:
 BossWeapon();
~BossWeapon();

public:
    void resetState();	//spawn
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();


void autoMove();	//handles automatic movement
    void setXDir(int); //handles whether object moves right or left
    void setYDir(int); //handles whether object moves up or down
    int getXDir(); //gets value
    int getYDir(); //gets value





  //protected:
    QImage image;
    QRect rect;
    int position,xdir,ydir;

};

#endif

