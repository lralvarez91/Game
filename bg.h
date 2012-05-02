#ifndef BG_H
#define BG_H

#include <QImage>
#include <QRect>

class Bg
{

public:
 Bg();
~Bg();

public:
    void resetState();	//spawn
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

    QImage image;
    QRect rect;
    int position;

};

#endif

