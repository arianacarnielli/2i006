CFLAGS=-g -Wall

all : main

entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc $(CFLAGS) -c entree_sortie.c
	

BiblioSimpleChaine.o : BiblioSimpleChaine.c BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioSimpleChaine.c

BiblioSimpleChaineMain.o : BiblioSimpleChaineMain.c BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioSimpleChaineMain.c
	
teste.o : teste.c BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -c teste.c
	
teste : BiblioSimpleChaine.o entree_sortie.o teste.o BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -o teste BiblioSimpleChaine.o entree_sortie.o teste.o
	
main : BiblioSimpleChaine.o entree_sortie.o BiblioSimpleChaineMain.o BiblioSimpleChaine.h entree_sortie.h
	gcc $(CFLAGS) -o main BiblioSimpleChaine.o entree_sortie.o BiblioSimpleChaineMain.o

clean: 
	rm -f *.o main teste

