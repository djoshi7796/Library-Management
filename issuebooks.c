#include"libman.h"
#include<stdio.h>
#include<time.h>
#define YEAR 1900
#define RETURN 7
void issue(student *std, Book *b, FILE *fp, FILE *ft, int id, int *found);
struct tm *gettodate();
struct tm *gettodate() {
	time_t t;
	time(&t);
	struct tm *currtime = localtime(&t);
	return currtime;
}
void issue(student *std, Book *b, FILE *fp, FILE *ft, int id, int *found) {
	struct tm *todate = gettodate();
	if(b->id == id) {
		printf("\tRecord available\n");
		printf("\tBook name : %s\n", b->name);
		printf("\tNo of copies on shelf : %d\n", b->quantity);
		printf("\tEnter name : ");
		scanf("%s", std->name);
		printf("\tEnter Roll NO.");
		scanf("%ld",&std->roll);
		std->issued = *b;
		std->issue_date.day = todate->tm_mday;
		std->issue_date.month = todate->tm_mon + 1;
		std->issue_date.year = todate->tm_year + YEAR;
		std->due_date.day = std->issue_date.day + RETURN;
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
		printf("\tISSUED ON : %d - %d - %d\n", std->issue_date.day, std->issue_date.month, std->issue_date.year);
		printf("\tDUE DATE : %d - %d - %d\n", std->due_date.day, std->due_date.month, std->due_date.year);
		std->issued.quantity = 0;
		b->quantity = b->quantity - 1;
		fseek(fp, ftell(fp) - sizeof(Book), 0);
		fwrite(b, sizeof(Book), 1, fp);
		fwrite(std, sizeof(student), 1, ft);
		*found = 1;
	}
}
		
void issuebooks() {
	FILE *fp, *fis;
	student std;
	Book b;
	char option = 'y';
	system("clear");
	while(option == 'y' || option == 'Y') {
		printf("\t\t\t~~~~~~~~ ISSUE BOOKS ~~~~~~~~\n\n");
		printgen();
		int c, id, found = 0;
		scanf("%d",&c);
		switch(c) {
			case FICTION : 
					fp = fopen("Fiction.dat","rb++");
					fis = fopen("Issuefict.dat","ab+");
					printf("\tEnter id ");
					scanf("%d", &id);
					while(fread(&b, sizeof(b), 1, fp) == 1)
						issue(&std, &b, fp, fis, id, &found);
					if(!found) 
						printf("\tRecord not found\n");
					break;
			case NONFICTION :
					fp = fopen("Nonfiction.dat","rb+"); 
                	                fis = fopen("Issuenfict.dat","ab+");     
                        	        printf("\tEnter id "); 
                               		scanf("%d", &id);
	                                while(fread(&b, sizeof(b), 1, fp) == 1)
        	                                issue(&std, &b, fp, fis, id, &found);
					if(!found) 
                        	                printf("\tRecord not found\n");
					break;
			case REFERENCE :
					fp = fopen("Reference.dat","rb+"); 
                	                fis = fopen("Issueref.dat","ab+");     
                        	        printf("\tEnter id\n"); 
                                	scanf("%d", &id);
	                                while(fread(&b, sizeof(b), 1, fp) == 1)
        	                                issue(&std, &b, fp, fis, id, &found);
					if(!found) 
                        	                printf("\tRecord not found\n");
					break;
			case SELFHELP:
					fp = fopen("Selfhelp.dat","rb+"); 
                        	        fis = fopen("Issuesh.dat","ab+");     
                                	printf("\tEnter id\n"); 
	                                scanf("%d", &id);
        	                        while(fread(&b, sizeof(b), 1, fp) == 1)
                	                        issue(&std, &b, fp, fis, id, &found);
					if(!found) 
                                	        printf("\tRecord not found\n");
					break;
			case MENU:
					mainmenu();
					return;

		}
		printf("\tIssue more ? (y/n) ");
		scanf(" %c", &option);
	}
}
