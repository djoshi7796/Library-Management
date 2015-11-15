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
int main() {
	initscr();		/*Start Ncurses */
	start_color();
	init_pair(1,COLOR_CYAN,COLOR_BLACK);
	bkgd(COLOR_PAIR(1)); 	/*Setting back ground and foreground */
	attron(A_BOLD);
	refresh();
	mainmenu();
	refresh();
	endwin();
	return 0;
}
void mainmenu() {
	
	int choice;
	/*Setting border*/
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	attroff(COLOR_PAIR(2));
	refresh();
	intro(); 		/*Intro() fucntion to print the menu*/
	scanw("%d",&choice);
	switch(choice) {
		case 1:
			addentry();
			break;
		case 2:
			printentry();
			break;
		case 3:
			searchentry();
			break;
		case 4 :
			deleteentry();
			break;
		case 5 :
			editentry();
			break;
		case 6 :
			issuebooks();
			break;
		case 7 :
			displayissue();
			break;
		case 8:
			returnbooks();
			break;
		case 9:
			closeapp();
			break;
	}
}
