#include<stdio.h>
#include<time.h>
#include"libman.h"

void returnb(student *std, FILE *fp, FILE *ft, long int roll_no, int *found) {
	char c;
	int fine;
	struct tm *t = gettodate();
	date today;
	today.day = t->tm_mday;
	today.month = t->tm_mon + 1;
	today.year = t->tm_year + YEAR;
	if(roll_no == std->roll) {
		printf("\tBook id : %d", std->issued.id);
		printf("\n\tBook name : %s", std->issued.name);			
		printf("\n\tDUE DATE : %d - %d - %d", std->due_date.day, std->due_date.month, std->due_date.year);
		*found = 1;
		printf("\n\tReturn book ? (y/n)");
		scanf(" %c", &c);
		if(c == 'y' || c == 'Y') {
			if(!(fine = calcfine(today, std->due_date)))
				printf("\tBook returned");
			else 
				printf("\t You have crossed the due date.\n\tPLease pay a fine of Rs. %d ", fine);
		}
	}
}	
	
void returnbooks() {
	Book b;
	student std;
	FILE *fp, *fis;
	long int roll_no;
	int d, found = 0;
	char option = 'y';
	while(option == 'y' || option == 'Y') {
		printgen();
		scanf("%d", &d);
		switch(d) {
			case FICTION :
					fp = fopen("Ficiton.dat","rb+");
					fis = fopen("Issuefict","rb+");
					printf("\tEnter roll no ");
					scanf("%ld",&roll_no);
					while(fread(&std, sizeof(std), 1, fis)) {
						returnb(&std, fp, fis, roll_no, &found);
					}
					if(!found)
						printf("\tRoll no not found.");
					break;
			case NONFICTION :
					 fp = fopen("Nonficiton.dat","rb+");
                                         fis = fopen("Issuenfict","rb+");
                                         printf("\tEnter roll no ");
                                         scanf("%ld",&roll_no);
                                         while(fread(&std, sizeof(std), 1, fis)) {
                                                returnb(&std, fp, fis, roll_no, &found);
                                         } 
                                         if(!found)
                                                 printf("\tRoll no not found.");
                                         break;
			case REFERENCE :
					 fp = fopen("Reference.dat","rb+");
                                         fis = fopen("Issueref","rb+");
                                         printf("\tEnter roll no ");
                                         scanf("%ld",&roll_no);
                                         while(fread(&std, sizeof(std), 1, fis)) {
                                                returnb(&std, fp, fis, roll_no, &found);
                                         } 
                                         if(!found)
                                                printf("\tRoll no not found.");
                                         break;
			case SELFHELP :
					 fp = fopen("Selfhelp.dat","rb+");
                                         fis = fopen("Issuesh","rb+");
                                         printf("\tEnter roll no ");
                                         scanf("%ld",&roll_no);
                                         while(fread(&std, sizeof(std), 1, fis)) {
                                                returnb(&std, fp, fis, roll_no, &found);
                                         }
                                         if(!found)
                                                printf("\tRoll no not found.");
                                         break;
			case MENU :
					mainmenu();
					return;
					break;
		}
	printf("\tReturn more books? (y/n) ");
	scanf(" %c", &option);
		if(option == 'n' || option == 'N') {
			printf("\tGo to main menu ? (y/n) ");
			scanf(" %c", &option);
			if(option == 'Y' || option == 'y'){
				mainmenu();
				return;
			}
		}
	}
} 
	
	




