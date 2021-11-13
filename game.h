#ifndef _GAME_H
#define _GAME_H

#include <ncurses.h>
#include <string>
#include "menu_item.h"
#include "config.h"

class Game {
    public:
        Game(int *gameStartPos,int *gameSize);
        int updateGame(int);

    private:
        WINDOW *gameWin;
        int *yxStart;
        int *yxSize;
        
        void drawGame(WINDOW *);
};


#endif
