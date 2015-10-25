#include<stdio.h>
#include"libman.h"
int main() {
	mainmenu();
	return 0;
}
void mainmenu() {
	
	int choice;
	intro();
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice) {
		case 1:
			addentry();
			break;
		case 2:
			printentry();
			break;
		case 3:
			searchentry();
			break;
		case 4 :
			deleteentry();
			break;
		case 5 :
			editentry();
			break;
		case 6 :
			issuebooks();
			break;
		case 7 :
//			returnbooks();
			break;
		case 8:
			closeapp();
			break;
	}
}
		


