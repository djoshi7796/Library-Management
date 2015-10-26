#include<stdio.h>
#include<string.h>
#include"libman.h"
#include<stdlib.h>

void searchname(Book *b, FILE *fp, char bname[], int *found);
void searchid(Book *b, FILE *fp, int id, int *found);

void searchid(Book *b, FILE *fp, int id, int *found){
       		 if(b->id == id) {       
                	printf("\n\tThe book is available\n");
                        printf("\tID : %d\n\tNAME : %s\n\tAUTHOR : %s\n\tQUANTITY : %d\n\tPRICE : %f\n\tRACK NO : %d\n\n", 
			b->id, b->name, b->author, b->quantity, b->price, b->rackno);
                        *found = 1;
                   }
}

void searchname(Book *b, FILE *fp, char bname[], int *found){
	       	if(strcmp(b->name, bname) == 0){
			printf("\n\tThe book is available\n");
                        printf("\tID : %d\n\tNAME : %s\n\tAUTHOR : %s\n\tQUANTITY : %d\n\tPRICE : %f\n\tRACK NO : %d\n\n", 
			b->id, b->name, b->author, b->quantity, b->price, b->rackno);
                        *found = 1;
                   }
                 
}                                 

void searchentry() {
	system("clear");
	FILE *fp;
	Book b;
	int g, id, found = 0;
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
							printf("\tEnter  book id:");
							scanf("%d",&id);
							while(fread(&b, sizeof(b), 1, fp) == 1) {
								searchid(&b, fp, id, &found);
							}
							if(!found)
								printf("\tRecord not found.\n");
							break;				
					case NONFICTION :
							 fp = fopen("Nonfiction.dat","rb+");
        	                        	         printf("\tEnter  book id:");
                        	                	 scanf("%d",&id);
                                	        	 while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        	        	searchid(&b, fp, id, &found);
                                        		 }
							 if(!found)
                                	                        printf("\tRecord not found.\n");
                                        		 break;
					 case REFERENCE :
							fp = fopen("Reference.dat","rb+");
                        	               		printf("\tEnter  book id:");
                                	        	scanf("%d",&id);
	                                        	while(fread(&b, sizeof(b), 1, fp) == 1) {
        	                                        	searchid(&b, fp, id, &found);
                	                       		}
							if(!found)
                                	                        printf("\tRecord not found.\n");
                                       			break;
					case SELFHELP :
							fp = fopen("Selfhelp.dat","rb+");
	        	                                printf("\tEnter  book id:");
        	        	                        scanf("%d",&id);
                	        	                while(fread(&b, sizeof(b), 1, fp) == 1) {
                        	        	                searchid(&b, fp, id, &found);
                                	        	}
							if(!found)
                                                	        printf("\tRecord not found.\n");
							break;
					case MENU :
							mainmenu();
							return;
							break;
					default :
							printf("\tWrong option. PLease enter again ");
							searchentry();
							return;
						}
					break;
		
			case 'B' :
				printgen();
				scanf("%d",&g);
				 switch(g) {
	                                case FICTION :
	        	                                fp = fopen("Fiction.dat","rb+");
        	        	                        printf("\tEnter  book name:");
                	        	                scanf("%s", bname);
                        	        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                        	                       		 searchname(&b, fp, bname, &found);
        	                        	        }
                	                        	break;
                        	        case NONFICTION :
	                                	         fp = fopen("Nonfiction.dat","rb+");
        	                                	 printf("\tEnter  book name:");
	        	                                 scanf("%s", bname);
        	        	                         while(fread(&b, sizeof(b), 1, fp) == 1) {
                	        	                        searchname(&b, fp, bname, &found);
                        	        	         }
                                	        	 break;
	                                 case REFERENCE :
	        	                                fp = fopen("Reference.dat","rb+");
        	        	                        printf("\tEnter  book name:");
                	        	                scanf("%s", bname);
                        	        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        	        searchname(&b, fp, bname, &found);
                       	        		        }	
                        	                	break;
	                                case SELFHELP :
	        	                                fp = fopen("Selfhelp.dat","rb+");
        	        	                        printf("\tEnter  book name:");
                	        	                scanf("%s", bname);
                        	        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        	        searchname(&b, fp, bname, &found);
							}
							break;
					case MENU :
							mainmenu();
							return;
							break;
					default :
							printf("\tWrong option. Please enter again ");
							searchentry();
							return;
					}
				break;
			default :
					printf("\t----- Wrong option. Please enter again ------");
					searchentry();
					return;
		}
		printf("\tSearch again ? (y/n) ");
		scanf(" %c", &option);
	}
	printf("\tGo to main menu ? (y/n) ");
	scanf(" %c", &ch);
	if(ch == 'y' || ch == 'Y') {
		mainmenu();
		return;
	}
}
