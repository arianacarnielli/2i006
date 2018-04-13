#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "Graphe.h"
#include "exo7.h"
int main(int argc,char **argv){
	Grille G;
	Graphe H;
	Solution S;

	int graine;
	if (argc != 5){
		printf("usage: %s <nb_lignes nb_colonnes nb_couleur grainer>\n",argv[0]);
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


	Grille_allocation(&G);  
	Gene_Grille(&G,graine);
	
	Graphe_creation(&G, &H);
	Graphe_affiche(&H);

	algorithme_exo7(&G, &S, graine);

}