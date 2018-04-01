#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorithme_naif.h"
#include "algorithme_circulaire.h"
#include "algorithme_couleur.h"
#include "algorithme_AVL.h"
#include "Grille.h"
#include "Solution.h"

int main(int argc, char**argv){

	Grille G;
	Solution S;
	int graine, ch;
	clock_t start;
	double duree;

	if (argc != 6){
		printf("usage: %s <nb_lignes nb_colonnes nb_couleur graine nb_solveur>\n",argv[0]);
		return 1;
	}

	G.m = atoi(argv[1]);
	G.n = atoi(argv[2]);

	if (G.m > G.n){
		printf("Il doit y avoir plus de colonnes que de lignes.\n");
		exit(1);
	}

	G.nbcoul = atoi(argv[3]);
	if (G.nbcoul > G.m * G.n){
		printf("Il ne doit pas y avoir plus de couleurs que de cases.\n");
		exit(1);
	}

	graine = atoi(argv[4]);

	ch = atoi(argv[5]);

	Grille_allocation(&G);  
	Gene_Grille(&G,graine);

	switch(ch){

		case 1:
			printf("Solution par l'algorithme naif en cours...\n");
			start = clock();
			algorithme_naif(&G, &S, graine);
			duree = (double)(clock() - start) / CLOCKS_PER_SEC;
			break;

		case 2:
			printf("Solution par l'algorithme circulaire en cours...\n");
			start = clock();
			algorithme_circulaire(&G, &S, graine);
			duree = (double)(clock() - start) / CLOCKS_PER_SEC;
			break;

		case 3:
			printf("Solution par l'algorithme circulaire par couleurs en cours...\n");
			start = clock();
			algorithme_couleur(&G, &S, graine);
			duree = (double)(clock() - start) / CLOCKS_PER_SEC;
			break;
			
		case 4:
			printf("Solution par l'algorithme AVL en cours...\n");
			start = clock();
			algorithme_AVL(&G, &S, graine);
			duree = (double)(clock() - start) / CLOCKS_PER_SEC;
			break;
		
	}
	
	printf ("Le solveur a pris %f secondes pour resoudre le jeu.\n", duree);
	return 0;
}
