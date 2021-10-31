#include "helper_functions.h"

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

