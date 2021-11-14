#include "menu.h"

Menu::Menu(const int* menuStartPos,const int* menuSize)
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

int  Menu::updateMenu(int menuHighlight)
{
    keypad(menuWin, TRUE);
    //int menuHighlight=lastChoice;
    while(1) {
        for(int i = 0; i<3;i++)
        {
            if(i == menuHighlight) 
            {
                //reverse color
                wattron(menuWin,A_REVERSE);
            }
            mvwprintw(menuWin,i+3,1,mItem[i].menuText);
            wattroff(menuWin, A_REVERSE);
        }
        menuChoice = wgetch(menuWin);
        switch(menuChoice)
        {
            case KEY_UP:
                menuHighlight--;
                if(menuHighlight<0) menuHighlight = 0;
                break;
            case KEY_DOWN:
                menuHighlight++;
                if(menuHighlight>2) menuHighlight = 2;
                break;
            default:
                break;
        }         
        if(menuChoice == ENTER) break ;
        wrefresh(menuWin);
    }   
    werase(menuWin);
    if(mItem[menuHighlight].menuText == "HELP") mvwprintw(menuWin,1,1,"HELP ME :D");
    else mvwprintw(menuWin,3,1,"in construction");
    wrefresh(menuWin);
return menuHighlight;
}
