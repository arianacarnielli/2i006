#include <stdlib.h>
#include <stdio.h>

#include "Graphe.h"
#include "ListeDC.h"
#include "Grille.h"
#include "circuit.h"
//#include "API_AffGrille.h"

int main(int argc, char**argv){
	Grille G;
	Graphe H;
	Lcircuit l_c;
	//AffGrille AG;
	int graine;
	// initialisation de la grille de jeu. 
	if (argc != 5){
		printf("usage: %s <nb_lignes nb_colonnes nb_couleur graine>\n",argv[0]);
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
	
	// Test creation et affichage du graphe.
	Graphe_init(&H, G.m, G.n);
	Graphe_creation(&G, &H);
	Graphe_affiche(&H);
	
	// Test l'affichage de circuits du graphe.
	Graphe_Affiche_Circuit(&H);
	
	reset_visit(&H);
	
	// Test initialisation et affichage de la liste Lcircuit.
	LcircuitInitialise(&l_c);
	Graphe_Rech_Circuit(&H, &l_c);
	Affiche_Lcircuit(&l_c);
	
	printf("\n\nTest calcul jmin et jmax\n\n");
	// Test si calcul Jmin et Jmax marche correctement.
	CalculJminJmax(&l_c);
	Affiche_Lcircuit(&l_c);
		
	/*AffGrille_init(&G, 600, &AG);

	AffGrille_ouvre_fenetre(&AG);

	for (i=0;i<G.m;i++){
		for (j=0;j<G.n;j++){
          AffGrille_redessine_case(&AG,&G,i,j);
		}
	}

	AffGrille_reaffiche_Grille(); */

	return 0;
	
}