#include "vehicle.h"
#include "config.h"
void Vehicle::init(WINDOW *win,int y,int x, char c) {
    this->gmWin = win;
    this->yPos = y;
    this->xPos = x;
    getmaxyx(gmWin,yMax,xMax);
    keypad(gmWin,true);
    character = c;
}

void Vehicle::moveUp() {
    mvwaddch(gmWin,yPos,xPos,'.');
    yPos--;
    if(yPos < 1) {
	yPos = 1;
    }
}
void Vehicle::moveDown() {
    mvwaddch(gmWin,yPos,xPos,'.');
    yPos++;
    if(yPos > yMax-2) {
	yPos = yMax-2;
    }
}

void Vehicle::moveLeft() {
    mvwaddch(gmWin,yPos,xPos,'.');
    xPos--;
    if(xPos < 1) {
	xPos = 1;
    }
}

void Vehicle::moveRight() {
    mvwaddch(gmWin,yPos,xPos,'.');
    xPos++;
    if(xPos > xMax-2) {
	xPos = xMax -2;
    }
}
int Vehicle::getMove() {
    nodelay(gmWin,true);
    int choice = wgetch(gmWin);
    switch(choice) {
	case KEY_UP:
	    moveUp();
	    break;
	case KEY_DOWN:
	    moveDown();
	    break;
	case KEY_LEFT:
	    moveLeft();
	    break;
	case KEY_RIGHT:
	    moveRight();
	    break;
	case SPACE:
	    wgetch(gmWin);
	    break;
	default:
	    break;
    }
    return choice;
}

void Vehicle::display() {
    //single character instead of string
    mvwaddch(gmWin,yPos,xPos, character);
    //wrefresh(gmWin);
}

