#include "menu.h"

Menu::Menu(const int* menuStartPos,const int* menuSize) {
    this->yxStart = menuStartPos;
    this->yxSize = menuSize;
    this->menuWin = newwin(yxSize[0],yxSize[1], \
	    yxStart[0],yxStart[1]);

    drawMenu(menuWin,this->mItem);
}

/*
   methode to draw menu. Class Game will choose 
   where to draw it based on screen size
   */
void Menu::drawMenu(WINDOW *win,MenuItem *menuIt) {
    nodelay(win,true);
    box(win,0,0);
    //mvwprintw(win,0,1,"MENU");
    mvwprintw(win,0,1,menuIt[0].menuText);
    mvwprintw(win,0,6,menuIt[1].menuText);
    mvwprintw(win,0,12,menuIt[2].menuText);
    wrefresh(win);
    // keypad(menuWin,true);
}

int  Menu::updateMenu(int menuHighlight) { 
    keypad(menuWin, TRUE);
    //int menuHighlight=lastChoice;
    while(1) {
	for(int i = 0; i < 3; i++) {
	    if(i == menuHighlight) { 
		//reverse color
		wattron(menuWin,A_REVERSE);
	    }
	    if (i == 0) {
		mvwprintw(menuWin,0,1,mItem[i].menuText);
	    }
	    else { 
		mvwprintw(menuWin,0,i*6,mItem[i].menuText);
	    }
	    wattroff(menuWin, A_REVERSE);
	}
	menuChoice = wgetch(menuWin);
	switch (menuChoice) {
	    case KEY_LEFT:
		menuHighlight--;
		if(menuHighlight<0) menuHighlight = 0;
		break;
	    case KEY_RIGHT:
		menuHighlight++;
		if(menuHighlight>2) menuHighlight = 2;
		break;
	    default:
		break;
	}         
	if (menuChoice == ENTER) break ;
	wrefresh(menuWin);
    }   
    werase(menuWin);
    box(menuWin,0,0);
    if (mItem[menuHighlight].menuText == "HELP") {
	mvwprintw(menuWin, 2, 1, "This is track game. \
		Lets see how window works. \ 
		should i ceck size ? :D");
    }
    else {
	mvwprintw(menuWin,2,1,"in construction");
    }
    wrefresh(menuWin);
    return menuHighlight;
}
