#include<stdio.h>
#include<stdlib.h>
#include"libman.h"
int foundd = 0;
void edit(Book *b, FILE *fp, int id) {
	if(b->id == id) {
		printf("\tThe book is available\n");
		printf("\tEnter new name\n");
		scanf("%s", b->name);
		printf("\tEnter new author name\n");
		scanf("%s", b->author);
		printf("\tEnter new quantity\n");
		scanf("%d", &b->quantity);
		printf("\tEnter new price\n");
		scanf("%f", &b->price);
		printf("\tEnter new rackno\n");
		scanf("%d", &b->rackno);
		printf("\t\t~~ RECORD MODIFIED ~~\n");
		fseek(fp, ftell(fp) - sizeof(Book), 0);
		fwrite(b, sizeof(Book), 1, fp);
		fclose(fp);
		foundd = 1;
	}

}

void editentry() {
	system("clear");
	printf("\t\t~~~~~~ EDIT BOOK RECORDS ~~~~~~\n\n");
	int id, c;
	char option = 'y';
	Book b;
	FILE *fp;
	while(option == 'y' || option == 'Y') {
		printgen();
		scanf("%d",&c);
		fflush(stdin);
		switch(c) {
			case FICTION :
					fp = fopen("Fiction.dat","rb+");
					printf("\tEnter book id : ");
					scanf("%d",&id);
					while(fread(&b, sizeof(b), 1, fp) == 1) {
					edit(&b, fp, id);
					}
					if(foundd == 0) 
						printf("\tRecord not found");		
					break;
			case NONFICTION :
					fp = fopen("Nonfiction.dat","rb");
                                	printf("\tEnter book id : ");                                        
					scanf("%d",&id);        
                                	while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        edit(&b, fp, id);
					}
					 if(foundd == 0)  
                                                printf("\tRecord not found"); 
					break;
			case REFERENCE :
					fp = fopen("Reference.dat","rb");
                               		printf("\tEnter book id : ");                                        
					scanf("%d",&id);        
                        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        edit(&b, fp, id);                                          
					 }
					 if(foundd == 0)  
                                                printf("\tRecord not found"); 
					break;
			case SELFHELP :
					fp = fopen("Selfhelp.dat","rb");
                                	printf("\tENter book id : ");                                        
					scanf("%d",&id);        
                                	while(fread(&b, sizeof(b), 1, fp) == 1) {
                                        	edit(&b, fp, id);                                            
					}
					 if(foundd == 0)  
                                                printf("\tRecord not found"); 
					break;
			case MENU :
					mainmenu();
					return ;
					break;
		}
		printf("\n\tEdit more? (y/n) ");
		scanf(" %c", &option);
	}
		
			
	
}
