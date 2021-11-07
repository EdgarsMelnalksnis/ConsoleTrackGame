#include "game_object.h"
#include "ncurses.h";
void GameObject::initScr(void){
    initscr();
    noecho();
    cbreak();//ctr+c exits program
    checkScreenSize(YMIN,XMIN);

    clear();
    refresh();

}




void GameObject::checkScreenSize(int ymin,int xmin)
{
    int y,x;
    std::cout << "Line:" << __LINE__ << std::endl;
    getmaxyx(stdscr,y,x);
    std::cout << "Line:" << __LINE__ << std::endl;
    if(y < ymin || x < xmin){ 
        printw("screen too small!!!");
        getch();
    }
    /* FIXME
       while(y < ymin || x < xmin)
       {
       getmaxyx(stdscr,y,x);
       clear();
       printw("Make screen larger. yMax > %d (%d), xMax > %d(%d) !",ymin,y,xmin,x);
       }
       */
    refresh();

}
