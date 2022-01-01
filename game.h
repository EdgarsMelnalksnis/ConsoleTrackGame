#ifndef _GAME_H
#define _GAME_H

#include <ncurses.h>
#include <string>
#include "menu_item.h"
#include "config.h"
#include "vehicle.h"

class Game {
    public:
        Game(const int *gameStartPos,const int *gameSize);
        int updateGame(int);
        WINDOW *gameWin;

        void playGame();
    
        const int *yxStart;
        const int *yxSize;
        int choice;
        Vehicle car;// = new Vehicle(gameWin,2,2,'o');
        void drawGame(WINDOW *);
	void randomGen(WINDOW *,int symbol,uint8_t count);
};


#endif
