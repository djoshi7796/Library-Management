#include"libman.h"
void closeapp() {
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	mvaddstr(27,60," ~~~~~ THANK YOU ~~~~~");
	mvaddstr(28,60,"Press ENTER to exit  ");
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
	getch();
	refresh();

}
