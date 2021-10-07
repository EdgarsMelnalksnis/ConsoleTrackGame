#include <iostream>
#include <ncurses.h>
#include "vehicle.h"

#define GAME_WIN_HEIGHT 30
#define GAME_WIN_WIDTH 40
#define GAME_WIN_Y 5
#define GAME_WIN_X 2
#define INS_WIN_HEIGHT 10
#define INS_WIN_WIDTH 20
#define INS_WIN_Y 5
#define INS_WIN_X GAME_WIN_X + GAME_WIN_WIDTH + 5
#define ENTER 10

int main(int argc,char **argv){	
    WINDOW* menuWin;
    WINDOW* gameWin;
    Vehicle *c = new Vehicle(gameWin,1,1,'0');
    std::string menu[3] = {"GAME","TRACK","HELP"};
    int menuChoice;
    int menuHighlight = 0;

    initscr();
    cbreak();//ctr+c exits program

    menuWin = newwin(INS_WIN_HEIGHT,INS_WIN_WIDTH,INS_WIN_Y,INS_WIN_X);   
    gameWin = newwin(GAME_WIN_HEIGHT,GAME_WIN_WIDTH,GAME_WIN_Y,GAME_WIN_X);   
    refresh();

    box(gameWin,0,0);
    mvwprintw(gameWin,1,1,"game");
    wrefresh(gameWin);
    //box(menuWin,0,0);
    mvwprintw(menuWin,1,1,"MENU");
    wrefresh(menuWin);
    keypad(menuWin,true);

    while(1)
    {
        for(int i = 0; i<3;i++)
        {
            if(i == menuHighlight)
                wattron(menuWin,A_REVERSE);
            mvwprintw(menuWin,i+3,1,menu[i].c_str());
            wattroff(menuWin, A_REVERSE);
        }
        menuChoice = wgetch(menuWin);
        switch(menuChoice)
        {
            case KEY_UP:
                menuHighlight--;
                if(menuHighlight<0) menuHighlight = 0;
                break;
            case KEY_DOWN:
                menuHighlight++;
                if(menuHighlight>2) menuHighlight = 2;
                break;
            default:
                break;
        }         
        if(menuChoice == ENTER) break;
    }
    werase(menuWin);
    if(menu[menuHighlight] == "HELP") mvwprintw(menuWin,1,1,"HELP ME :D");
    else mvwprintw(menuWin,3,1,"in construction");
    wrefresh(menuWin);

    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */
    return 0;
}
