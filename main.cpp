#include <iostream>
#include <ncurses.h>
#include "vehicle.h"
#include "config.h"
#include "game_object.h"
#include "menu.h"


void checkScreenSize(int ymin,int xmin)
{
    int y,x;
    getmaxyx(stdscr,y,x);
    while(y < ymin || x < xmin)
    {
        getmaxyx(stdscr,y,x);
        clear();
        printw("Make screen larger. yMax > %d (%d), xMax > %d(%d) !",ymin,y,xmin,x);

        refresh();
    }
}

void initScreen(void)
{
    initscr();
    noecho();
    cbreak();//ctr+c exits program
    checkScreenSize(YMIN,XMIN);

    clear();
    refresh();

}


int main(int argc,char **argv){	
    //test
    int yMax,xMax;
    int startpos[]={1,1};
    int dim[]={10,20};

    initScreen();

    Menu men(startpos,dim);

    refresh();
    int lastChoice=0;
    while(1)
    {
        lastChoice=men.updateMenu(lastChoice);
    }
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */
    return 0;
}
