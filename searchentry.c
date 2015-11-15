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


#include<string.h>
#include"libman.h"
#include<stdlib.h>

void searchname(Book *b, FILE *fp, char bname[], int *found);
void searchid(Book *b, FILE *fp, int id, int *found);

/*Search by id*/
void searchid(Book *b, FILE *fp, int id, int *found){
       		 if(b->id == id) {       
                	mvaddstr(14,32,"The book is available");
                        mvprintw(15,32,"ID : %d\n\t\t\t\tNAME : %s\n\t\t\t\tAUTHOR : %s\n\t\t\t\tQUANTITY : %d\n\t\t\t\tRACK NO : %d\n\n", 
			b->id, b->name, b->author, b->quantity, b->rackno);
                        *found = 1;
                   }
}

/*Search by name*/
void searchname(Book *b, FILE *fp, char bname[], int *found){
	       	if(strcmp(b->name, bname) == 0){
			mvaddstr(14,32,"The book is available");
                        mvprintw(15,32,"ID : %d\n\t\t\t\tNAME : %s\n\t\t\t\tAUTHOR : %s\n\t\t\t\tQUANTITY : %d\n\t\t\t\tRACK NO : %d\n\n", 
			b->id, b->name, b->author, b->quantity, b->rackno);
                        *found = 1;
                   }
                 
}                                 

void searchentry() {
	system("clear");
	printw("#######");
	FILE *fp;
	Book b;
	int g, id, found = 0;
	char c, ch, option = 'y';
	char bname[20];
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	mvaddstr(1,60," ~~~~~~ SEARCH BOOKS ~~~~~~");
	refresh();
	while(option == 'y' || option == 'Y') {
		mvaddstr(3,32,"A. Search by ID");
		mvaddstr(5,32,"B. Search by name");
		mvaddstr(7,32,"Enter your choice");
		fflush(stdin);
		scanw(" %c",&c);
		switch(c) {
			case 'A' :
				printgen();
				addstr("(Genre to be searched) ");
				scanw("%d", &g);
				switch(g) {
					case FICTION :
							fp = fopen("Fiction.dat","rb+");
							mvaddstr(13,32,"Enter  book id:");
							scanw("%d",&id);
							while(fread(&b, sizeof(b), 1, fp) == 1) {
								searchid(&b, fp, id, &found);
							}
							fclose(fp);
							if(!found)
								mvaddstr(14,32,"Record not found.");
							break;				
					case NONFICTION :
							 fp = fopen("Nonfiction.dat","rb+");
        	                        	         mvaddstr(13,32,"Enter  book id:");
                        	                	 scanw("%d",&id);
                                	        	 while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        	        	searchid(&b, fp, id, &found);
                                        		 }
							 fclose(fp);
							 if(!found)
                                	                        mvaddstr(14,32,"Record not found.");
                                        		 break;
					 case REFERENCE :
							fp = fopen("Reference.dat","rb+");
                        	               		mvaddstr(13,32,"Enter  book id:");
                                	        	scanw("%d",&id);
	                                        	while(fread(&b, sizeof(b), 1, fp) == 1) {
        	                                        	searchid(&b, fp, id, &found);
                	                       		}
							fclose(fp);
							if(!found)
                                	                        mvaddstr(14,32,"Record not found.");
                                       			break;
					case SELFHELP :
							fp = fopen("Selfhelp.dat","rb+");
	        	                                mvaddstr(13,32,"Enter  book id:");
        	        	                        scanw("%d",&id);
                	        	                while(fread(&b, sizeof(b), 1, fp) == 1) {
                        	        	                searchid(&b, fp, id, &found);
                                	        	}
							fclose(fp);
							if(!found)
                                                	        mvaddstr(14,32,"Record not found.");
							break;
					case MENU :
							mainmenu();
							return;
							break;
					default :
							mvaddstr(13,32,"Wrong option. Press enter to search again. ");
							getch();
							refresh();
							searchentry();
							return;
						}
					break;
		
			case 'B' :
				printgen();
				scanw("%d",&g);
				 switch(g) {
	                                case FICTION :
	        	                                fp = fopen("Fiction.dat","rb+");
        	        	                        mvaddstr(13,32,"Enter book name:");
                	        	                getstr(bname);
                        	        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                        	                       		 searchname(&b, fp, bname, &found);
        	                        	        }
							fclose(fp);
							if(!found)
                                                                mvaddstr(14,32,"Record not found.");
                	                        	break;
                        	        case NONFICTION :
	                                	         fp = fopen("Nonfiction.dat","rb+");
        	                                	 mvaddstr(13,32,"Enter book name:");
	        	                                 getstr(bname);
        	        	                         while(fread(&b, sizeof(b), 1, fp) == 1) {
                	        	                        searchname(&b, fp, bname, &found);
                        	        	         }
							 fclose(fp);
							 if(!found)
                                                                mvaddstr(14,32,"Record not found.");
                                	        	 break;
	                                 case REFERENCE :
	        	                                fp = fopen("Reference.dat","rb+");
        	        	                        mvaddstr(13,32,"Enter book name:");
                	        	                getstr(bname);
                        	        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        	        searchname(&b, fp, bname, &found);
                       	        		        }
							fclose(fp);	
                        	                	break;
	                                case SELFHELP :
	        	                                fp = fopen("Selfhelp.dat","rb+");
        	        	                        mvaddstr(13,32,"Enter  book name:");
                	        	                getstr(bname);
                        	        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        	        searchname(&b, fp, bname, &found);
							}
							fclose(fp);
							if(!found)
                                                                mvaddstr(14,32,"Record not found.");
							break;
					case MENU :
							mainmenu();
							return;
							break;
					default :
							mvaddstr(13,32,"Wrong option. Press enter to search again ");
							getch();
							clear();
							refresh();
							searchentry();
							return;
					}
				break;
			default :
					mvaddstr(13,32,"Wrong option. Press enter to search again");
					getch();
					refresh();
					clear();
					refresh();
					searchentry();
					return;
		}
		mvaddstr(21,16,"Search again ? (y/n) ");
		scanw("%c", &option);
		clear();
		refresh();
	}
	mvaddstr(22,16,"Press enter to return to main menu");
	getch();
	mainmenu();
	return;
}
