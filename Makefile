CFLAGS=-g -Wall

all : main

entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc $(CFLAGS) -c  entree_sortie.c
	

BiblioSimpleChaine.o : BiblioSimpleChaine.c Biblio.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioSimpleChaine.c

main.o :   main.c Biblio.h entree_sortie.h entree_sortie.h
	gcc $(CFLAGS) -c main.c
	
	 
main : BiblioSimpleChaine.o entree_sortie.o main.o
	gcc $(CFLAGS) -o main BiblioSimpleChaine.o entree_sortie.o main.o
clean: 
	rm -f *.o main

