#ifndef LANDMINE_H
#define LANDMINE_H

#include <QImage>
#include <QRect>

class Landmine
{

public:
 Landmine(int,int);
~Landmine();

public:
    void resetState();	//spawn
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

  //private:
    QImage image;
    QRect rect;
    int position;

};

#endif

