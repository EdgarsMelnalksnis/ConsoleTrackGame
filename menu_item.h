#ifndef _MENU_ITEM_H
#define _MENU_ITEM_H

#include <string>

class MenuItem {
    public:
        MenuItem(const char* text,int yx[])
        {
            this->menuText = text;
            this->startYX[0]=yx[0];
            this->startYX[1]=yx[1];

        }
        int startYX[2];
        const char* menuText;
        char trigger;
};

#endif

