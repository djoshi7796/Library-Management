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
#include<stdio.h>
void issue(student *std, Book *b, FILE *fp, FILE *ft, int id, int *found);
struct tm *gettodate();
struct tm *gettodate() {
	time_t t;
	time(&t);
	struct tm *currtime = localtime(&t);
	return currtime;
}

/*This function writes details into the issued books file*/

void issue(student *std, Book *b, FILE *fp, FILE *ft, int id, int *found) {
	struct tm *todate = gettodate();
	if(b->id == id) {
		mvaddstr(15,32,"Record available");
		mvprintw(17,32,"Book name : %s", b->name);
		mvprintw(18,32,"No of copies on shelf : %d", b->quantity);
		mvaddstr(20,32,"Enter name : ");
		scanw("%s", std->name);
		mvaddstr(21,32,"Enter Roll NO.");
		scanw("%ld",&std->roll);
		std->issued = *b;
		std->issue_date.day = todate->tm_mday;
		std->issue_date.month = todate->tm_mon + 1;
		std->issue_date.year = todate->tm_year + YEAR;
		std->due_date.day = std->issue_date.day + DAYSDUE;
		std->due_date.month = std->issue_date.month;
		std->due_date.year = std->issue_date.year;
		if(std->due_date.day > 30) {
			std->due_date.month += 1;
			std->due_date.day -= 30;
		}
		if(std->due_date.month > 12) {
			std->due_date.year += 1;
			std->due_date.month -= 12;
		}
		mvprintw(23,32,"ISSUED ON : %d - %d - %d", std->issue_date.day, std->issue_date.month, std->issue_date.year);
		mvprintw(24,32,"DUE DATE : %d - %d - %d", std->due_date.day, std->due_date.month, std->due_date.year);
		std->issued.quantity = 0;
		b->quantity = b->quantity - 1;
		fseek(fp, ftell(fp) - sizeof(Book), 0);
		fwrite(b, sizeof(Book), 1, fp);
		fwrite(std, sizeof(student), 1, ft);
		*found = 1;
	}
}

/*This function opens relevant files for issuing books*/
		
void issuebooks() {
	FILE *fp, *fis;
	student std;
	Book b;
	char option = 'y';
	system("clear");

	while(option == 'y' || option == 'Y') {
		mvaddstr(1,60,"~~~~~~~~ ISSUE BOOKS ~~~~~~~~");
		printgen();
		int c, id, found = 0;
		scanw("%d",&c);
		switch(c) {
			case FICTION : 
					fp = fopen("Fiction.dat","rb+");
					fis = fopen("Issuefict.dat","ab+");
					mvaddstr(13,32,"Enter id ");
					scanw("%d", &id);
					while(fread(&b, sizeof(b), 1, fp) == 1)
						issue(&std, &b, fp, fis, id, &found);
					fclose(fp);
					fclose(fis);
					if(!found) 
						mvaddstr(14,32,"Record not found");
					break;
			case NONFICTION :
					fp = fopen("Nonfiction.dat","rb+"); 
                	                fis = fopen("Issuenfict.dat","ab+");     
                        	        mvaddstr(13,32,"Enter id "); 
                               		scanw("%d", &id);
	                                while(fread(&b, sizeof(b), 1, fp) == 1)
        	                                issue(&std, &b, fp, fis, id, &found);
					fclose(fp);
					fclose(fis);
					if(!found) 
                        	                mvaddstr(14,32,"Record not found");
					break;
			case REFERENCE :
					fp = fopen("Reference.dat","rb+"); 
                	                fis = fopen("Issueref.dat","ab+");     
                        	        mvaddstr(13,32,"Enter id"); 
                                	scanw("%d", &id);
	                                while(fread(&b, sizeof(b), 1, fp) == 1)
        	                                issue(&std, &b, fp, fis, id, &found);
					fclose(fp);
					fclose(fis);
					if(!found) 
                        	                mvaddstr(14,32,"Record not found");
					break;
			case SELFHELP:
					fp = fopen("Selfhelp.dat","rb+"); 
                        	        fis = fopen("Issuesh.dat","ab+");     
                                	mvaddstr(13,32,"Enter id"); 
	                                scanw("%d", &id);
        	                        while(fread(&b, sizeof(b), 1, fp) == 1)
                	                        issue(&std, &b, fp, fis, id, &found);
					fclose(fp);
					fclose(fis);
					if(!found) 
                                	        mvaddstr(14,32,"Record not found");
					break;
			case MENU:
					mainmenu();
					return;
			default :
					mvaddstr(13,32,"Wrong option. Press enter to return to issue menu");
					issuebooks();
					return;

		}
		mvaddstr(26,32,"Issue more ? (y/n) ");
		scanw(" %c", &option);
	}
	mvaddstr(27,32,"Press enter to return to main menu");
	getch();
	mainmenu();
}
