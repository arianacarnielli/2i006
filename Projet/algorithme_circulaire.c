#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibliotheque.h"
#include "Solution.h"
#include "Grille.h"

void RechercheCaseCirculaire_c(Grille *G, int c, int i, int j, int* k, int* l){

	int L = 1;
	int lg, ld, k_temp;
	/* On utilise une variable temporaire pour la valeur de k aussi pour la praticité et car cela augmente un peu la vitesse. */ 
	int max = G->m + G->n;

	while(L < max){

		lg = j;
		ld = j;

		for(k_temp = i - L; k_temp <= i; k_temp++){

			if (EstDansGrille(G, k_temp, lg) && PieceEgaleFond(G, k_temp, lg, c) && (!EstCaseNoire(G, k_temp, lg))){
				*k = k_temp;
				*l = lg;
				return;
			}
			if (EstDansGrille(G, k_temp, ld) && PieceEgaleFond(G, k_temp, ld, c) && (!EstCaseNoire(G, k_temp, ld))){
				*k = k_temp;
				*l = ld;
				return;
			}

			lg = lg - 1;
			ld = ld + 1;
		}
		
		lg = j - L + 1;
		ld = j + L - 1;

		for(k_temp = i + 1; k_temp <= i + L; k_temp++){
			if (EstDansGrille(G, k_temp, lg) && PieceEgaleFond(G, k_temp, lg, c) && (!EstCaseNoire(G, k_temp, lg))){
				*k = k_temp;
				*l = lg;
				return;
			}
			if (EstDansGrille(G, k_temp, ld) && PieceEgaleFond(G, k_temp, ld, c) && (!EstCaseNoire(G, k_temp, ld))){
				*k = k_temp;
				*l = ld;
				return;
			}

			lg = lg + 1;
			ld = ld - 1;
		}
		L++;
	}
}
void RechercheCaseCirculaire_nn(Grille *G, int i, int j, int* k, int* l){
	int L = 0;
	int lg,ld, k_temp;
	int max = G->m + G->n;

	while(L < max){

		lg = j;
		ld = j;

		for(k_temp = i - L; k_temp <= i; k_temp++){

			if (EstDansGrille(G, k_temp, lg) && (!EstCaseNoire(G, k_temp, lg)) && ExistePiece(G, k_temp, lg)){
				*k = k_temp;
				*l = lg;
				return;
			}
			if (EstDansGrille(G, k_temp, ld) && (!EstCaseNoire(G, k_temp, ld)) && ExistePiece(G, k_temp, ld)){
				*k = k_temp;
				*l = ld;
				return;
			}

			lg = lg - 1;
			ld = ld + 1;

		}

		lg = j - L + 1;
		ld = j + L - 1;


		for(k_temp = i + 1; k_temp <= i + L; k_temp++){
			if (EstDansGrille(G, k_temp, lg) && (!EstCaseNoire(G, k_temp, lg)) && ExistePiece(G, k_temp, lg)){
				*k = k_temp;
				*l = lg;
				return;
			}
			if (EstDansGrille(G, k_temp, ld) && (!EstCaseNoire(G, k_temp, ld)) && ExistePiece(G, k_temp, ld)){
				*k = k_temp;
				*l = ld;
				return;
			}
			
			lg = lg + 1;
			ld = ld - 1;
		}
		L++;
	}
}

void algorithme_circulaire(Grille *G, Solution *S, int graine){

	int nb_tot_noir = G->m * G->n;
	int k, l;
	
	Solution_init(S);
	
	while (G->cptr_noire < nb_tot_noir){
		if (RobotPortePiece(G)){
		/* Le robot a une piece, il cherche la case la plus proche de la meme couleur. */
			RechercheCaseCirculaire_c(G, CouleurPieceRobot(G), G->ir, G->jr, &k, &l);
		}else{
		/* Le robot n'a pas de piece, il cherche la case la plus proche avec une piece libre. */
			RechercheCaseCirculaire_nn(G, G->ir, G->jr, &k, &l);		
		}
				
		//PlusCourtChemin(S, G->ir, G->jr, k, l);
		changement_case(G, k, l);
		swap_case(G);
		//Ajout_action(S, 'S');
	}
	//Ecriture_Disque(G->m, G->n, G->nbcoul, graine, S);
}