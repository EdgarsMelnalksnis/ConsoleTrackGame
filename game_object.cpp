#include "game_object.h"

GameObject::GameObject() {
    initScr();
}
void GameObject::initScr(void) {
    initscr();//ncureses function
    noecho();
    cbreak();//ctr+c exits program
    checkScreenSize(yMin,xMin);

    clear();
    refresh();

}

void GameObject::checkScreenSize(int ymin,int xmin) {
    int y,x;
    getmaxyx(stdscr,y,x);
    if((y < ymin ) || ( x < xmin)) {
        while((y < ymin ) || ( x < xmin))
        {
            clear();
            printw("Make screen larger. yMax > %d (%d), xMax > %d(%d) !",ymin,y,xmin,x);
            getmaxyx(stdscr,y,x);
            refresh();
        }
    }
}
void GameObject::play() {
    Game game(gameStartpos,gameDim);//
    Menu men(menuStartpos,menuDim);
    mvprintw(titleStartPos[0],titleStartPos[1],"Track Game");
    refresh();
    int lastch = 0;
    while(1){ //add status to end Game
        lastch=men.updateMenu(lastch);
        //checkScreenSize(yMin,xMin);
    }
}
