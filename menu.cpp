#include "menu.h"

Menu::Menu(int* menuStartPos,int* menuSize)
{
    this->yxStart = menuStartPos;
    this->yxSize = menuSize;
    this->menuWin = newwin(yxSize[0],yxSize[1],yxStart[0],yxStart[1]);

    drawMenu(menuWin,this->mItem);
}



void Menu::drawMenu(WINDOW *win,MenuItem *menuIt)//methode to draw menu. Class Game will choose where to draw it based on screen size
{
    box(win,0,0);
    mvwprintw(win,1,1,"MENU");
    mvwprintw(win,3,1,menuIt[0].menuText);
    mvwprintw(win,4,1,menuIt[1].menuText);
    mvwprintw(win,5,1,menuIt[2].menuText);
    wrefresh(win);
    // keypad(menuWin,true);
}

