#include <ncurses.h>

#define GAME_WIN_HEIGHT 10
#define GAME_WIN_WIDTH 20
#define GAME_WIN_Y 5
#define GAME_WIN_X 2
#define INS_WIN_HEIGHT 10
#define INS_WIN_WIDTH 20
#define INS_WIN_Y 5
#define INS_WIN_X GAME_WIN_X + GAME_WIN_WIDTH + 5

int main(int argc,char **argv){	
    initscr();
    cbreak();//ctr+c exits program
   // int win_height=10,win_width=20,win_y=5,win_x=2;
	
    WINDOW *insWin = newwin(INS_WIN_HEIGHT,INS_WIN_WIDTH,INS_WIN_Y,INS_WIN_X);
    WINDOW *gameWin = newwin(GAME_WIN_HEIGHT,GAME_WIN_WIDTH,GAME_WIN_Y,GAME_WIN_X);
    refresh();

    box(gameWin,0,0);
    mvwprintw(gameWin,1,1,"game");
    wrefresh(gameWin);
    box(insWin,0,0);
    mvwprintw(insWin,1,1,"Instructions");
    wrefresh(insWin);
    getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
	return 0;
}
