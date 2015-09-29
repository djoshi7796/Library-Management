#include"libman.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char categories[][20]={"Fiction","Non-Fiction","Reference","Self-Help"};
char fiction[][20] = {"Mystery","Drama","Young-adult","Horror","Conspiracy-theory"};
char refer[][20] = {"Business","Computers","Arts","Medicine","Econimics","History","Geography","Architecture","Engineering","Psychology"};
char selfhelp[][20] = {"Fine-arts","Culinary-skills","Languages","Communication-skills","Encyclopaedias"};

void addentry(){
    int i, s;
    int fict, sh, ref, nonfict;
    FILE *fp;
    system("clear");
    printf("SELECT GENRES");
    printf("\n\n");
    printf("\t\t 1. Fiction\n");
    printf("\t\t 2. Non-fiction\n");
    printf("\t\t 3. Reference\n");
    printf("\t\t 4. Self-help\n");
    printf("\t\t 5. Back to main menu\n\n");
    printf("Enter your choice:");
    scanf("%d",&s);
	switch(s) {
		case FICTION :
				system("clear");
				printfiction();
				scanf("%d",&fict);
			        fp=fopen("Fiction.txt","a");
				if(getdata() == 1){
    					book.cat = (char *)malloc(sizeof(strlen(categories[s-1] + 1)));
					 strcpy(book.cat, categories[s-1]);

				      	book.subcat = (char *)malloc(sizeof(strlen(fiction[fict - 1] + 1)));
					 strcpy(book.subcat, fiction[fict - 1]);
   					 fseek(fp,0,SEEK_END);
   					 fwrite(&book,sizeof(book),1,fp);
				         fclose(fp);
				}
				break;

		case NONFICTION :
				system("clear");
				fp=fopen("Non-fiction.txt","a");
                                if(getdata() == 1){
                                         book.cat = (char *)malloc(sizeof(strlen(categories[s-1] + 1)));
                                         strcpy(book.cat, categories[s-1]);
                                         book.subcat = (char *)malloc(sizeof(strlen(categories[s - 1] + 1)));
                                         strcpy(book.subcat, categories[s - 1]);
                                         fseek(fp,0,SEEK_END);
                                         fwrite(&book,sizeof(book),1,fp);
                                         fclose(fp);
                                }
                                break;

		case REFERENCE :
				system("clear");
				printref();
				scanf("%d",&ref);
				 fp=fopen("Reference.txt","a");
                                if(getdata() == 1){
                                         book.cat = (char *)malloc(sizeof(strlen(categories[s-1] + 1)));
                                         strcpy(book.cat, categories[s-1]);
                                         book.subcat = (char *)malloc(sizeof(strlen(refer[ref - 1] + 1)));
                                         strcpy(book.subcat, refer[ref - 1]);
                                         fseek(fp,0,SEEK_END);
                                         fwrite(&book,sizeof(book),1,fp);
                                         fclose(fp);
                                }
                                break;

		case SELFHELP :
				system("clear");
				printselfhelp();
				scanf("%d",&sh);
				 fp=fopen("Self-help.txt","a");
                                if(getdata() == 1){
                                         book.cat = (char *)malloc(sizeof(strlen(categories[s-1] + 1)));
                                         strcpy(book.cat, categories[s-1]);
                                         book.subcat = (char *)malloc(sizeof(strlen(selfhelp[sh - 1] + 1)));
                                         strcpy(book.subcat, selfhelp[sh - 1]);
                                         fseek(fp,0,SEEK_END);
                                         fwrite(&book,sizeof(book),1,fp);
                                         fclose(fp);
                                }
                                break;
	}
    char c;
    printf("\nThe record is sucessfully saved\n");
   // scanf("%c", &c);
   // if(c == 'Y')
//		addentry();
}

int getdata()
{
    int t;
    system("clear");
    printf("Enter the Information Below\n");
    printf("Book ID:\t");
    scanf("%d",&t);
    book.id = t;
    printf("\nBook Name:*no spaces please*");
    scanf("%s", book.name);
    printf("\nAuthor:*no spaces please*");
    scanf("%s",book.author);
    printf("\nQuantity:");
    scanf("%d",&book.quantity);
    printf("\nPrice:");
    scanf("%f",&book.price);
    printf("\nRack No:");
    scanf("%d",&book.rackno);
    	return 1;
}

