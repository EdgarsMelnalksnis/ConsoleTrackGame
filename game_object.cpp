#include "game_object.h"
#include <ncurses.h>


void GameObject::checkScreenSize(int ymin,int xmin)
{
    int y,x;
    getmaxyx(stdscr,y,x);
    while(y < ymin || x < xmin)
    {
        getmaxyx(stdscr,y,x);
        clear();
        printw("Make screen larger. yMax > %d (%d), xMax > %d(%d) !",ymin,y,xmin,x);
    }
    refresh();
}
