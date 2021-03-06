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
/*This fucntion prints an entry */
void printbook(Book *b, int col) {
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	mvprintw(col,5,"%d",b->id);
	mvprintw(col,15, "%s",b->name);
	mvprintw(col,45,"%s",b->author);
	mvprintw(col,70,"%d",b->quantity);
	mvprintw(col,85,"%d",b->rackno);
	mvprintw(col,100, "%s",b->cat);
	mvprintw(col,120,"%s",b->subcat);
	refresh();
}
/*This function selects the relevent file */
void printentry() {
	refresh();
	FILE *fp;
	int c, col = 5;
	char ch;
	Book b;
	printgen();
	scanw("%d", &c);
	clear();
	refresh();
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	mvaddstr(1,60,"~~~~~~ BOOK LIST ~~~~~~");
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(3));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(3));
	mvaddstr(3,5,"ID");
        mvaddstr(3,15,"NAME");
        mvaddstr(3,45,"AUTHOR");
        mvaddstr(3,70,"QUANTITY");
      	mvaddstr(3,85,"RACKNO");
        mvaddstr(3,100,"GENRE");
        mvaddstr(3,120,"SUBGENRE");
	refresh();
	switch(c) {
		case FICTION :
				fp = fopen("Fiction.dat","rb");
				if(fp == NULL ) {
					mvaddstr(6,48,"~ ~ ~ ~ No books under this genre ~ ~ ~ ~");
					mvaddstr(9,48,"~ ~ ~ ~ Press ENTER to go back to main menu ~ ~ ~ ~ ");
					getch();
					mainmenu();
					return;
				}	
				while(fread(&b, sizeof(b), 1, fp) == 1){
					printbook(&b, col);
					col++;
				}
				mvprintw(30,12,"Press enter to go to main menu");
				getch();
				refresh();
				mainmenu();
				break;
		case NONFICTION : 
				fp = fopen("Nonfiction.dat","rb");
				if(fp == NULL ) {
                                        mvaddstr(6,48,"~ ~ ~ ~ No books under this genre ~ ~ ~ ~");
                                        mvaddstr(9,48,"~ ~ ~ ~ Press ENTER to go back to main menu ~ ~ ~ ~ ");
                                        getch();
                                        mainmenu();
                                        return;
                                }
                                while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        printbook(&b, col);
					col++;
                                }
				mvprintw(30,12,"Press enter to go to main menu");
                                getch();
                                refresh();
                                mainmenu();
				break;
		case REFERENCE :
				fp = fopen("Reference.dat","rb");
				if(fp == NULL ) {
                                        mvaddstr(6,48,"~ ~ ~ ~ No books under this genre ~ ~ ~ ~");
                                        mvaddstr(9,48,"~ ~ ~ ~ Press ENTER to go back to main menu ~ ~ ~ ~ ");
                                        getch();
                                        mainmenu();
                                        return;
                                }
                                while(fread(&b, sizeof(b), 1, fp) == 1) {
                                       printbook(&b, col);
				       col++;
                                }
				mvprintw(30,12,"Press enter to go to main menu");
                                getch();
                                refresh();
                                mainmenu();
				break;
		case SELFHELP :
				fp = fopen("Selfhelp.dat","rb");
				if(fp == NULL ) {
                                        mvaddstr(6,48,"~ ~ ~ ~ No books under this genre ~ ~ ~ ~");
                                        mvaddstr(9,48,"~ ~ ~ ~ Press ENTER to go back to main menu ~ ~ ~ ~ ");
                                        getch();
                                        mainmenu();
                                        return;
                                }
                               	while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        printbook(&b, col);
					col++;
                                }
				mvprintw(30,12,"Press enter to go to main menu");
                                getch();
                                refresh();
                                mainmenu();
				break;
		default :
			printw("\n ~~~~~ Wrong option. Select again ~~~~~\n\n");			
			refresh();
			printentry();
			return;
	}
	refresh();
}
			
