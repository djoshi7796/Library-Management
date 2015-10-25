#include<stdio.h>
#include"libman.h"
void printbook(Book *b) {
	printf("\n\tID : %d\n\tNAME : %s\n\tAUTHOR : %s\n\tQUANTITY : %d\n\tPRICE : %.2f\n\tRACK NO : %d\n\t",
		b->id, b->name, b->author, b->quantity, b->price, b->rackno);
}
void printentry() {
	FILE *fp;
	int c;
	char ch;
	Book b;
	system("clear");
	printgen();
	scanf("%d", &c);
	switch(c) {
		case FICTION :
				fp = fopen("Fiction.dat","rb");
				while(fread(&b, sizeof(b), 1, fp) == 1){
					printbook(&b);
				}
				printf("Go to main menu ? (y/n) ");
				scanf(" %c", &ch);
				if(ch == 'y' || ch == 'Y') {
					mainmenu();
					return;
				}
				break;
		case NONFICTION : 
				fp = fopen("Nonfiction.dat","rb");
                                while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        printbook(&b);
                                }
				printf("Go to main menu ? (y/n) ");
                                scanf(" %c", &ch);
                                if(ch == 'y' || ch == 'Y') {
                                        mainmenu();
                                        return;
                                }
				break;
		case REFERENCE :
				 fp = fopen("Reference.dat","rb");
                                 while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        printbook(&b);
                                }
				printf("Go to main menu ? (y/n) ");
                                scanf(" %c", &ch);
                                if(ch == 'y' || ch == 'Y') {
                                        mainmenu();
                                        return;
                                }
				break;
		case SELFHELP :
				 fp = fopen("Selfhelp.dat","rb");
                               	 while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        printbook(&b);
                                }
				printf("Go to main menu ? (y/n) ");
                                scanf(" %c", &ch);
                                if(ch == 'y' || ch == 'Y') {
                                        mainmenu();
                                        return;
                                }
				break;
		default :
			printf("\n ~~~~~ Wrong option. Select again ~~~~~\n\n");
			printentry();
			return;
	}
}
			
