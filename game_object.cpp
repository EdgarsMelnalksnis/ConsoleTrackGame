#include "game_object.h"

GameObject::GameObject() {
    initScr();
}
void GameObject::initScr(void) {
    const int yMin = 30;
    const int xMin = 90;
    initscr();
    noecho();
    cbreak();//ctr+c exits program
    checkScreenSize(yMin,xMin);

    clear();
    refresh();

}

void GameObject::checkScreenSize(int ymin,int xmin) {
    int y,x;
    getmaxyx(stdscr,y,x);
    if(y < ymin || x < xmin){ 
        printw("screen too small!!!");
        getch();
    }
    //FIXME 
    /*    while((y < ymin ) || ( x < xmin))
          {
          getmaxyx(stdscr,y,x);
          clear();
          printw("Make screen larger. yMax > %d (%d), xMax > %d(%d) !",ymin,y,xmin,x);
          }
          */
    refresh();

}


void GameObject::play() {
    Game game(gameStartpos,gameDim);//
    Menu men(menuStartpos,menuDim);
    int lastch = 0;
    while(1){ //add status to end Game
        lastch=men.updateMenu(lastch);
    }
}
