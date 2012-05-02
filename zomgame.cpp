#include "zomgame.h"
#include <QPainter>
#include <QApplication>

QString scores;	//QString objects
QString life;	
QString shot;
QString bosshp;
int lives=25;	//global variables
int score=0;	
int shots=30;
int bosslife=500;

//constructor turns gameover and game win screens, turns off pause and gamestart, opens the game window and creates objects
Zomgame::Zomgame(QWidget *parent)
    : QWidget(parent)
{
  x = 0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  level1=FALSE;
  level2=FALSE;
  level3=FALSE;
  level4=FALSE;
	
//these pieces of code create objects of type player, zombie, zombie2, zombie3, landmine,landmine2, and civilian
player = new Player();

car=new Car();
car2=new Car();
zcar=new Car();
car4=new Car();
car3=new Car2();
ncar=new Car2();

s=new Life();
s2=new Life();
s3=new Life();
s4=new Life();

b=new Switch();
b2=new Switch();
b3=new Switch();
b4=new Switch();
b5=new Switch();
b6=new Switch();

sh1=new Shooter();
sh2=new Shooter();
sh3=new Shooter();
sh4=new Shooter();

bullet1=new Shot();
bullet2=new Shot();
bullet3=new Shot();
bullet4=new Shot();
pshot=new Pshot();

landmine= new Landmine(700,50);
l2=new Landmine(50,50);
l3=new Landmine(50,50);
l4=new Landmine(50,50);
l5=new Landmine(50,50);
l6=new Landmine(50,50);
l7=new Landmine(50,50);
l8=new Landmine(50,50);
l9=new Landmine(50,50);
l10=new Landmine(50,50);

civilian= new Civilian();

zombie=new Zombie();
zombie2= new Zombie2();
zombie3= new Zombie3();
z3=new Zombie3();
z4=new Zombie3();

bg=new Bg();
bg2=new Bg();

boss= new Boss();

axe= new BossWeapon();
	
}

//This destructor deletes all objects when player chooses to quit the game
Zomgame::~Zomgame() {


delete player;
delete car;
delete car2;
delete car3;
delete zcar;
delete car4;
delete ncar;
delete s;
delete s2;
delete s3;
delete s4;
delete b;
delete b2;
delete b3;
delete b4;
delete b5;
delete b6;
delete sh1;
delete sh2;
delete sh3;
delete sh4;
delete bullet1;
delete bullet2;
delete bullet3;
delete bullet4;
delete pshot;
delete zombie;
delete landmine;
delete l2;
delete l3;
delete l4;
delete l5;
delete l6;
delete l7;
delete l8;
delete l9;
delete l10;
delete civilian;
delete zombie2;
delete zombie3;
delete z3;
delete z4;
delete bg;
delete bg2;
delete boss;
delete axe;

}

