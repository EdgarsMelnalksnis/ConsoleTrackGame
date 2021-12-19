#include "game.h"

Game::Game(const int* gameStartPos,const int* gameSize) {
    this->yxStart = gameStartPos;
    this->yxSize = gameSize;
    this->gameWin = newwin(yxSize[0],yxSize[1], \
	    yxStart[0],yxStart[1]);
    drawGame(gameWin);
    car.init(gameWin,1,1,'o');
}


/*
   methode to draw menu. Class Game will 
   choose where to draw it based on screen size 
   */
void Game::drawGame(WINDOW *win) {    
    box(win,0,0);
    nodelay(win,true);
    mvwprintw(win,1,1,"Game");
    wrefresh(win);
}

void Game::playGame() {
    choice = car.getMove();
    car.display();
    wrefresh(gameWin);
}
