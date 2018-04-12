@echo off

if "%1" == "all" (
	
	gcc -c entree_sortie.c
	gcc -c Solution.c
	gcc -c Grille.c
	gcc -c API_AffGrille.c -lmingw32 -lSDLmain -lSDL
	gcc -c Checker_SortingRobot.c
	gcc -c Game_SortingRobot.c -lmingw32 -lSDLmain -lSDL
	gcc -c algorithme_naif.c
	gcc -c algorithme_circulaire.c
	gcc -c algorithme_couleur.c
	gcc -c algorithme_AVL.c
	gcc -c AVL.c
	gcc -c bibliotheque.c
	gcc -c Graphe.c
	gcc -c ListeDC.c
	gcc -c Solveur.c
	gcc -c main_partie_2.c
	gcc -c circuit.c
	
	gcc -o Game_SortingRobot Game_SortingRobot.o API_AffGrille.o Grille.o Solution.o entree_sortie.o -lmingw32 -lSDLmain -lSDL
	gcc -o Checker_SortingRobot Checker_SortingRobot.o  API_AffGrille.o Grille.o Solution.o entree_sortie.o -lmingw32 -lSDLmain -lSDL
	gcc -o Solveur Solveur.o algorithme_naif.o algorithme_circulaire.o algorithme_couleur.o algorithme_AVL.o AVL.o bibliotheque.o Grille.o Solution.o entree_sortie.o
	gcc -o main_partie_2 main_partie_2.o Graphe.o ListeDC.o Grille.o circuit.o
	
) else if "%1" == "clear" (

	del /q *.o Game_SortingRobot.exe Checker_SortingRobot.exe Solveur.exe main_partie_2.exe
)

