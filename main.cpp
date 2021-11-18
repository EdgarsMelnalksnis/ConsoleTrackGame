#include <iostream>
#include <ncurses.h>
#include "vehicle.h"
#include "config.h"
#include "game_object.h"
#include "menu.h"

int main(int argc,char **argv){	
    GameObject *trackGame = new GameObject;

    refresh();
    trackGame->start();

    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */
    return 0;
}
