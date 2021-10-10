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


int main(int argc,char **argv){	
    //test
    int yMax,xMax;
    int startpos[]={1,1};
    int dim[]={5,10};

    initscr();
    noecho();
    cbreak();//ctr+c exits program
    checkScreenSize(YMIN,XMIN);

    clear();
    refresh();

    Menu men(startpos,dim);

    refresh();
    while(1)

        getmaxyx(stdscr,yMax,xMax);

    WINDOW* gameWin = newwin(GAME_WIN_HEIGHT,GAME_WIN_WIDTH,(yMax/2)-10,GAME_WIN_X);
    box(gameWin,0,0);
    refresh();
    wrefresh(gameWin);

    //Vehicle *c = new Vehicle(gameWin,1,1,'0');
    //menuWin = newwin(INS_WIN_HEIGHT,INS_WIN_WIDTH,(yMax/2-10),GAME_WIN_X+GAME_WIN_WIDTH+5);   
    //  refresh();
    /*
       do{
       c->display();
       wrefresh(gameWin);
       }while(c->getMove() != 'x');

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
     */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */
    return 0;
}
