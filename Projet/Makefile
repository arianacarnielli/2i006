all: Game_SortingRobot Checker_SortingRobot Solveur

entree_sortie.o: entree_sortie.c entree_sortie.h
	gcc -c entree_sortie.c

Solution.o: Solution.c Solution.h entree_sortie.h
	gcc -c Solution.c

Grille.o: Grille.c Grille.h Solution.h
	gcc -c Grille.c

API_AffGrille.o: API_AffGrille.c API_AffGrille.h Grille.h
	gcc -c API_AffGrille.c

Game_SortingRobot.o: Game_SortingRobot.c Grille.h API_AffGrille.h Solution.h 
	gcc -c Game_SortingRobot.c 

Game_SortingRobot: Game_SortingRobot.o API_AffGrille.o Grille.o Solution.o entree_sortie.o
	gcc -o Game_SortingRobot Game_SortingRobot.o API_AffGrille.o Grille.o Solution.o entree_sortie.o -lSDL

Checker_SortingRobot.o: Checker_SortingRobot.c Grille.h API_AffGrille.h Solution.h
	gcc -c Checker_SortingRobot.c

Checker_SortingRobot: Checker_SortingRobot.o API_AffGrille.o Grille.o Solution.o entree_sortie.o
	gcc -o Checker_SortingRobot Checker_SortingRobot.o API_AffGrille.o Grille.o Solution.o entree_sortie.o -lSDL
	
algorithme_naif.o: algorithme_naif.c algorithme_naif.h Grille.h Solution.h
	gcc -c algorithme_naif.c
	
Solveur.o: Solveur.c algorithme_naif.h Grille.h Solution.h entree_sortie.h
	gcc -c Solveur.c
	
Solveur: Solveur.o algorithme_naif.o Grille.o Solution.o entree_sortie.o
	gcc -o Solveur Solveur.o algorithme_naif.o Grille.o Solution.o entree_sortie.o
	
clean:
	rm -f *.o Game_SortingRobot Checker_SortingRobot Solveur