//this function draws everything that is a part of the game
void Zomgame::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

	
  if (gameOver) {	//initializes Game over message
    QFont font("Courier", 15, QFont::Black);//DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("FAIL");
    //int textHeight= fm.height("FAIL");

    painter.setFont(font);
    int h = height();//keeps track of hight in message
    int w = width();//keeps track of width

	  //moves game over message and prints it relatively close to center
    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2-200, 5, "Press R key to Restart or Esc to Quit"); 
    painter.drawText(-125,-10,"You Died. Game Over.");
  }
	
	//same as gameOver only winning message
  else if(gameWon) {
    QFont font("Courier", 15, QFont::Black);
    QFontMetrics fm(font);
    int textWidth = fm.width("YOU WIN");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-250, 5, "Press R key to Restart or Esc to Quit");
    painter.drawText(-110,-10,"You Win the Game.");
  }
  else {
    QFont font("Courier", 15, QFont::Black);
    QFontMetrics fm(font);
    painter.setFont(font);
    int h = height();
    int w = width();

   //prints score counter on top of the screen	  
scores.setNum(score);
painter.drawText(300,15,"Score:");
painter.drawText(390,15,scores);

//prints life counter at the top of the screen
life.setNum(lives);
    painter.drawText(100,15,"lives:");
    painter.drawText(190,15,life);

//rules for level 3
if(level3==TRUE){
shot.setNum(shots);
	painter.drawText(700,15,"Dodge this many shots!:");
	painter.drawText(1000,15,shot);
}

//rules for level 3
if(level4==TRUE){
bosshp.setNum(bosslife);
	painter.drawText(700,15,"KILL THE BOSS!      HP:");
	painter.drawText(1000,15,bosshp);
}

	  //gets and displays certain objects images on the game screen depending on what level is currently running
if(level3==TRUE){
painter.drawImage(bg2->getRect(),	//certain background during later levels but order of painting matters
 bg2->getImage());					//placed here so that bg doesn't cover other objects
}

if(level2==TRUE){
painter.drawImage(bg->getRect(),
  bg->getImage());

painter.drawImage(car->getRect(),
  car->getImage());
painter.drawImage(car2->getRect(),
  car2->getImage());
painter.drawImage(car3->getRect(),
  car3->getImage());
painter.drawImage(car4->getRect(),
  car4->getImage());
painter.drawImage(ncar->getRect(),
  ncar->getImage());
painter.drawImage(zcar->getRect(),
  zcar->getImage());


painter.drawImage(s->getRect(),
  s->getImage());
painter.drawImage(s2->getRect(),
  s2->getImage());
painter.drawImage(s3->getRect(),
  s3->getImage());
painter.drawImage(s4->getRect(),
  s4->getImage());
painter.drawImage(b->getRect(),
  b->getImage());
painter.drawImage(b2->getRect(),
  b2->getImage());
painter.drawImage(b3->getRect(),
  b3->getImage());
painter.drawImage(b4->getRect(),
  b4->getImage());
painter.drawImage(b5->getRect(),
  b5->getImage());
painter.drawImage(b6->getRect(),
  b6->getImage());
}


 painter.drawImage(player->getRect(), //player always on screen
      player->getImage());

if(level1==TRUE){

    painter.drawImage(civilian->getRect(), 
      civilian->getImage());
   painter.drawImage(zombie->getRect(), 
     zombie->getImage());
   painter.drawImage(zombie2->getRect(),
     zombie2->getImage());
   painter.drawImage(zombie3->getRect(),
     zombie3->getImage());
   painter.drawImage(z3->getRect(),
     z3->getImage());
painter.drawImage(z4->getRect(),
    z4->getImage());


   painter.drawImage(landmine->getRect(), 
     landmine->getImage());
 painter.drawImage(l2->getRect(), 
     l2->getImage());
 painter.drawImage(l3->getRect(), 
     l3->getImage());
 painter.drawImage(l4->getRect(), 
     l4->getImage());
 painter.drawImage(l5->getRect(), 
     l5->getImage());
 painter.drawImage(l6->getRect(), 
     l6->getImage());
 painter.drawImage(l7->getRect(), 
     l7->getImage());
 painter.drawImage(l8->getRect(), 
     l8->getImage());
 painter.drawImage(l9->getRect(), 
     l9->getImage());
 painter.drawImage(l10->getRect(), 
     l10->getImage());
}
   
if(level3==TRUE){
   painter.drawImage(sh1->getRect(), 
     sh1->getImage());
 painter.drawImage(sh2->getRect(), 
     sh2->getImage());
 painter.drawImage(sh3->getRect(), 
     sh3->getImage());
 painter.drawImage(sh4->getRect(), 
     sh4->getImage());
painter.drawImage(bullet1->getRect(), 
     bullet1->getImage());
painter.drawImage(bullet2->getRect(), 
     bullet2->getImage());
painter.drawImage(bullet3->getRect(), 
     bullet3->getImage());
painter.drawImage(bullet4->getRect(), 
     bullet4->getImage());
}

if(level4==TRUE){
painter.drawImage(boss->getRect(),
  boss->getImage());
painter.drawImage(axe->getRect(),
  axe->getImage());
painter.drawImage(pshot->getRect(),
  pshot->getImage());
}
    }
  }


