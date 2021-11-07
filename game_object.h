#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include <iostream>
#include <ncurses.h>
#include "game.h"
#include "config.h"
#include "menu.h"

class GameObject{
    int yMax,xMax;
    int startpos[2]={1,1};
    int dim[2]={10,20};

    void initScr(void);
    enum gameStatus {STOP = 0, RUN = 1, PAUSE = 2};
    void checkScreenSize(int,int);
    
    public:
    GameObject(){
        initScr();
       // Menu men(startpos,dim);
    }
    void  update();
};

#endif
