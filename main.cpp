#include <iostream>
#include <ncurses.h>
#include "vehicle.h"
#include "config.h"
#include "game_object.h"
#include "menu.h"
#include <time.h>
#include <stdlib.h>
int main(int argc,char **argv) {	
    srand(time(NULL));
    GameObject *trackGame = new GameObject;

    refresh();
    trackGame->start();

    getch();
    endwin();
    return 0;
}