//handles the automatically moving zombies and tells them to start moving
void Zomgame::timerEvent(QTimerEvent *event)
{
  zombie->autoMove();
  zombie2->autoMove();
  zombie3->autoMove();
  z3->autoMove();

  civilian->autoMove();

boss->autoMove();

if(level2==TRUE){	//certain objects allowed to start moving automatically once their level starts
car->autoMove();
car2->autoMove();
car2->image.load("zomcar2.png");
if( (car2->getRect().right() >1200)) { car2->rect.moveTo(0,600);}
car3->autoMove();
car4->autoMove();
car4->image.load("zomcar2.png");
car4->xdir=5;
zcar->autoMove();

ncar->autoMove();

}

if(level3==TRUE){
bullet1->autoMove();
bullet1->ydir=16;
bullet2->autoMove();
bullet2->xdir=16;
bullet3->autoMove();
bullet3->ydir=-16;
bullet4->autoMove();
bullet4->xdir=-16;
}
pshot->autoMove();
pshot->ydir=-15;

  checkCollision();
  repaint();
}



//if game starts/restarts, everything starts at their initial positions
void Zomgame::startGame()
{ 
  if(!gameStarted) {
    player->resetState();//reset position for this object
car->resetState();
car2->rect.moveTo(0,600);
car2->image.load("zomcar2.png");
car2->xdir=5;
car3->resetState();
car4->rect.moveTo(200,370);
zcar->rect.moveTo(150,265);
ncar->rect.moveTo(-1000,725);


s->rect.moveTo(100,100);
s2->rect.moveTo(170,100);
s3->rect.moveTo(240,100);
s4->rect.moveTo(1050,100);
s4->image.load("life.png");

b->rect.moveTo(500,100);
b2->rect.moveTo(-300,-300);
b3->rect.moveTo(-300,-300);
b4->rect.moveTo(-300,-300);
b5->rect.moveTo(-300,-300);
b6->rect.moveTo(950,100);
b6->image.load("button5.png");

sh1->rect.moveTo(550,-5);	//shooter objects placed on sides of screen
sh2->rect.moveTo(0,450);
sh2->image.load("shooter2.png");
sh3->rect.moveTo(550,880);
sh3->image.load("shooter3.png");
sh4->rect.moveTo(1080,450);
sh4->image.load("shooter4.png");

bullet2->image.load("bullet2.png");
bullet3->image.load("bullet3.png");
bullet4->image.load("bullet4.png");
pshot->image.load("pshot.png");

int S1B= sh1->getRect().bottom();	//positions of shooter objects found
int S1L= sh1->getRect().left();
int S2R= sh2->getRect().right();
int S2T= sh2->getRect().top();
int S3T= sh3->getRect().top();
int S3L= sh3->getRect().left();
int S4L= sh4->getRect().left();
int S4B= sh4->getRect().bottom();
int PL= player->getRect().left();
int PT= player->getRect().top();

bullet1->rect.moveTo(S1L+20,S1B-100);	//shooter bullets come from the wherever the object is
bullet2->rect.moveTo(S2R-100,S2T+20);
bullet3->rect.moveTo(S3L+20,S3T);
bullet4->rect.moveTo(S4L,S4B-100);
pshot->rect.moveTo(PL,PT);

zombie->resetState();
landmine->resetState();
civilian->resetState();
zombie2->resetState();
zombie3->resetState();
boss->resetState();
axe->resetState();
z3->rect.moveTo(300,100); //zombie3 double
z4->rect.moveTo(600,200); //follower zombie

l2->rect.moveTo(250,200);
l3->rect.moveTo(250,400);
l4->rect.moveTo(250,600);
l5->rect.moveTo(250,800);
l6->rect.moveTo(850,200);
l7->rect.moveTo(850,400);
l8->rect.moveTo(850,600);
l9->image.load("landmine2.jpg");
l9->rect.moveTo(950,150);
l10->image.load("landmine2.jpg");
l10->rect.moveTo(150,150);

bg->resetState();
bg2->resetState();

    gameOver = FALSE; 
    gameWon = FALSE; 
    gameStarted = TRUE;
level1=TRUE;
level2=FALSE;
level3=FALSE;
level4=FALSE;
    timerId = startTimer(5);  

  }
}


