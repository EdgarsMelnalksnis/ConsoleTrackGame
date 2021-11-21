#ifndef _MENU_H
#define _MENU_H

#include <ncurses.h>
#include <string>
#include "menu_item.h"
#include "config.h"
#include "window.h"

class Menu {
    public:
        Menu(const int *menuStartPos,const int *menuSize);
        int updateMenu(int);
     
    private:
        WINDOW *menuWin;
        MenuItem mItem[3]={{"GAME"},{"TRACK"},{"HELP"}};    
        const int *yxStart;
        const int *yxSize;
        int numMenus = 3;
        int menuChoice = 0;
        int menuHighlight1 = 0;

        void drawMenu(WINDOW *,MenuItem *);
};

#endif
