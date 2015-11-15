/*This file is a part of Library-Management

    Library-Management is a free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/


#include"libman.h"
#include<stdlib.h>
void printgen() {				/*Prints genre menu*/
	int y, x;
	clear();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	attron(A_BOLD);
	for(x = 44; x < 100; x++) {
		attron(COLOR_PAIR(1));
		printw("*");
		move(0, x);
		attroff(COLOR_PAIR(1));
	}
	for(y = 0; y < 11; y++) {
		attron(COLOR_PAIR(1));
		printw("*");
		move(y, 44);
		attroff(COLOR_PAIR(1));
	}
	for(x = 44; x < 100; x++) {
		attron(COLOR_PAIR(1));
		printw("*");
		move(11, x);
		attroff(COLOR_PAIR(1));
	}
	for(y = 0; y < 11; y++) {
		attron(COLOR_PAIR(1));
		printw("*");
		move(y, 100);
		attroff(COLOR_PAIR(1));
	}
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(2));
        border(0,0,0,0, 0,0,0,0);
        refresh();
        attroff(COLOR_PAIR(2));
        refresh();	
	mvaddstr(2,60," ----- SELECT GENRES -----");
	mvaddstr(4,48,"1. Fiction");
	mvaddstr(5,48,"2. Non-fiction");
	mvaddstr(6,48,"3. Reference");
	mvaddstr(7,48,"4. Self-help");
	mvaddstr(8,48,"5. Back to main menu");
	mvaddstr(9,48,"Enter your choice:");
   	refresh();
}
void printfiction() {					/*Prints subgenres of fiction*/
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	mvprintw(13,28,"SELECT SUBCATEGORY");
	mvprintw(15,28,"1. Mystery");
	mvprintw(16,28,"2. Drama");
	mvprintw(17,28,"3. Young adult");
	mvprintw(18,28,"4. Horror");
	mvprintw(19,28,"5. Historic");
	mvprintw(20,28,"6. Conspiracy theory");
	mvprintw(21,20,"Enter your choice");
	refresh();
}
void printref() {
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	mvprintw(13,28,"SELECT SUBCATEGORY");
	mvprintw(15,28,"1. Business");
	mvprintw(16,28,"2. Computers");
	mvprintw(17,28,"3. Arts");
        mvprintw(18,28,"4. Medicine");
	mvprintw(19,28,"5. Economics");
        mvprintw(20,28,"6. History");
	mvprintw(21,28,"7. Geography");
        mvprintw(22,28,"8. Architecture");
	mvprintw(23,28,"9. Engineering");
        mvprintw(24,28,"10. Psychology");
	mvprintw(25,20,"Enter your choice");
	refresh();
}
void printselfhelp() {
	init_pair(2,COLOR_MAGENTA,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	mvprintw(13,28,"SELECT SUBCATEGORY");
	mvprintw(15,28,"1. Fine arts");
        mvprintw(16,28,"2. Culinary skills");
        mvprintw(17,28,"3. Languages");
        mvprintw(18,28,"4. Communication skills");
        mvprintw(19,28,"5. Encyclopaedias");
        mvprintw(20,20,"Enter your choice");
	refresh();
}
void intro() {
	clear();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);			/*Setting backgrnd and foregrnd*/
	bkgd(COLOR_PAIR(1));
	attron(A_BOLD);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);			/*Setting borders*/
        attron(COLOR_PAIR(2));
        border(0,0,0,0, 0,0,0,0);
        refresh();
        attroff(COLOR_PAIR(2));
        refresh();
	init_pair(3,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(3));
	refresh();
	mvaddstr(2,60," ~*~*~*~*~* WELCOME *~*~*~*~*~");	/*Printing main menu*/
	attroff(COLOR_PAIR(3));
	refresh();
	mvaddstr(5,48,"Please select an option");
	mvaddstr(7,48,"1. Add books");
	mvaddstr(9,48,"2. Display books");
	mvaddstr(11,48,"3. Search a book");
	mvaddstr(13,48,"4. Delete a record");
	mvaddstr(15,48,"5. Edit a record");
	mvaddstr(17,48,"6. Issue a book");
	mvaddstr(19,48,"7. View issued books");
	mvaddstr(21,48,"8. Return a book");
	mvaddstr(23,48,"9. Close application");
	refresh();
}	
