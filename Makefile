project: main.o addentry.o printentry.o printmenus.o deleteentry.o searchentry.o editentry.o issuebooks.o closeapp.o displayissue.o returnbooks.o calcfine.o 
	cc main.o addentry.o printentry.o printmenus.o deleteentry.o searchentry.o editentry.o issuebooks.o closeapp.o displayissue.o returnbooks.o calcfine.o -o project
main.o : main.c libman.h
	cc -c main.c
addentry.o : addentry.c libman.h
	cc -c addentry.c
printentry.o : printentry.c libman.h
	cc -c printentry.c
printmenus.o : printmenus.c libman.h
	cc -c printmenus.c
deleteentry.o : deleteentry.c libman.h
	cc -c deleteentry.c
searchentry.o : searchntry.c libman.h
	cc -c searchentry.c
editentry.o : editentry.c libman.h
	cc -c editentry.c
issuebooks.o : issuebooks.c libman.h
	cc -c issuebooks.c
displayissue.o : displayissue.c libman.h
	cc -c displayissue.c
returnbooks.o : returnbooks.c libman.h
	cc -c returnbooks.c
calcfine.o : calcfine.c libman.h
	cc -c calcfine.c
closeapp.o : closeapp.c libman.h
	cc -c closeapp.c

