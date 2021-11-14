#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include <iostream>
#include <ncurses.h>
#include "game.h"
#include "config.h"
#include "menu.h"
#include "vehicle.h"

class GameObject{
    public:
        GameObject();
        //    initScr();
        //}
        void  play();

    private:
        int yMax,xMax;
        const int titleStartPos[2] = {1,1};
        const int gameStartpos[2]={titleStartPos[0]+4,1};
        const int gameDim[2]={20,40};
        const int menuStartpos[2]={gameStartpos[0],gameStartpos[1]+gameDim[1]+5};
        const int menuDim[2]={10,20};
        const int yMin = 30;
        const int xMin = 90;

        void initScr(void);
        enum gameStatus {STOP = 0, RUN = 1, PAUSE = 2};
        void checkScreenSize(int,int);

};

#endif
