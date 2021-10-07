#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <ncurses.h>

class Vehicle
{
    WINDOW *gameWin;
    char character;
    int yPos,xPos,yMax,xMax;


    public:
    Vehicle(WINDOW*,int,int,char);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getMove();
    void display();

};

#endif
