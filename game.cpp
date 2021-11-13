#include "game.h"

Game::Game(const int* gameStartPos,const int* gameSize)
{
    this->yxStart = gameStartPos;
    this->yxSize = gameSize;
    this->gameWin = newwin(yxSize[0],yxSize[1],yxStart[0],yxStart[1]);
    drawGame(gameWin);
}



void Game::drawGame(WINDOW *win)//methode to draw menu. Class Game will choose where to draw it based on screen size
{
    box(win,0,0);
    mvwprintw(win,1,1,"Game");
    wrefresh(win);
}