void Zomgame::pauseGame()
{
  if (paused) {
    timerId = startTimer(1);//if already paused, unpause after 5 milliseconds
    paused = FALSE;
  } else {
    paused = TRUE;//pause game
    killTimer(timerId); 
   }
}

//if player loses all their lives, stop auto moving objects, and show gameOver message
void Zomgame::stopGame()
{
  killTimer(timerId);    
  gameOver = TRUE;      
  gameStarted = FALSE;
}

//if player saves all civilians, stop auto moving objects and show victory message
void Zomgame::victory()
{
  killTimer(timerId);
  gameWon = TRUE;  
  gameStarted = FALSE;
}


//checks positions of objects and if they collide
void Zomgame::checkCollision()
{

//swapping from top-bottom, left-right vice versa
if(level2 != TRUE){

int top=  player->getRect().top();
int left= player->getRect().left();

if (player->rect.left() <= 0) {	//if hit left edge, move right
    player->rect.moveTo(1185,top);
  }

  if (player->rect.left() >= 1200){ //if hit right edge, move left
   player->rect.moveTo(15,top);
  }

  if (player->rect.top() <= 0) { //if hit top edge, move down
  player->rect.moveTo(left,985);
  }
  
  if (player->rect.top() >= 1000) { //if hit bottom edge, move up
   player->rect.moveTo(left,10);
}

}

//no swapping in level 2, played a bit like frogger
if(level2==TRUE){
int top=  player->getRect().top();
int left= player->getRect().left();
if (player->rect.left() <= 0) {	//if hit left edge, move right
    player->rect.moveTo(30,top);
  }

  if (player->rect.left() >= 1200){ //if hit right edge, move left
   player->rect.moveTo(1170,top);
  }

  if (player->rect.top() <= 0) { //if hit top edge, move down
  player->rect.moveTo(left,30);
  }
  
  if (player->rect.top() >= 1000) { //if hit bottom edge, move up
   player->rect.moveTo(left,970);
}

}


 if(level1==TRUE){

//following zombie, finds and moves towards player at all times
z4->image.load("follower.png");
z4->autoMove();
if(z4->rect.left() < player->rect.left())   {
z4->xdir=2;}
if(z4->rect.right() > player->rect.right())   {
z4->xdir=-2;}
if(player->rect.bottom() < z4->getRect().bottom()) z4->ydir=-2;
if(player->rect.top() > z4->getRect().top()) z4->ydir=2;



	//player hits  zombies
  if ( (player->getRect()).intersects(zombie->getRect()) ||(player->getRect()).intersects(zombie2->getRect()) || (player->getRect()).intersects(zombie3->getRect()) || (player->getRect()).intersects(z3->getRect()) || (player->getRect()).intersects(z4->getRect())) {

    player->resetState(); //respawn player
    lives--;//subtract life
    score-=50;//subtract score
 
}
	
//player and landmine
if ( (player->getRect()).intersects(landmine->getRect()) || (player->getRect()).intersects(l2->getRect()) || (player->getRect()).intersects(l3->getRect()) || (player->getRect()).intersects(l4->getRect()) || (player->getRect()).intersects(l5->getRect()) ||  (player->getRect()).intersects(l6->getRect())|| (player->getRect()).intersects(l7->getRect()) || (player->getRect()).intersects(l8->getRect()) || (player->getRect()).intersects(l9->getRect()) || (player->getRect()).intersects(l10->getRect())) {
 
    player->resetState();
lives--;
score-=50;
 

}

//player and civilian
if ( (player->getRect()).intersects(civilian->getRect())) {

    civilian->resetState();//respawn civilian
score+=100;//add score

}

 if(score>=500){ level2=TRUE;//if score at 500, level 1 complete, level 2 start, player start at new location
player->rect.moveTo(600,1000);
level1=FALSE;}
}



if(level2==TRUE){		//buttons initialize unpressed image
b->image.load("button.png");
b2->image.load("button.png");
b3->image.load("button.png");
b4->image.load("button.png");




if( (player->getRect()).intersects(s->getRect()) ){		//few life objects add to players lives

s->rect.moveTo(-200,-200);
lives++;
}
if( (player->getRect()).intersects(s2->getRect()) ){

s2->rect.moveTo(-200,-200);
lives++;
}

if( (player->getRect()).intersects(s3->getRect()) ){

s3->rect.moveTo(-200,-200);
lives++;
}


if( (player->getRect()).intersects(b->getRect()) ){	//player hits a button to spawn a new one

b->image.load("button2.png");	//when player is on button, a "pressed" image will load, simulates really touching a button
b2->rect.moveTo(700,900);
}
if( (player->getRect()).intersects(b2->getRect()) ){

b2->image.load("button2.png");
b3->rect.moveTo(500,500);
}
if(ncar->rect.right() > 1200){ncar->rect.moveTo(-1000,725);}

if( (player->getRect()).intersects(b3->getRect()) ){

b3->image.load("button2.png");
b4->rect.moveTo(300,30);
}
if(zcar->rect.left() <= 0){zcar->rect.moveTo(1170,265);}

if( (player->getRect()).intersects(b4->getRect()) ){	

b4->image.load("button2.png");
b5->rect.moveTo(900,900);
b5->image.load("button4.png");
car4->image.load("zomcar2.png");
car4->xdir=5;
}
if(car4->rect.right() >= 1200){car4->rect.moveTo(10,370);}

if( (player->getRect()).intersects(b6->getRect()) ){	//fake button kills player

player->rect.moveTo(600,1000);
lives--;
b6->image.load("button3.png");
}


if( (player->getRect()).intersects(s4->getRect()) ){	//fake life.....also kills player

player->rect.moveTo(600,1000);
lives--;
s4->image.load("fakelife.png");
}

	//player and zombie cars
if( (player->getRect()).intersects(car->getRect()) || (player->getRect()).intersects(car2->getRect()) || (player->getRect()).intersects(car3->getRect()) || (player->getRect()).intersects(car4->getRect()) || (player->getRect()).intersects(ncar->getRect()) || (player->getRect()).intersects(zcar->getRect()) ){

player->rect.moveTo(600,1000);
lives--;
}

//final button moves player to level 3
if( (player->getRect()).intersects(b5->getRect()) ){

level3=TRUE;
player->rect.moveTo(600,600);
level2=FALSE;
}
}




if(level3==TRUE){
  bg2->image.load("space.png");
//shooters
sh1->autoMove();	//shooters start moving when they sense player in level 3
sh2->autoMove();
sh3->autoMove();
sh4->autoMove();

sh1->xdir=0; sh1->ydir=0;	//initially they dont move
sh2->xdir=0; sh2->ydir=0;
sh3->xdir=0; sh3->ydir=0;
sh4->xdir=0; sh4->ydir=0;

	//they move to players row or column
if((player->getRect().left()) <(sh1->getRect().left())) sh1->xdir=-8;
if((player->getRect().right()) >(sh1->getRect().right())) sh1->xdir=8;

if((player->getRect().bottom()) < (sh2->getRect().bottom())) sh2->ydir=-8;
if((player->getRect().top()) > (sh2->getRect().top())) sh2->ydir=8;

if((player->getRect().bottom()) < (sh2->getRect().bottom())) sh2->ydir=-8;
if((player->getRect().top()) > (sh2->getRect().top())) sh2->ydir=8;

if((player->getRect().left()) <(sh3->getRect().left())) sh3->xdir=-8;
if((player->getRect().right()) >(sh3->getRect().right())) sh3->xdir=8;

if((player->getRect().bottom()) < (sh4->getRect().bottom())) sh4->ydir=-8;
if((player->getRect().top()) > (sh4->getRect().top())) sh4->ydir=8;

int S1B= sh1->getRect().bottom();	//bullets find shooters respective positios
int S1L= sh1->getRect().left();
int S2R= sh2->getRect().right();
int S2T= sh2->getRect().top();
int S3T= sh3->getRect().top();
int S3L= sh3->getRect().left();
int S4L= sh4->getRect().left();
int S4B= sh4->getRect().bottom();


if( (bullet1->getRect().top()) >1000)
{
  score+=300; //dodging bullets gives score
bullet1->rect.moveTo(S1L+20,S1B-100);	//bullets respawn to whereever shooters have moved once off screen
shots--;
}
if( (bullet2->getRect().left()) >1200)
{ 
  score+=300;
bullet2->rect.moveTo(S2R-100,S2T+20);
shots--;
}
if( (bullet3->getRect().bottom()) <0)
{
  score+=300;
bullet3->rect.moveTo(S3L+20,S3T);
shots--;
}
if( (bullet4->getRect().right()) <0)
{
  score+=300;
bullet4->rect.moveTo(S4L,S4B-100);
shots--;								//when bullets hit screen, if player is still alive, counted as dodged
}

if( (player->getRect()).intersects(sh1->getRect()) || (player->getRect()).intersects(sh2->getRect()) || (player->getRect()).intersects(sh3->getRect()) || (player->getRect()).intersects(sh4->getRect()) || (player->getRect()).intersects(bullet1->getRect()) || (player->getRect()).intersects(bullet2->getRect()) || (player->getRect()).intersects(bullet3->getRect()) || (player->getRect()).intersects(bullet4->getRect()) ){

player->rect.moveTo(50,50);
lives--;
}


if(shots<=0){	//players move to final level when they dodge 30 shots

level4=TRUE;

player->rect.moveTo(1100,950);
level3=FALSE;

}
}


if(level4==TRUE){

if( (player->getRect()).intersects(boss->getRect()) || (player->getRect()).intersects(axe->getRect()) ){

player->rect.moveTo(1000,950);
lives--;
}

if( (pshot->getRect()).intersects(boss->getRect()) ){

bosslife=bosslife-10;	//pshot damage per shot
score+=10;
}

//player's shot attack is automatic and does damage to the boss
int PL= player->getRect().left();
int PT= player->getRect().bottom();


if( (pshot->getRect().bottom()) < 0)
{ 
pshot->rect.moveTo(PL,PT);
}

if( (pshot->getRect()).intersects(boss->getRect()))
{ 
pshot->rect.moveTo(PL,PT);
}

//Boss and Weapon


//left side attack
//boss "throws" weapon and retrieves it


if((boss->getRect().left()<=115)){
boss->image.load("ganonu.png");
}
if((boss->getRect().left()<=110)){
boss->image.load("boss.png");
axe->rect.moveTo(-200,-200);
}
if((boss->getRect().left()<=100)){
boss->image.load("axethrow.png");
axe->rect.moveTo(100,500);
}
if((boss->getRect().left()<=95)){
boss->image.load("axethrow2.png");
axe->rect.moveTo(100,510);
}
if((boss->getRect().left()<=90)){
axe->rect.moveTo(100,525);
}
if((boss->getRect().left()<=85)){
axe->rect.moveTo(100,540);
axe->image.load("axe2.png");  
}
if((boss->getRect().left()<=80)){
axe->rect.moveTo(100,555);
}
if((boss->getRect().left()<=75)){
axe->rect.moveTo(100,570);
}
if((boss->getRect().left()<=70)){
axe->rect.moveTo(100,585);
axe->image.load("axe3.png");  
}
if((boss->getRect().left()<=65)){
axe->rect.moveTo(100,600);
}
if((boss->getRect().left()<=60)){
axe->rect.moveTo(100,615);
}
if((boss->getRect().left()<=55)){
axe->rect.moveTo(100,630);
axe->image.load("axe4.png");  
}
if((boss->getRect().left()<=50)){
axe->rect.moveTo(100,645);
}
if((boss->getRect().left()<=45)){
axe->rect.moveTo(100,660);
}
if((boss->getRect().left()<=40)){
axe->rect.moveTo(100,675);
axe->image.load("axe5.png");  
}
if((boss->getRect().left()<=35)){
axe->rect.moveTo(100,690);
}
if((boss->getRect().left()<=30)){
axe->rect.moveTo(100,705);
}
if((boss->getRect().left()<=25)){
axe->rect.moveTo(100,720);
axe->image.load("axe6.png");  
}
if((boss->getRect().left()<=20)){
axe->rect.moveTo(100,735);
}
if((boss->getRect().left()<=15)){
axe->rect.moveTo(100,750);
}
if((boss->getRect().left()<=10)){
axe->rect.moveTo(100,765);
axe->image.load("axe7.png");  
}
if((boss->getRect().left()<=5)){
axe->rect.moveTo(100,780);
}


//right side attack
	//same as left side

if((boss->getRect().right()>=1090)){
axe->rect.moveTo(-200,-200);
boss->image.load("ganonu.png");
}
if((boss->getRect().right()>=1095)){
boss->image.load("boss.png");
}
if((boss->getRect().right()>=1100)){
boss->image.load("axethrow.png");
axe->rect.moveTo(800,500);
}
if((boss->getRect().right()>=1105)){
boss->image.load("axethrow2.png");
axe->rect.moveTo(800,510);
}
if((boss->getRect().right()>=1110)){
axe->rect.moveTo(800,525);
}
if((boss->getRect().right()>=1115)){
axe->rect.moveTo(800,540);
axe->image.load("axe2.png");  
}
if((boss->getRect().right()>=1120)){
axe->rect.moveTo(800,555);
}
if((boss->getRect().right()>=1125)){
axe->rect.moveTo(800,570);
}
if((boss->getRect().right()>=1130)){
axe->rect.moveTo(800,585);
axe->image.load("axe3.png");  
}
if((boss->getRect().right()>=1135)){
axe->rect.moveTo(800,600);
}
if((boss->getRect().right()>=1140)){
axe->rect.moveTo(800,615);
}
if((boss->getRect().right()>=1145)){
axe->rect.moveTo(800,630);
axe->image.load("axe4.png");  
}
if((boss->getRect().right()>=1150)){
axe->rect.moveTo(800,645);
}
if((boss->getRect().right()>=1155)){
axe->rect.moveTo(800,660);
}
if((boss->getRect().right()>=1160)){
axe->rect.moveTo(800,675);
axe->image.load("axe5.png");  
}
if((boss->getRect().right()>=1165)){
axe->rect.moveTo(800,690);
}
if((boss->getRect().right()>=1170)){
axe->rect.moveTo(800,705);
}
if((boss->getRect().right()>=1175)){
axe->rect.moveTo(800,720);
axe->image.load("axe6.png");  
}
if((boss->getRect().right()>=1180)){
axe->rect.moveTo(800,735);
}
if((boss->getRect().right()>=1185)){
axe->rect.moveTo(800,750);
}
if((boss->getRect().right()>=1190)){
axe->rect.moveTo(800,765);
axe->image.load("axe7.png");  
}
if((boss->getRect().right()>=1195)){
axe->rect.moveTo(800,780);
}

if(bosslife==0){ victory();} //when player "kills" boss, the game is won and can be played from level 1 again or exited.
}






if(lives<=0) stopGame();//if all lives lost, game over

}

