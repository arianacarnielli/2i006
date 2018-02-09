CFLAGS=-g -Wall

all : main

entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc $(CFLAGS) -c entree_sortie.c
	

BiblioSimpleChaine.o : BiblioSimpleChaine.c BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioSimpleChaine.c

BiblioSimpleChaineMain.o : BiblioSimpleChaineMain.c BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioSimpleChaineMain.c
	
	 
main : BiblioSimpleChaine.o entree_sortie.o BiblioSimpleChaineMain.o BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -o main BiblioSimpleChaine.o entree_sortie.o BiblioSimpleChaineMain.o
clean: 
	rm -f *.o main

