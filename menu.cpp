#include "menu.h"

Menu::Menu(int* menuStartPos,int* menuSize)
{
    this->yxStart[0] =1;// menuStartPos[0];
    this->yxStart[1] =1;// menuStartPos[1];
    this->yxSize[0] =10;// menuSize[0];
    this->yxSize[1] =10;// menuSize[1];
    this->menuWin = newwin(yxSize[0],yxSize[1],yxStart[0],yxStart[1]);

    drawMenu(menuWin);
}



void Menu::drawMenu(WINDOW *win)//methode to draw menu. Class Game will choose where to draw it based on screen size
{
    box(win,0,0);
    mvwprintw(win,1,1,"MENU");
    wrefresh(win);
    // keypad(menuWin,true);
}

