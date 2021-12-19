#ifndef _MENU_ITEM_H
#define _MENU_ITEM_H

#include <string>

class MenuItem {
    public:
        MenuItem(const char* text) {
            this->menuText = text;
        }
        const char* menuText;
        char trigger;
};

#endif

