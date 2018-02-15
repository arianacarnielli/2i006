CFLAGS=-g -Wall

all : main

entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc $(CFLAGS) -c entree_sortie.c
	

BiblioHachage.o : BiblioHachage.c BiblioHachage.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioHachage.c

BiblioHachageMain.o : BiblioHachageMain.c BiblioHachage.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioHachageMain.c
	
	 
main : BiblioHachage.o entree_sortie.o BiblioHachageMain.o BiblioHachage.h entree_sortie.h
	gcc $(CFLAGS) -o main BiblioHachage.o entree_sortie.o BiblioHachageMain.o
clean: 
	rm -f *.o main
