#include<stdio.h>
void printgen() {
	 printf("\t\t\tSELECT GENRES");
    printf("\n\n");
    printf("\t\t 1. Fiction\n");
    printf("\t\t 2. Non-fiction\n");
    printf("\t\t 3. Reference\n");
    printf("\t\t 4. Self-help\n");
    printf("\t\t 5. Back to main menu\n\n");
    printf("\tEnter your choice:");
}
void printfiction() {
	printf("\t\tSELECT SUBCATEGORY\n\n");
	printf("\t\t 1. Mystery\n");
	printf("\t\t 2. Drama\n");
	printf("\t\t 3. Young adult\n");
	printf("\t\t 4. Horror\n");
	printf("\t\t 5. Historic\n");
	printf("\t\t 6. Conspiracy theory\n");
	printf("Enter your choice");
}
void printref() {
	printf("\t\tSELECT SUBCATEGORY\n\n");
	printf("\t\t 1. Business\n");
	printf("\t\t 2. Computers\n");
	printf("\t\t 3. Arts\n");
        printf("\t\t 4. Medicine\n");
	printf("\t\t 5. Economics\n");
        printf("\t\t 6. History\n");
	printf("\t\t 7. Geography\n");
        printf("\t\t 8. Architecture\n");
	printf("\t\t 9. Engineering\n");
        printf("\t\t 10. Psychology\n");
	printf("Enter your choice");
}
void printselfhelp() {
	printf("\t\tSELECT SUBCATEGORY\n\n");
	printf("\t\t 1. Fine arts\n");
        printf("\t\t 2. Culinary skills\n");
        printf("\t\t 3. Languages\n");
        printf("\t\t 4. Communication skills\n");
        printf("\t\t 5. Encyclopaedias\n");
        printf("Enter your choice");
}
void intro() {
	system("clear");
	printf("\t\t ~*~*~*~*~* WELCOME *~*~*~*~*~\n\n");
	printf("\tPlease select an option\n");
	printf("\t1. Add books\n\t2. Display books\n\t3. Search a book\n\t4. Delete a record\n\t5. Edit a record\n\t6. Issue a book\n\t7. Return a book\n\t8. Close application\n");
}	
