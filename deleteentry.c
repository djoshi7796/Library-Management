#include<stdio.h>
#include<stdlib.h>
#include"libman.h"
int Found = 0;
void delete(Book *b, FILE *fp, int id, int Found) {
		FILE *fd;
		if(b->id == id) {
			printf("\tRecord available\n");
			printf("\tBook name : %s\n", b->name);
			Found = 1;
		}
		if(Found) {
			fd = fopen("temporary.dat","wb+");
			while(fread(b, sizeof(Book), 1, fp) == 1) {
				if(b->id != id) 
					fwrite(b, sizeof(Book), 1, fd);
			}	
			fclose(fp);
			fclose(fd);
		}
		else
			printf("\tRecord not Found\n");
			
}			
		
void deleteentry() {
	FILE *fp;
	Book b;
	int c, id;
	char option = 'y';
	Found = 0;
	while(option == 'y' || option == 'Y') {
		printgen();
		scanf("%d", &c);
		switch(c) {
			case FICTION :
					fp = fopen("Fiction.dat","rb+");
					while(fread(&b, sizeof(b), 1, fp) == 1) {
						delete(&b, fp, id, Found);
					}
					remove("Fiction.dat");
					rename("temporary.dat","Fiction.dat");
					if(Found)
						printf("\tRecord successfully saved\n");
					break;
			case NONFICTION :
					 fp = fopen("Nonfiction.dat","rb");
                        	        while(fread(&b, sizeof(b), 1, fp) == 1) {
                                	        delete(&b, fp, id, Found);
                               		 }
	                                remove("Nonfiction.dat");
        	                        rename("temporary.dat","Nonfiction.dat");
                	                if(Found)
                        	                printf("\tRecord successfully saved\n");
					break;
			case REFERENCE :
					 fp = fopen("Reference.dat","rb");
                	                while(fread(&b, sizeof(b), 1, fp) == 1) {
                        	                delete(&b, fp, id, Found);
                                	}
	                                remove("Reference.dat");
        	                        rename("temporary.dat","Reference.dat");
                	                if(Found)
                        	                printf("\tRecord successfully saved\n");
					break;
			case SELFHELP :
					fp = fopen("Selfhelp.dat","rb");
                	                while(fread(&b, sizeof(b), 1, fp) == 1) {
                        	                delete(&b, fp, id, Found);
                                	}
                               		remove("Selfhelp.dat");
                                	rename("temporary.dat","Selfhelp.dat");
                               		if(Found)
                                        	printf("\tRecord successfully saved\n");
					break;
			}
			printf("\tDelete more? (y/n) ");
			scanf(" %c", &option);
	}
}
