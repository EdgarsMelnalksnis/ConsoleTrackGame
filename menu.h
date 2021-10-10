#ifndef _MENU_H
#define _MENU_H

#include <curses.h>
#include <string>
#include "menu_item.h"
#include "config.h"

class Menu {
    public:

        Menu(int menuStartPos[],int menuSize[])
        {
            this->yxStart[0] = menuStartPos[0];
            this->yxStart[1] = menuStartPos[1];
            this->yxSize[0] = menuSize[0];
            this->yxSize[1] = menuSize[1];

           

            WINDOW *menuWin = newwin(yxSize[0],yxSize[1],(yxSize[0]/2-10),GAME_WIN_X+GAME_WIN_WIDTH+5);
            box(menuWin,0,0);
            mvwprintw(menuWin,1,1,"MENU");
            wrefresh(menuWin);
            keypad(menuWin,true);

        }


        // WINDOW *menuWindow;
        MenuItem *mItem;//multiple menu items    
        int *yxStart;
        int *yxSize;
        int numMenus;
        //std::string menu[3] = {"GAME","TRACK","HELP"};
        int menuChoice;
        int menuHighlight = 0;

        void drawMenu(int xyStart[],int xySize[]);//methode to draw menu. Class Game will choose where to draw it based on screen size
};






#endif
