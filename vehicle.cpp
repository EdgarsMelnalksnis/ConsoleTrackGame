#include "vehicle.h"

Vehicle::Vehicle(WINDOW *win,int y,int x, char c)
{
    gameWin= win;
    yPos = y;
    xPos = x;
    getmaxyx(gameWin,yMax,xMax);
    keypad(gameWin,true);
    character = c;
}

void Vehicle::moveUp()
{
    yPos--;
    if(yPos < 1) yPos = 1;
}
void Vehicle::moveDown()
{
    yPos++;
    if(yPos > yMax-2) yPos = yMax-2;
}

void Vehicle::moveLeft()
{
    xPos--;
    if(xPos < 1) xPos = 1;
}

void Vehicle::moveRight()
{
    xPos++;
    if(xPos > xMax-2) xPos = xMax -2;
}
int Vehicle::getMove()
{
    int choice = wgetch(gameWin);
        switch(choice)
        {
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
            default:
                break;
        }
return choice;
}

void Vehicle::display()
{
mvwaddch(gameWin,yPos,xPos, character);//single character instead of string
}

