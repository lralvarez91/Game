#include "zomgame.h"
#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget)
{

  QPalette palette;
  palette.setBrush(widget.backgroundRole(), QBrush(Qt::darkCyan));
  widget.setPalette(palette);
    

int x, y;
	int screenWidth;
  int screenHeight;

  int WIDTH = 1200;	//make a window of 800 pixels wide
  int HEIGHT = 1000; //make window 800 pixels tall
  

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
 
  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  
    
  Zomgame window;	//make game window
  
  window.setWindowTitle("Zombie TakeOver");	//title of window
  window.show();
  center(window);

  return app.exec();
}

