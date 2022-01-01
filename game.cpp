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
    //mvwaddch(win,10,10,'+');
    //mvwaddch(win,8,8,'+');
    //mvwaddch(win,5,5,'-');
    //mvwaddch(win,12,12,'-');
    //mvwaddch(win,10,3,'-');
    randomGen(win,'+', 10);
    randomGen(win, '-', 10);
    wrefresh(win);
}

void Game::randomGen(WINDOW *win, int symbol, uint8_t count) {
    //get random number for x and y, next check if it is
    //whitespace, then place
    unsigned int randY;
    unsigned int randX;

    while(count) {
	--count;
	randX = random() % yxSize[0];
	randY = random() % yxSize[1];
	if(mvwinch(win, randX, randY) == ' ') {
	    mvwaddch(win,randX,randY,symbol);
	}
    }
}

void Game::playGame() {
    choice = car.getUserInput();
    car.item=car.moveVehicle(choice,car.speed);  
    if(car.item != car.item_old) {
	car.item_old = car.item;
	switch(car.item) {
	    case '+':
		++car.speed;
		break;
	    case '-':
		if(car.speed > 1) {
		    --car.speed;
		}
		break;
	    default: 
		break;
	}
    }
    car.display();
    wrefresh(gameWin);

}


