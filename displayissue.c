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
void printissue(student *std, int col) {
	init_pair(2,COLOR_MAGENTA,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	mvprintw(col,5,"%ld",std->roll);
	mvprintw(col,25, "%s",std->name);
	mvprintw(col,45,"%d",std->issued.id);
	mvprintw(col,65,"%s",std->issued.name);
	mvprintw(col,95,"%d-%d-%d",std->issue_date.day, std->issue_date.month, std->issue_date.year);
	mvprintw(col,120,"%d-%d-%d",std->due_date.day, std->due_date.month, std->due_date.year);
	refresh();
}
void displayissue() {
	refresh();
	FILE *fp;
	int c, col = 5;
	char ch;
	student std;
	printgen();
	scanw("%d", &c);
	clear();
	refresh();
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	mvaddstr(1,60,"~~~~~~ LIST OF BOOKS ISSUED ~~~~~~");
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(3));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(3));
	refresh();
	mvaddstr(3,5,"ROLL NO");
	mvaddstr(3,25,"NAME");
	mvaddstr(3,45,"BOOK ID");
	mvaddstr(3,65,"BOOK NAME");
	mvaddstr(3,95,"ISSUE DATE");
	mvaddstr(3,120,"DUE DATE");
	switch(c) {
		case FICTION :
				fp = fopen("Issuefict.dat","rb");
				if(fp == NULL) {
					mvaddstr(6, 48, "~ ~ ~ ~ No books have been issued in this genre ~ ~ ~ ~");
					mvaddstr(9,48, "~ ~ ~ ~ Press ENTER to return to main menu ~ ~ ~ ~");
					getch();
					mainmenu();
					return;
				}
				while(fread(&std, sizeof(std), 1, fp) == 1){
					printissue(&std, col);
					col++;
				}
				fclose(fp);
				mvprintw(30,12,"Press enter to go to main menu");
				getch();
				refresh();
				mainmenu();
				break;
		case NONFICTION : 
				fp = fopen("Issuenfict.dat","rb");
				if(fp == NULL) {
                                        mvaddstr(6, 48, "~ ~ ~ ~ No books have been issued in this genre ~ ~ ~ ~");
                                        mvaddstr(9,48, "~ ~ ~ ~ Press ENTER to return to main menu ~ ~ ~ ~");
                                        getch();
                                        mainmenu();
                                        return;
                                }
                                while(fread(&std, sizeof(std), 1, fp) == 1) {
                                        printissue(&std, col);
					col++;
                                }
				fclose(fp);
				mvprintw(30,12,"Press enter to go to main menu");
                                getch();
                                refresh();
                                mainmenu();
				break;
		case REFERENCE :
				 fp = fopen("Issueref.dat","rb");
				 if(fp == NULL) {
                                        mvaddstr(6, 48, "~ ~ ~ ~ No books have been issued in this genre ~ ~ ~ ~");
                                        mvaddstr(9,48, "~ ~ ~ ~ Press ENTER to return to main menu ~ ~ ~ ~");
                                        getch();
                                        mainmenu();
                                        return;
                                }
                                while(fread(&std, sizeof(std), 1, fp) == 1) {
                                        printissue(&std, col);
					col++;
                                }
				fclose(fp);
				mvprintw(30,12,"Press enter to go to main menu");
                                getch();
                                refresh();
                                mainmenu();
				break;
		case SELFHELP :
				fp = fopen("Issuesh.dat","rb");
				if(fp == NULL) {
                                        mvaddstr(6, 48, "~ ~ ~ ~ No books have been issued in this genre ~ ~ ~ ~");
                                        mvaddstr(9,48, "~ ~ ~ ~ Press ENTER to return to main menu ~ ~ ~ ~");
                                        getch();
                                        mainmenu();
                                        return;
                                }
                               	while(fread(&std, sizeof(std), 1, fp) == 1) {
                                        printissue(&std, col);
					col++;
                                }
				fclose(fp);
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
			
