#ifndef _GAME_H
#define _GAME_H

#include <ncurses.h>
#include <string>
#include "menu_item.h"
#include "config.h"

class Game {
    public:
        Game(const int *gameStartPos,const int *gameSize);
        int updateGame(int);

    private:
        WINDOW *gameWin;
        const int *yxStart;
        const int *yxSize;
        
        void drawGame(WINDOW *);
};


#endif
