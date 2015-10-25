#include<stdio.h>
#include<string.h>
#include"libman.h"
#include<stdlib.h>
int found = 0;
void searchname(Book *b, FILE *fp, char bname[]);
void searchid(Book *b, FILE *fp, int id);
void searchid(Book *b, FILE *fp, int id){
       		 if(b->id == id) {       
                	printf("\n\tThe book is available\n");
                        printf("\tID : %d\n\tNAME : %s\n\tAUTHOR : %s\n\tQUANTITY : %d\n\tPRICE : %f\n\tRACK NO : %d\n\n", 
			b->id, b->name, b->author, b->quantity, b->price, b->rackno);
                        found = 1;
                   }
}
void searchname(Book *b, FILE *fp, char bname[]){
	       	if(strcmp(b->name, bname) == 0){
			printf("\n\tThe book is available\n");
                        printf("\tID : %d\n\tNAME : %s\n\tAUTHOR : %s\n\tQUANTITY : %d\n\tPRICE : %f\n\tRACK NO : %d\n\n", 
			b->id, b->name, b->author, b->quantity, b->price, b->rackno);
                        found = 1;
                   }
                 
}                                 
void searchentry() {
	system("clear");
	FILE *fp;
	Book b;
	int g, id;
	char c, ch, option = 'y';
	char bname[20];
	printf("\t\t ~~~~~~ SEARCH BOOKS ~~~~~~\n\n");
	while(option == 'y' || option == 'Y') {
		printf("\tA. Search by ID\n");
		printf("\tB. Search by name\n");
		printf("\tEnter your choice");
		fflush(stdin);
		scanf(" %c",&c);
		switch(c) {
			case 'A' :
				printgen();
				scanf("%d", &g);
				switch(g) {
					case FICTION :
						fp = fopen("Fiction.dat","rb+");
						printf("Enter  book id:");
						scanf("%d",&id);
						while(fread(&b, sizeof(b), 1, fp) == 1) {
							searchid(&b, fp, id);
						}
						printf("Go to main menu ? (y/n) ");
						scanf(" %c", &ch);
						if(ch == 'y' || ch == 'Y') {
							mainmenu();
							return;
						}
						break;				
					case NONFICTION :
						 fp = fopen("Nonfiction.dat","rb+");
                                	         printf("Enter  book id:");
                                        	 scanf("%d",&id);
                                        	 while(fread(&b, sizeof(b), 1, fp) == 1) {
                                                	searchid(&b, fp, id);
                                        	 }
                                        	 break;
					 case REFERENCE :
						fp = fopen("Reference.dat","rb+");
                        	                printf("Enter  book id:");
                                	        scanf("%d",&id);
                                        	while(fread(&b, sizeof(b), 1, fp) == 1) {
                                                	searchid(&b, fp, id);
                                       		}
                                       		break;
					case SELFHELP :
						fp = fopen("Selfhelp.dat","rb+");
        	                                printf("Enter  book id:");
                	                        scanf("%d",&id);
                        	                while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	                searchid(&b, fp, id);
                                        	}
						break;
					case MENU :
						mainmenu();
						return;
						break;
					}
				break;
		
			case 'B' :
				printgen();
				scanf("%d",&g);
				 switch(g) {
	                                case FICTION :
        	                                fp = fopen("Fiction.dat","rb+");
                	                        printf("Enter  book name:");
                        	                scanf("%s", bname);
                                	        while(fread(&b, sizeof(b), 1, fp) == 1) {
	                                                searchname(&b, fp, bname);
        	                                }
                	                        break;
                        	        case NONFICTION :
                                	         fp = fopen("Nonfiction.dat","rb+");
                                        	 printf("Enter  book name:");
	                                         scanf("%s", bname);
        	                                 while(fread(&b, sizeof(b), 1, fp) == 1) {
                	                                searchname(&b, fp, bname);
                        	                 }
                                	         break;
	                                 case REFERENCE :
        	                                fp = fopen("Reference.dat","rb+");
                	                        printf("Enter  book name:");
                        	                scanf("%s", bname);
                                	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        	        searchname(&b, fp, bname);
                       	        	         }	
                        	                break;
	                                case SELFHELP :
        	                                fp = fopen("Selfhelp.dat","rb+");
                	                        printf("Enter  book name:");
                        	                scanf("%s", bname);
                                	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        	        searchname(&b, fp, bname);
						}
						break;
					case MENU :
						mainmenu();
						return;
						break;
					}
				break;
			}
		printf("\tSearch again ? (y/n) ");
		scanf(" %c", &option);
	}
}
