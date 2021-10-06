#ifndef _VEHICLE_H
#define _VEHICLE_H
class Vehicle
{
    WINDOW *gameWin;
    char character;
    int yPos,xPos,yMax,xMax;


    public:
    Vehicle(WINDOW,int,int,char);

    void mvUp();
    void mvDown();
    void mvLeft();
    void mvRight();
    void getmv();

};

Vehicle::Vehicle(WINDOW *win,int y,int x, char c);
{
    gameWIN= win;
    yPos = y;
    xPos = x;
    getmaxyx(gameWin,yMax,xMax);
    keypad(gameWin,true);
    character = c;
}

Vehicle::mvUp()
{
    yPos--;
    if(yPos < 1) yPos = 1;
}

Vehicle::mvDown()
{
    yPos++;
    if(yPos > yMax-1) yPos = yMax-1; 
}

Vehicle::mvLeft()
{
    xPos--;
    if(xPos < 1) xPos = 1;
}

Vehicle::mvRight()
{
    xPos++;
    if(xPos > Xmax-1) xPos = xMax -1;
}

Vehicle::getmv()
{
    int choice = wgetch(curwin)
        switch(choice)
        {
            case KEY_UP:
                mvUp();
                break;
            case KEY_DOWN:
                mvDown();
                break;
            case KEY_LEFT:
                mvLeft();
            case KEY_RIGHT:
                mvRight();
            default:
                break;
        }    
return choice;
}

Vehicle::display()
{
mvwaddch(gameWin,yPos,xPos, character);//single character instead of string
}
#endif
