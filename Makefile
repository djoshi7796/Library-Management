project: main.o addentry.o printentry.o printmenus.o
	cc main.o addentry.o printentry.o printmenus.o -o project
main.o : main.c libman.h
	cc -c main.c
addentry.o : addentry.c libman.h
	cc -c addentry.c
printentry.o : printentry.c libman.h
	cc -c printentry.c
printmenus.o : printmenus.c libman.h
	cc -c printmenus.c

