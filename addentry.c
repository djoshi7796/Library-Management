/*This file is a part of Library-Management

    Library-Management is a free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/


#include"libman.h"
#include<stdlib.h>
#include<string.h>

char categories[][20]={"Fiction","Non-Fiction","Reference","Self-Help"};
char fiction[][20] = {"Mystery","Drama","Young-adult","Horror","Conspiracy-theory"};
char refer[][20] = {"Business","Computers","Arts","Medicine","Econimics","History","Geography","Architecture","Engineering","Psychology"};
char selfhelp[][20] = {"Fine-arts","Culinary-skills","Languages","Communication-skills","Encyclopaedias"};

void addentry(){
    	int i, s;
	/*Setting border color */
    	init_pair(2,COLOR_MAGENTA,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	border(0,0,0,0, 0,0,0,0);
	refresh();
	attroff(COLOR_PAIR(2));
	refresh();
   	int fict, sh, ref, nonfict;
	FILE *fp;
	Book book;
    	char option = 'y';
   	clear();
	    	refresh();
    	while(option == 'y' || option == 'Y') {
    		printgen();
    		scanw("%d",&s);
			switch(s) {
				case FICTION :
						printfiction();
						scanw("%d",&fict);
				       		fp=fopen("Fiction.dat","ab+");
						if(getinfo(&book)){
							book.cat = categories[s - 1];
							book.subcat = fiction[fict - 1];
   						 	fseek(fp,0,SEEK_END);
   							fwrite(&book,sizeof(book),1,fp);
						        fclose(fp);
						}	
						break;
				case NONFICTION :
						fp=fopen("Nonfiction.dat","ab+");
                	        	        if(getinfo(&book) == 1){
                        	        	         book.cat = categories[s-1];
                                	        	 book.subcat = categories[s-1];
                     		                   	 fseek(fp,0,SEEK_END);
	                        	                 fwrite(&book,sizeof(book),1,fp);
	                                	         fclose(fp);
      		  	                        }
                	         	       break;
				case REFERENCE :
						printref();
						scanw("%d",&ref);
						fp=fopen("Reference.dat","ab+");
                     	          	        if(getinfo(&book) == 1){
                                        		 book.cat = categories[s-1];
                                        		 book.subcat = refer[ref - 1]; 
                                        		 fseek(fp,0,SEEK_END);
                            	            		 fwrite(&book,sizeof(book),1,fp);
                                	        	 fclose(fp);
                               			 }
                              			 break;
				case SELFHELP :
						printselfhelp();
						scanw("%d",&sh);
					 	fp=fopen("Selfhelp.dat","ab+");
                	                	if(getinfo(&book) == 1){
                        	                	 book.cat,categories[s-1];
                                	        	 book.subcat = selfhelp[sh - 1];
                                        		 fseek(fp,0,SEEK_END);
                                        		 fwrite(&book,sizeof(book),1,fp);
	                                       		 fclose(fp);
        	                	        }
                	               	        break;
				case MENU :
						mainmenu();
						return;
						break;
				default :
						printw("\n ----- Wrong option. Please select again -----\n");
						addentry();
						return;
			}
    		mvaddstr(10,16,"The record is sucessfully saved");
    		mvaddstr(11,16,"Add more ? (y/n) ");
		option = getch();
	}
	mvaddstr(12,16,"Press Enter to go to main menu");
	getch();
	mainmenu();
	refresh();
	return;
}

/*This fucntion gets the information from the user */

int getinfo(Book *book)
{
	int t;
    	clear();
	/*Setting border color */
	init_pair(2,COLOR_MAGENTA,COLOR_BLACK);
        attron(COLOR_PAIR(2));
        border(0,0,0,0, 0,0,0,0);
        refresh();
        attroff(COLOR_PAIR(2));
    	refresh();
	/*Getting information */
	mvaddstr(2,24,"Enter the Information Below");
    	mvaddstr(4,24,"Book ID: ");
    	scanw("%d",&t);
    	book->id = t;
    	mvaddstr(5,24,"Book Name: ");
    	getstr(book->name);
    	mvaddstr(6,24,"Author: ");
    	getstr(book->author);
    	mvaddstr(7,24,"Quantity:");
    	scanw("%d",&book->quantity);
    	mvaddstr(8,24,"Rack No:");
    	scanw("%d",&book->rackno);
    	refresh();
    	return 1;
	
}

