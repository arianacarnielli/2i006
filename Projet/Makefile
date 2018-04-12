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
	
algorithme_naif.o: algorithme_naif.c algorithme_naif.h Grille.h Solution.h bibliotheque.h
	gcc -c algorithme_naif.c
	
algorithme_circulaire.o: algorithme_circulaire.c algorithme_circulaire.h Grille.h Solution.h bibliotheque.h
	gcc -c algorithme_circulaire.c
	
algorithme_couleur.o: algorithme_couleur.c algorithme_couleur.h algorithme_circulaire.h Grille.h Solution.h bibliotheque.h
	gcc -c algorithme_couleur.c
	
algorithme_AVL.o: algorithme_AVL.c algorithme_AVL.h AVL.h Grille.h Solution.h bibliotheque.h
	gcc -c algorithme_AVL.c
	
AVL.o: AVL.c AVL.h
	gcc -c AVL.c
	
bibliotheque.o: bibliotheque.c bibliotheque.h Grille.h Solution.h
		gcc -c bibliotheque.c
	
Solveur.o: Solveur.c algorithme_naif.h algorithme_circulaire.h algorithme_couleur.h algorithme_AVL.h Grille.h Solution.h entree_sortie.h 
	gcc -c Solveur.c
	
Solveur: Solveur.o algorithme_naif.o algorithme_circulaire.o algorithme_couleur.o algorithme_AVL.o bibliotheque.o AVL.o Grille.o Solution.o entree_sortie.o
	gcc -o Solveur Solveur.o algorithme_naif.o algorithme_circulaire.o algorithme_couleur.o algorithme_AVL.o bibliotheque.o AVL.o Grille.o Solution.o entree_sortie.o
	
Graphe.o: Graphe.c Graphe.h ListeDC.h
	gcc -c Graphe.c
	
ListeDC.o: ListeDC.c ListeDC.h
	gcc -c ListeDC.c
	
circuit.o: circuit.c Graphe.h ListeDC.h circuit.h
	gcc -c circuit.c
	
main_partie_2.o: main_partie_2.c Graphe.h ListeDC.h Grille.h circuit.h
	gcc -c main_partie_2.c
	
main_partie_2: main_partie_2.o Graphe.o ListeDC.o Grille.o circuit.o
	gcc -o main_partie_2 main_partie_2.o Graphe.o ListeDC.o Grille.o circuit.o
	
clean:
	rm -f *.o Game_SortingRobot Checker_SortingRobot Solveur
