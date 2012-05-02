#ifndef PLAYER_H
#define PLAYER_H

#include <QImage>
#include <QRect>


class Player
{

public:
    Player();
    ~Player();

public:
    void resetState();	//spawn
    void moveBottom(int);	//move down
    void moveTop(int);	//move up
    void moveLeft(int);	//move left
    void moveRight(int); //move right
    QRect getRect();
    QImage & getImage();

  //private:
    QImage image;
    QRect rect;

};

#endif

