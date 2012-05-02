#ifndef ZOMGAME_H
#define ZOMGAME_H

#include "player.h"	//includes all classes of the objects
#include "zombie.h"
#include "civilian.h"
#include "landmine.h"
#include "zombie2.h"
#include "life.h"
#include "switch.h"
#include "zombie3.h"
#include "car2.h"
#include "shooter.h"
#include "shot.h"
#include "pshot.h"
#include "boss.h"
#include "bossweapon.h"
#include "bg.h"
#include "car.h"
#include <QWidget>
#include <QKeyEvent>	//handles actions for specific user input

class Zomgame: public QWidget
{

Q_OBJECT

public:
Zomgame(QWidget *parent = 0);
~Zomgame();

protected:
    void paintEvent(QPaintEvent *event);	
    void timerEvent(QTimerEvent *event);	
    void keyPressEvent(QKeyEvent *event);	

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();
    

  private:
    int x;
    int timerId;
    int timerId2;
    Player *player;			//player object
    Landmine *landmine;		//landmine object
    Landmine *l2,*l3,*l4,*l5,*l6,*l7,*l8,*l9,*l10;
    Life *s,*s2,*s3,*s4;

    Car *car,*car2,*zcar,*car4;
    Car2 *car3,*ncar;
    Zombie *zombie;			//zombie object
    Zombie2 *zombie2;		//zombie2 object
    Zombie3 *zombie3,*z3,*z4;		//zombie3 object
    Bg *bg,*bg2;
    Switch *b,*b2,*b3,*b4,*b5,*b6;

    Shooter *sh1,*sh2,*sh3,*sh4;
    Shot *bullet1, *bullet2, *bullet3, *bullet4;
    Pshot *pshot;

    Civilian *civilian;		//civivilian object
    Boss *boss;
    BossWeapon *axe;

    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    bool level1;
    bool level2;
    bool level3;
    bool level4;
};

#endif
