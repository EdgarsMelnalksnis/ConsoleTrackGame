#include <iostream>
#include <ncurses.h>
#include "vehicle.h"
#include "config.h"
#include "game_object.h"
#include "menu.h"
#include "helper_functions.h"
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
