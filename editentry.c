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


#include<stdio.h>
#include<stdlib.h>
#include"libman.h"
int foundd = 0;


void edit(Book *b, FILE *fp, int id) {
	if(b->id == id) {
		mvaddstr(15,32,"The book is available");
		mvaddstr(17,32,"Enter new name ");
		getstr(b->name);
		mvaddstr(18,32,"Enter new author name ");
		getstr(b->author);
		mvaddstr(19,32,"Enter new quantity ");
		scanw("%d", &b->quantity);
		mvaddstr(20,32,"Enter new rackno ");
		scanw("%d", &b->rackno);
		mvaddstr(21,40,"~~ RECORD MODIFIED ~~");
		fseek(fp, ftell(fp) - sizeof(Book), 0);		/*Updating modified record */
		fwrite(b, sizeof(Book), 1, fp);
		foundd = 1;
	}

}

void editentry() {
	system("clear");
	init_pair(2,COLOR_MAGENTA,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	attroff(COLOR_PAIR(2));
	mvaddstr(1,60,"~~~~~~ EDIT BOOK RECORDS ~~~~~~");
	int id, c;
	char option = 'y';
	Book b;
	FILE *fp;
	while(option == 'y' || option == 'Y') {
		printgen();
		scanw("%d",&c);
		switch(c) {
			case FICTION :
					fp = fopen("Fiction.dat","rb+");
					mvaddstr(13,32,"Enter book id : ");
					scanw("%d",&id);
					refresh();
					while(fread(&b, sizeof(b), 1, fp) == 1) {
						edit(&b, fp, id);
					}
					fclose(fp);
					if(foundd == 0) 
						mvaddstr(15,32,"Record not found");		
					break;
			case NONFICTION :
					fp = fopen("Nonfiction.dat","rb+");
                                	mvaddstr(13,32,"Enter book id : ");                                        
					scanw("%d",&id);        
                                	while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        edit(&b, fp, id);
					}
					fclose(fp);
					 if(foundd == 0)  
                                                mvaddstr(15,32,"Record not found"); 
					break;
			case REFERENCE :
					fp = fopen("Reference.dat","rb");
                               		mvaddstr(13,32,"Enter book id : ");                                        
					scanw("%d",&id);        
                        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        edit(&b, fp, id);                                          
					 }
					fclose(fp);
					 if(foundd == 0)  
                                                mvaddstr(15,32,"Record not found"); 
					break;
			case SELFHELP :
					fp = fopen("Selfhelp.dat","rb");
                                	mvaddstr(13,32,"Enter book id : ");                                        
					scanw("%d",&id);        
                                	while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        	edit(&b, fp, id);                                            
					}
					fclose(fp);
					 if(foundd == 0)  
                                                mvaddstr(15,32,"Record not found"); 
					break;
			case MENU :
					mainmenu();
					return ;
					break;
		}
		mvaddstr(23,32,"Edit more? (y/n) ");
		scanw("%c", &option);
	}
	mvaddstr(24,32,"Press ENTER to return to main menu");
	getch();
	refresh();
	mainmenu();
}
