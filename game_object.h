#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include <iostream>
#include <ncurses.h>
#include "game.h"
#include "config.h"
#include "menu.h"

class GameObject{
    int yMax,xMax;
    int gameStartpos[2]={1,1};
    int gameDim[2]={10,20};
    int menuStartpos[2]={1,gameStartpos[1]+gameDim[1]+5};
    int menuDim[2]={10,20};

    void initScr(void);
    enum gameStatus {STOP = 0, RUN = 1, PAUSE = 2};
    void checkScreenSize(int,int);
    
    public:
    GameObject(){
        initScr();
    }
    void  play();
};

#endif
