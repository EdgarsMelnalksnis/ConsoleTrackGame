#ifndef _MENU_H
#define _MENU_H

#include <curses.h>
#include <string>
#include "menu_item.h"
#include "config.h"

class Menu {
    public:

        Menu(int *menuStartPos,int *menuSize);
 
        WINDOW *menuWin;
        MenuItem mItem={"FILE",yxStart};//multiple menu items    
        int yxStart[2];
        int yxSize[2];
        int numMenus;
        //std::string menu[3] = {"GAME","TRACK","HELP"};
        int menuChoice;
        int menuHighlight = 0;

        void drawMenu(WINDOW *,MenuItem);//methode to draw menu. Class Game will choose where to draw it based on screen size
};






#endif
