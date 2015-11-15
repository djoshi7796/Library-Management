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
int Found = 0;

void delete(Book *b, FILE *fp, FILE *fd, int id, int Found) {
		char opt;
		int yes = 0;
		if(b->id == id) {
			mvaddstr(14,32,"Record available");
			mvprintw(15,32,"Book name : %s", b->name);
			mvaddstr(16,32,"Delete book ? (y/n)");
			scanw("%c",&opt);
			if(opt == 'y' || opt == 'Y') {
				Found = 1;
				yes = 1;
			}
			else 
				Found = 1;
		}
		if(Found && yes) {
			rewind(fp);					
			rewind(fd);
			while(fread(b, sizeof(Book), 1, fp)) {			/*Transferring contents into temporary file*/
				if(b->id != id) 
					fwrite(b, sizeof(Book), 1, fd);
			}
			mvaddstr(17,32,"Book successfully deleted");	
		}
			
}			
		
void deleteentry() {
	FILE *fp, *fd;
	Book b;
	int c, id;
	mvaddstr(1,60,"~~~~~~ DELETE BOOKS ~~~~~~");
	char option = 'y';
	Found = 0;
	fd = fopen("temporary.dat","ab+");
	while(option == 'y' || option == 'Y') {
		printgen();
		init_pair(2,COLOR_RED,COLOR_BLACK);		/*Setting border*/
		attron(COLOR_PAIR(2));
		border(0,0,0,0, 0,0,0,0);
		refresh();
		attroff(COLOR_PAIR(2));
		refresh();
		scanw("%d", &c);
		switch(c) {
			case FICTION :	mvaddstr(13,32,"Enter id ");
					scanw("%d",&id);
					fp = fopen("Fiction.dat","rb+");
					while(fread(&b, sizeof(b), 1, fp) == 1) {
						delete(&b, fp, fd, id, Found);
					}
					fclose(fp);
					fclose(fd);
					remove("Fiction.dat"); 				/* Removing old file */ 
					rename("temporary.dat","Fiction.dat");		/* Renaming new file */
					if(!Found)
						mvaddstr(14,32,"Record not found");
					break;
			case NONFICTION :
					mvaddstr(13,32,"Enter id ");
					scanw("%d",&id);
					fp = fopen("Nonfiction.dat","rb+");
                        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        delete(&b, fp, fd, id, Found);
                               		 }
					fclose(fp);
					fclose(fd);
	                                remove("Nonfiction.dat");
        	                        rename("temporary.dat","Nonfiction.dat");
					if(!Found)
                                                mvaddstr(14,32,"Record not found");
					break;
			case REFERENCE :
					mvaddstr(13,32,"Enter id ");
                                        scanw("%d",&id);
					fp = fopen("Reference.dat","rb");
                	                while(fread(&b, sizeof(b), 1, fp) == 1) {
                        	                delete(&b, fp, fd, id, Found);
                                	}
					fclose(fp);
					fclose(fd);
	                                remove("Reference.dat");
        	                        rename("temporary.dat","Reference.dat");
					if(!Found)
                                                mvaddstr(14,32,"Record not found");
					break;
			case SELFHELP :
					mvaddstr(13,32,"Enter id ");
                                        scanw("%d",&id);
					fp = fopen("Selfhelp.dat","rb");
                	                while(fread(&b, sizeof(b), 1, fp) == 1) {
                        	                delete(&b, fp, fd, id, Found);
                                	}
					fclose(fp);
					fclose(fd);
                               		remove("Selfhelp.dat");
                                	rename("temporary.dat","Selfhelp.dat");
					if(!Found)
                                                mvaddstr(14,32,"Record not found");
					break;
			case MENU :
					mainmenu();
					return;
					break;
			default :
					mvaddstr(13,32,"Wrong option. Press ENTER to select again");
					getch();
					deleteentry();
					return;
			
			}
			mvaddstr(19,32,"Delete more? (y/n) ");
			scanw(" %c", &option);
	}
	mvaddstr(21,32,"Press ENTER to go to main menu");
	getch();
	mainmenu();
}