//certain actions for certain key press
void Zomgame::keyPressEvent(QKeyEvent *event)
{
switch (event->key()) {
    case Qt::Key_Left://move left
       {  
int x = player->getRect().x();
        for (int i=1; i<=5; i++)
          player->moveLeft(x-35);
        break;
       }
    case Qt::Key_Right://move right
        { 
          int x = player->getRect().x();
          for (int i=1; i<=5; i++)
            player->moveRight(x+35);
	break;
        }
    case Qt::Key_Down://move down
       {  
         int y = player->getRect().y();
        for (int i=1; i<=5; i++)
          player->moveTop(y+35);
        break;
       }
    case Qt::Key_Up://move up
        { 
          int y = player->getRect().y();
          for (int i=1; i<=5; i++)
            player->moveBottom(y-6);
	break;
        }
    case Qt::Key_P://pause game
        { 
          pauseGame();
        }
        break;
    case Qt::Key_Space: //start game when first opened/run
        {
          startGame();
        }
        break;
 case Qt::Key_R://restart game during play or at win/lose screens
        {
	  stopGame(); //end current game
	  lives=25;//reset lives
	  score=0;//reset score
shots=30;//reset or level 3 would be skipped in on a second run
bosslife=500;	//reset for same reason as shots
	  startGame();//start new game
	  paused=FALSE;

	}
	break;
    case Qt::Key_Escape://quit game and close window
        {
          qApp->exit();
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

