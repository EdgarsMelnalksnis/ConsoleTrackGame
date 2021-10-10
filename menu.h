#ifndef _MENU_H
#define _MENU_H

#include <curses.h>
#include <string>
#include "menu_item.h"
#include "config.h"

class Menu {
    public:

        Menu(int *menuStartPos,int *menuSize)
        {
            this->yxStart[0] = menuStartPos[0];
            this->yxStart[1] = menuStartPos[1];
            this->yxSize[0] = menuSize[0];
            this->yxSize[1] = menuSize[1];
            this->menuWin = newwin(yxSize[0],yxSize[1],yxStart[0],yxStart[1]);

            drawMenu(menuWin);
        }

    private:
        WINDOW *menuWin;
        MenuItem *mItem;//multiple menu items    
        int *yxStart;
        int *yxSize;
        int numMenus;
        //std::string menu[3] = {"GAME","TRACK","HELP"};
        int menuChoice;
        int menuHighlight = 0;

        void drawMenu(WINDOW *win)//methode to draw menu. Class Game will choose where to draw it based on screen size
        {
            box(win,0,0);
            mvwprintw(win,1,1,"MENU");
            wrefresh(win);
            // keypad(menuWin,true);
        }
};






#endif
