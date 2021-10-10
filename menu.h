#ifndef _MENU_H
#define _MENU_H

#include <curses.h>
#include <string>
#include "menu_item.h"
#include "config.h"

class Menu {
    public:
        Menu(int *menuStartPos,int *menuSize);
    private:
        WINDOW *menuWin;
        MenuItem mItem[3]={{"GAME"},{"TRACK"},{"HELP"}};//multiple menu items    
        int *yxStart;
        int *yxSize;
        int numMenus = 3;
        int menuChoice = 0;
        int menuHighlight = 0;

        void drawMenu(WINDOW *,MenuItem *);
};






#endif
