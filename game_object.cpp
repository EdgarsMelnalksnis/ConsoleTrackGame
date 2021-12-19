#include "game_object.h"

GameObject::GameObject() {
    initScr();
}
void GameObject::initScr(void) {
    initscr();
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
	while((y < ymin ) || ( x < xmin)) {
	    clear();
	    printw("Make screen larger. yMax > %d (%d), \ 
		    xMax > %d(%d) !",ymin,y,xmin,x);
	    getmaxyx(stdscr,y,x);
	    refresh();
	}
    }
}
void GameObject::start() {
    Game *game = new Game(gameStartpos,gameDim);//
    Menu men(menuStartpos,menuDim);
    WINDOW *helpWin = newwin(4,15,1,1);
    box(helpWin,0,0);
    refresh();
    int lastch = 0;
    char c;
    gameStatus gameStat;
    int toggle = 0;
    //nodelay(helpWin,true);
    while(1){ 
	//c = wgetch(helpWin);
	//toggle++;
	//if(c != ERR) {
	//  if(c == SPACE) {
	//	toggle = toggle ^ 1;
	//  }
	//}
	//mvwprintw(helpWin,1,1,"Toggle:%d",toggle);
	//wrefresh(helpWin);
	// if(toggle & 1) {
	//   lastch=men.updateMenu(lastch);
	//  }
	// else {
	game->playGame();
	// }
    }
}
