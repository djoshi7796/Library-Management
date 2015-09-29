/* This function just demonstrates if addentry works*/
#include"libman.h"
#include<stdio.h>
#include<stdlib.h>
void printentry() {
	int ch, i = 0;
	FILE *fp;
	Book *printbook;
	system("clear");
	printgen();
	scanf("%d",&ch);
	switch(ch){
		
		case FICTION:
			fp = fopen("Fiction.txt","r");
			if(i == 0) 
				printbook = (Book *)malloc(sizeof(Book));
			
			else
				printbook = (Book *)realloc(printbook,sizeof(Book)*(i+1));	
			
			while((fread(&printbook[i], sizeof(Book), 1, fp)) == 1) {
				printf("Entry : %d\n\nName: %s\nAuthor : %s\nQuantity : %d\nPrice : %f\n\n",i+1, printbook[i].name, printbook[i].author, printbook[i].quantity,printbook[i].price);
			
			i++;
			}
			break;

		 case NONFICTION:
                        fp = fopen("Non-fiction.txt","r");
                        if(i == 0)
                                printbook = (Book *)malloc(sizeof(Book));

                        else
                                printbook = (Book *)realloc(printbook,sizeof(Book)*(i+1));

                        while((fread(&printbook[i], sizeof(Book), 1, fp)) == 1) {
                                printf("Entry : %d\n\nName: %s\nAuthor : %s\nQuantity : %d\nPrice : %f\n\n",i+1, printbook[i].name, printbook[i].author, printbook[i].quantity,printbook[i].price);

                        i++;
                        }
                        break;

		 case REFERENCE:
                        fp = fopen("Reference.txt","r");
                        if(i == 0)
                                printbook = (Book *)malloc(sizeof(Book));

                        else
                                printbook = (Book *)realloc(printbook,sizeof(Book)*(i+1));

                        while((fread(&printbook[i], sizeof(Book), 1, fp)) == 1) {
                                printf("Entry : %d\n\nName: %s\nAuthor : %s\nQuantity : %d\nPrice : %f\n\n",i+1, printbook[i].name, printbook[i].author, printbook[i].quantity,printbook[i].price);

                        i++;
                        }
                        break;

		 case SELFHELP:
                        fp = fopen("Self-help.txt","r");
                        if(i == 0)
                                printbook = (Book *)malloc(sizeof(Book));

                        else
                                printbook = (Book *)realloc(printbook,sizeof(Book)*(i+1));

                        while((fread(&printbook[i], sizeof(Book), 1, fp)) == 1) {
                                printf("Entry : %d\n\nName: %s\nAuthor : %s\nQuantity : %d\nPrice : %f\n\n",i+1, printbook[i].name, printbook[i].author, printbook[i].quantity,printbook[i].price);

                        i++;
                        }
                        break;



		}
}
			
