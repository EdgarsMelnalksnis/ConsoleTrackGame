#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include <iostream>
#include <ncurses.h>
#include "game.h"
#include "config.h"

class GameObject{
    void initScr(void);
    enum gameStatus {STOP = 0, RUN = 1, PAUSE = 2};
    void checkScreenSize(int,int);

    public:
    GameObject(){
        initScr();
    }

};

#endif
