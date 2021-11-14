#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <ncurses.h>

class Vehicle
{
    public:
        //Vehicle(WINDOW *,int,int,char);
        void init(WINDOW *,int,int,char);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        int getMove();
        void display();

    //private:
        WINDOW *gmWin;
        char character;
        int yPos,xPos,yMax,xMax;


};

#endif
