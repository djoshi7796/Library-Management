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
#include"libman.h"
struct tm *gettodate1();
struct tm *gettodate1() {			/*Gets system date */
        time_t t;
        time(&t);
        struct tm *currtime = localtime(&t);
        return currtime;
}
void returnb(student *std, FILE *fp, FILE *ft, FILE *f, long int roll_no, int *found) {
	char c;
	int fine;
	Book b;
	struct tm *t = gettodate1();
	date today;
	today.day = t->tm_mday;
	today.month = t->tm_mon + 1;
	today.year = t->tm_year + YEAR;
	if(roll_no == std->roll) {
		mvprintw(15,32,"Book id : %d", std->issued.id);
		mvprintw(16,32,"Book name : %s", std->issued.name);			
		mvprintw(17,32,"DUE DATE : %d - %d - %d", std->due_date.day, std->due_date.month, std->due_date.year);
		*found = 1;
		mvaddstr(18,32,"Return book ? (y/n)");
		scanw(" %c", &c);
		if(c == 'y' || c == 'Y') {
			if(!(fine = calcfine(today, std->due_date)))			/*Calcfine calculates fine to be paid*/
				mvaddstr(20,32,"Book returned");
			else 
				mvprintw(20,32,"You have crossed the due date. Please pay a fine of Rs. %d ", fine);
			rewind(ft);
        		while(fread(std, sizeof(student), 1, ft)) {
                		if(roll_no != std->roll)
                        		fwrite(std, sizeof(student), 1, f);
        		}
			rewind(fp);
			while(fread(&b, sizeof(Book), 1, fp) == 1) {
				if(b.id == std->issued.id) {
					b.quantity = b.quantity + 1;
					fseek(fp, ftell(fp) - sizeof(Book), 0);
					fwrite(&b, sizeof(Book), 1, fp);
				}
			}
					
		}
	*found = 1;
	}
}	
	
void returnbooks() {
	Book b;
	student std;
	FILE *fp, *fis, *f;
	f = fopen("temp.dat","ab+");
	long int roll_no;
	mvaddstr(1,60,"~~~~~~ RETURN BOOKS ~~~~~~");
	int d, found = 0;
	char option = 'y';
	while(option == 'y' || option == 'Y') {
		printgen();
		scanw("%d", &d);
		switch(d) {
			case FICTION :
					fp = fopen("Fiction.dat","rb+");
					fis = fopen("Issuefict.dat","rb+");
					mvaddstr(13,32,"Enter roll no ");
					scanw("%ld",&roll_no);
					while(fread(&std, sizeof(std), 1, fis) == 1) {
						returnb(&std, fp, fis, f, roll_no, &found);
					}
					fclose(fp);
					fclose(fis);
					fclose(f);
					remove("Issuefict.dat");
					rename("temp.dat","Issuefict.dat");
					if(!found)
						mvaddstr(14,32,"Roll no not found.");
					break;
			case NONFICTION :
					 fp = fopen("Nonficiton.dat","rb+");
                                         fis = fopen("Issuenfict.dat","rb+");
                                         mvaddstr(13,32,"Enter roll no ");
                                         scanw("%ld",&roll_no);
                                         while(fread(&std, sizeof(std), 1, fis) == 1) {
						printw("\t\t\t $$$$ %ld $$$$ ", std.roll);
                                                returnb(&std, fp, fis, f, roll_no, &found);
                                         }
					 fclose(fp);
					 fclose(fis);
					 fclose(f);
                                         remove("Issuenfict.dat");
                                         rename("temp.dat","Issuenfict.dat"); 
                                         if(!found)
                                                 mvaddstr(14,32,"Roll no not found.");
                                         break;
			case REFERENCE :
					 fp = fopen("Reference.dat","rb+");
                                         fis = fopen("Issueref.dat","rb+");
                                         mvaddstr(13,32,"Enter roll no ");
                                         scanw("%ld",&roll_no);
                                         while(fread(&std, sizeof(std), 1, fis) == 1) {
                                                returnb(&std, fp, fis, f, roll_no, &found);
                                         } 
					 fclose(fp);
					 fclose(fis);
					 fclose(f);
                                         remove("Issueref.dat");
                                         rename("temp.dat","Issueref.dat");
                                         if(!found)
                                                mvaddstr(14,32,"Roll no not found.");
                                         break;
			case SELFHELP :
					 fp = fopen("Selfhelp.dat","rb+");
                                         fis = fopen("Issuesh.dat","rb+");
                                         mvaddstr(13,32,"Enter roll no ");
                                         scanw("%ld",&roll_no);
                                         while(fread(&std, sizeof(std), 1, fis) == 1) {
                                                returnb(&std, fp, fis, f, roll_no, &found);
                                         }
					 fclose(fp);
					 fclose(fis);
					 fclose(f);
                                         remove("Issuesh.dat");
                                         rename("temp.dat","Issuesh.dat");
                                         if(!found)
                                                mvaddstr(14,32,"Roll no not found.");
                                         break;
			case MENU :
					mainmenu();
					return;
					break;
			default :
				mvaddstr(13,32,"Wrong Option. Press ENTER to go back to return menu");
				refresh();
				returnbooks();
				return;
		}
	mvaddstr(22,32,"Return more books? (y/n) ");
	scanw(" %c", &option);
	}
	mvaddstr(23,32,"Press ENTER to return to main menu ");
	getch();
	mainmenu();
} 
