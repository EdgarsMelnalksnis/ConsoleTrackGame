#ifndef _MENU_H
#define _MENU_H

#include <curses.h>
#include <string>
#include "menu_item.h"

class Menu {
    public:
        Menu(WINDOW *win,MenuItem* mi,int num)
        {
            this->menuWindow = win;
            this->mItem = mi;
            this->numMenus = num;
        }
        WINDOW *menuWindow;
        MenuItem *mItem;    
        int numMenus;

};






#endif
