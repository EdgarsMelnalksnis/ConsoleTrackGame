#ifndef _MENU_H
#define _MENU_H

#include <curses.h>
#include <string>
#include "menu_item.h"

class Menu {
    public:
        WINDOW *menuWindow;
        MenuItem *mItem;    
        int numMenus;

};






#endif
