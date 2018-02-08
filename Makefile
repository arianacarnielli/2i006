CFLAGS=-g -Wall

all : main

entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc $(CFLAGS) -c  entree_sortie.c
	

BiblioSimpleChaine.o : BiblioSimpleChaine.c BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioSimpleChaine.c

main.o :   main.c BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -c main.c
	
	 
main : BiblioSimpleChaine.o entree_sortie.o main.o BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -o main BiblioSimpleChaine.o entree_sortie.o main.o
clean: 
	rm -f *.o main

