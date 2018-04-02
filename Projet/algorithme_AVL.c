#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "AVL.h" 
#include "Grille.h"
#include "bibliotheque.h"

AVL*** creer_table_AVL(Grille* G){
	int i, j, c;
	AVL*** M;
	M = (AVL***)malloc(sizeof(AVL**)*G->m);
	/* Initialise le tableau avec NULL partout. Chaque ligne represente une ligne de la grille et chaque colonne une couleur. La derniere colonne contient une AVL avec toutes les cases non noires de la ligne. */
	for(i = 0; i < G->m; i++){
		M[i] = (AVL**)malloc(sizeof(AVL*)*(G->nbcoul + 1));
		for(c = 0; c <= G->nbcoul; c++){
			M[i][c] = NULL;
		}
	}
	
	for(i = 0; i < G->m; i++){
		for(j = 0; j < G->n; j++){
			c = G->T[i][j].fond;
			if (!EstCaseNoire(G, i, j)){
				M[i][c] = inserer_AVL(M[i][c], j);
				M[i][G->nbcoul] = inserer_AVL(M[i][G->nbcoul], j);
			}
		}
	}
	return M;
}

void RechercheCaseAVL_c(Grille *G, int c, int i, int j, int* k, int* l, AVL*** M){
	int cpt_m, plus_proche, dist_temp;
	int dist = G->m + G->n;
	for (cpt_m = 0; cpt_m < G->m; cpt_m++){
		plus_proche = recherche_plus_proche(M[cpt_m][c], j);
		if (plus_proche != -1){
			dist_temp = Distance(i, j, cpt_m, plus_proche);
			if (dist_temp < dist){
				dist = dist_temp;
				*k = cpt_m;
				*l = plus_proche;
			}
		}
	}
}

void RechercheCaseAVL_nn(Grille *G, int i, int j, int* k, int* l, AVL*** M){
	int cpt_m, plus_proche, dist_temp;
	int dist = G->m + G->n;
	for (cpt_m = 0; cpt_m < G->m; cpt_m++){
		plus_proche = recherche_plus_proche(M[cpt_m][G->nbcoul], j);
		if (plus_proche != -1){
			dist_temp = Distance(i, j, cpt_m, plus_proche);
			if (dist_temp < dist){
				dist = dist_temp;
				*k = cpt_m;
				*l = plus_proche;
			}
		}
	}
}

void algorithme_AVL(Grille *G, Solution *S, int graine){
	int nb_tot_noir = G->m * G->n;
	int k, l;
	
	Solution_init(S);
	
	AVL*** M = creer_table_AVL(G);
	
	while (G->cptr_noire < nb_tot_noir){
		if (RobotPortePiece(G)){
		/* Le robot a une piece, il cherche la case la plus proche de la meme couleur. */
			RechercheCaseAVL_c(G, CouleurPieceRobot(G), G->ir, G->jr, &k, &l, M);
			
		}else{
		/* Le robot n'a pas de piece, il cherche la case la plus proche avec une piece libre. */
			RechercheCaseAVL_nn(G, G->ir, G->jr, &k, &l, M);	
		}
				
		//PlusCourtChemin(S, G->ir, G->jr, k, l);
		changement_case(G, k, l);
		swap_case(G);
		//Ajout_action(S, 'S');
		if(EstCaseNoire(G, k, l)){
			M[k][CouleurFond(G, k, l)] = supprimer_noeud(M[k][CouleurFond(G, k, l)], l);
			M[k][G->nbcoul] = supprimer_noeud(M[k][G->nbcoul], l);
		}else{
			if(!ExistePiece(G, k, l)){
				M[k][G->nbcoul] = supprimer_noeud(M[k][G->nbcoul], l);
			}
		}
			
	}
	//Ecriture_Disque(G->m, G->n, G->nbcoul, graine, S);
}


