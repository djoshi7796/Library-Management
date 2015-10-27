#define YEAR 1990
typedef struct books{
    int id;
    char name[20];
    char author[20];
    int quantity;
    float price;
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
void returnbooks();
int  getinfo(Book *b);
void Password();
struct tm *gettodate();
int calcfine(date, date);

