#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <ncurses.h>

class Vehicle
{
    public:
        //Vehicle(WINDOW *,int,int,char);
        void init(WINDOW *,int,int,char);
        int moveVehicle(int,uint16_t);
        uint8_t moveUp();
        uint8_t moveDown();
        uint8_t moveLeft();
        uint8_t moveRight();
        int getMove();
        int getUserInput();
        void display();
	int speed;
	int item;
	int item_old;
    private:
        WINDOW *gmWin;
        char character;
        int yPos,xPos,yMax,xMax;
        chtype trackChar;
};

#endif
