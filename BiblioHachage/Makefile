CFLAGS=-g -Wall

all : main

entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc $(CFLAGS) -c entree_sortie.c
	

BiblioHachage.o : BiblioHachage.c BiblioHachage.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioHachage.c

BiblioHachageMain.o : BiblioHachageMain.c BiblioHachage.h entree_sortie.h
	gcc $(CFLAGS) -c BiblioHachageMain.c
	
teste.o : teste.c BiblioHachage.h entree_sortie.h
	gcc $(CFLAGS) -c teste.c
	
teste :  BiblioHachage.o entree_sortie.o teste.o BiblioHachage.h entree_sortie.h
	gcc $(CFLAGS) -o teste BiblioHachage.o entree_sortie.o teste.o
	 
main : BiblioHachage.o entree_sortie.o BiblioHachageMain.o BiblioHachage.h entree_sortie.h
	gcc $(CFLAGS) -o main BiblioHachage.o entree_sortie.o BiblioHachageMain.o
clean: 
	rm -f *.o main teste
