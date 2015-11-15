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


#include<ncurses.h>
#include<time.h>
#define YEAR 1900
#define DAYSDUE 7
typedef struct books{
    int id;
    char name[20];
    char author[20];
    int quantity;
    int rackno;
    char *cat;
    char *subcat;
}Book;
typedef struct date{
	int day, month, year;
}date;
typedef struct student{
	char name[20];
	long int roll;
	Book issued;
	date issue_date;
	date due_date;
}student;
enum Genres {FICTION = 1, NONFICTION, REFERENCE, SELFHELP, MENU};
void mainmenu();
void addentry();
void intro();
void printentry();
void printgenres();
void printfiction();
void printref();
void printselfhelp();
void deleteentry();
void editentry();
void searchentry();
void issuebooks();
void displayissue();
void returnbooks();
int  getinfo(Book *b);
void Password();
int calcfine(date, date);

