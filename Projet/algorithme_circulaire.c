#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithme_naif.h"


#include "Solution.h"
#include "Grille.h"

void RechercheCaseCirculaire_c(Grille *G, int c, int i, int j, int* k, int* l){

	int L = 1;
	int lg,ld;
	int max = G->m + G->n;

	while(L < max){

		*k = i - L;
		lg = j;
		ld = j;

		for(*k; *k <= i; (*k)++){

			if ((*k >= 0) && (*k < G->m) && (lg >= 0) && (lg < G->n) && (c == G->T[*k][lg].fond) && (G->T[*k][lg].fond != G->T[*k][lg].piece)){
				*l = lg;
				return;
			}
			if ((*k >= 0) && (*k < G->m) && (ld >= 0) && (ld < G->n) && (c == G->T[*k][ld].fond) && (G->T[*k][ld].fond != G->T[*k][ld].piece)){
				*l = ld;
				return;
			}

			lg = lg - 1;
			ld = ld + 1;

		}
		*k = i + 1;
		lg = j - L + 1;
		ld = j + L - 1;


		for(*k; *k <= i + L; (*k)++){
			if ((*k >= 0) && (*k < G->m) && (lg >= 0) && (lg < G->n) && (c == G->T[*k][lg].fond) && (G->T[*k][lg].fond != G->T[*k][lg].piece)){
				*l = lg;
				return;
			}
			if ((*k >= 0) && (*k < G->m) && (ld >= 0) && (ld < G->n) && (c == G->T[*k][ld].fond) && (G->T[*k][ld].fond != G->T[*k][ld].piece)){
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
	int L = 1;
	int lg,ld;
	int max = G->m + G->n;

	while(L < max){

		*k = i - L;
		lg = j;
		ld = j;

		for(*k; *k <= i; (*k)++){

			if ((*k >= 0) && (*k < G->m) && (lg >= 0) && (lg < G->n) && (G->T[*k][lg].fond != G->T[*k][lg].piece) && (G->T[*k][lg].piece != -1)){
				*l = lg;
				return;
			}
			if ((*k >= 0) && (*k < G->m) && (ld >= 0) && (ld < G->n) && (G->T[*k][ld].fond != G->T[*k][ld].piece) && (G->T[*k][ld].piece != -1)){
				*l = ld;
				return;
			}

			lg = lg - 1;
			ld = ld + 1;

		}
		*k = i + 1;
		lg = j - L + 1;
		ld = j + L - 1;


		for(*k; *k <= i + L; (*k)++){
			if ((*k >= 0) && (*k < G->m) && (lg >= 0) && (lg < G->n) && (G->T[*k][lg].fond != G->T[*k][lg].piece) && (G->T[*k][lg].piece != -1)){
				*l = lg;
				return;
			}
			if ((*k >= 0) && (*k < G->m) && (ld >= 0) && (ld < G->n) && (G->T[*k][ld].fond != G->T[*k][ld].piece) && (G->T[*k][ld].piece != -1)){
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
		if (G->T[G->ir][G->jr].robot >= 0){
		/* Le robot a une piece, il cherche la case la plus proche de la meme couleur. */
			RechercheCaseCirculaire_c(G, G->T[G->ir][G->jr].robot, G->ir, G->jr, &k, &l);
		}else{
		/* Le robot n'a pas de piece, il cherche la case la plus proche avec une piece libre. */
			RechercheCaseCirculaire_nn(G, G->ir, G->jr, &k, &l);		
		}
				
		PlusCourtChemin(S, G->ir, G->jr, k, l);
		changement_case(G, k, l);
		swap_case(G);
		Ajout_action(S, 'S');
	}
	Ecriture_Disque(G->m, G->n, G->nbcoul, graine, S);
}