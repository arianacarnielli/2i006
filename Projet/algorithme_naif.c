#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibliotheque.h"
#include "Solution.h"
#include "Grille.h"


void RechercheCaseNaif_c(Grille *G, int c, int i, int j, int* k, int* l){
	int cpt_m, cpt_n, dist;
	int dist_min = G->m + G->n;
	
	for (cpt_m = 0; cpt_m < G->m; cpt_m++){
		for (cpt_n = 0; cpt_n < G->n; cpt_n++){
			if (PieceEgaleFond(G, cpt_m, cpt_n, c) && (!EstCaseNoire(G, cpt_m, cpt_n))){
				dist = abs(cpt_m - i) + abs(cpt_n - j);
				if (dist_min > dist){
					dist_min = dist;
					*k = cpt_m;
					*l = cpt_n;
				}
			}
		}
	}	
}

void RechercheCaseNaif_nn(Grille *G, int i, int j, int* k, int* l){
	int cpt_m, cpt_n, dist;
	int dist_min = G->m + G->n;
	
	for (cpt_m = 0; cpt_m < G->m; cpt_m++){
		for (cpt_n = 0; cpt_n < G->n; cpt_n++){
			if ((!EstCaseNoire(G, cpt_m, cpt_n)) && ExistePiece(G, cpt_m, cpt_n)){
				dist = abs(cpt_m - i) + abs(cpt_n - j);
				if (dist_min > dist){
					dist_min = dist;
					*k = cpt_m;
					*l = cpt_n;
				}
			}
		}
	}		
}

void algorithme_naif(Grille *G, Solution *S, int graine){
	int nb_tot_noir = G->m * G->n;
	int k, l;
	
	Solution_init(S);
	
	while (G->cptr_noire < nb_tot_noir){
		if (RobotPortePiece(G)){
		/* Le robot a une piece, il cherche la case la plus proche de la meme couleur. */
			RechercheCaseNaif_c(G, CouleurPieceRobot(G), G->ir, G->jr, &k, &l);
		}else{
		/* Le robot n'a pas de piece, il cherche la case la plus proche avec une piece libre. */
			RechercheCaseNaif_nn(G, G->ir, G->jr, &k, &l);		
		}
				
		//PlusCourtChemin(S, G->ir, G->jr, k, l);
		changement_case(G, k, l);
		swap_case(G);
		//Ajout_action(S, 'S');
	}
	//Ecriture_Disque(G->m, G->n, G->nbcoul, graine, S);
}
