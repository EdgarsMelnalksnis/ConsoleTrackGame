#ifndef _MENU_ITEM_H
#define _MENU_ITEM_H

#include <string>

class MenuItem {
    public:
        MenuItem(string text,char trig)
        {
            this-> menuText = text;
            this-> trigger = trig;
        }
        int startX,startY;
        srd::string menuText;
        char trigger;
};

#endif

