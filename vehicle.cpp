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

int Vehicle::moveVehicle(int dir, uint16_t count) {
    int retSymbol;
    while(count) {
	switch (dir) {
	    case KEY_UP:
		trackChar = mvwinch(gmWin, yPos - 1, xPos);
		if(trackChar == ' ') {
		    mvwaddch(gmWin,yPos,xPos,'.');
		    if(moveUp()) {
			retSymbol = trackChar;
		    }
		    break;
		}
		else return trackChar; 
	    case KEY_DOWN:
		trackChar = mvwinch(gmWin, yPos + 1, xPos);
		if(trackChar == ' ') {
		    mvwaddch(gmWin,yPos,xPos,'.');
		    if(moveDown()) {
			retSymbol = trackChar;
		    }
		    break;
		}
		else return trackChar;    
	    case KEY_RIGHT:
		trackChar = mvwinch(gmWin, yPos, xPos + 1);
		if(trackChar == ' ') {
		    mvwaddch(gmWin,yPos,xPos,'.');
		    if(moveRight()) {
			retSymbol = trackChar;
		    }
		    break;
		}
	    case KEY_LEFT:
		trackChar = mvwinch(gmWin, yPos, xPos -1);
		if(trackChar == ' ') {
		    mvwaddch(gmWin,yPos,xPos,'.');
		    if(moveLeft()) {
			retSymbol = trackChar;
		    }
		    break;
		}
	}
	--count;
    }
    return retSymbol;
}

uint8_t Vehicle::moveUp() {
    yPos--;
    if(yPos < 2) {
	return 0;
    }
    return 1;
}
uint8_t Vehicle::moveDown() {
    yPos++;
    if(yPos > yMax - 2) {
	return 0;
    }
    return 1;
}

uint8_t Vehicle::moveLeft() {
    xPos--;
    if(xPos < 2) {
	return 0;
    }
    return 1;
}

uint8_t Vehicle::moveRight() {
    xPos++;
    if(xPos > xMax - 2) {
	return 0;
    }
    return 1;
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

int Vehicle::getUserInput() {
    return wgetch(gmWin);
}

void Vehicle::display() {
    //single character instead of string
    mvwaddch(gmWin,yPos,xPos, character);
    //wrefresh(gmWin);
}

