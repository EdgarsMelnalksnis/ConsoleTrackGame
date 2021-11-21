#include "game_object.h"

GameObject::GameObject() {
    initScr();
}
void GameObject::initScr(void) {
    initscr();//ncureses function
    noecho();
    curs_set(0);//no cursor ?
    cbreak();//ctr+c exits program
    nodelay(stdscr, TRUE);
    //scrollok(stdscr, TRUE);
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
void GameObject::start() {
    Game *game = new Game(gameStartpos,gameDim);//
    Menu men(menuStartpos,menuDim);
    refresh();
    int lastch = 0;
    char c;
    gameStatus gameStat;
    while(1){ //add status to end Game
        
            lastch=men.updateMenu(lastch);
        //checkScreenSize(yMin,xMin);
    }
}
