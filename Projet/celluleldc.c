#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithme_naif.h"
#include "algorithme_circulaire.h"


#include "Solution.h"
#include "Grille.h"


typedef	struct	celluleLDC{
	int i, j;
	struct celluleLDC* prec;
	struct celluleLDC* suiv;
}CelluleLDC;

typedef struct {
	CelluleLDC* premier;
	CelluleLDC* dernier;
}LDC;

CelluleLDC* creerCellule( int i, int j){
	CelluleLDC* new = (CelluleLDC*) malloc(sizeof(CelluleLDC));
	new->i = i;
	new->j = j;
	new->prec = NULL;
	new->suiv = NULL;
	return new;
}

void LDCInitialise(LDC* ldc){
	ldc->premier = NULL;
	ldc->dernier = NULL;
}

int LDCVide(LDC* ldc){
	return ldc->premier == NULL;
}

void LDCInsererEnFin(LDC* ldc , int i, int j){
	CelluleLDC* new = creerCellule(i, j);

	if(LDCVide(ldc)){
		ldc->premier = new;
		ldc->dernier = new;

	}else{
		ldc->dernier->suiv = new;
		new->prec = ldc->dernier;
		ldc->dernier = new;
	}
}  

void LDCenleverCellule(LDC* ldc, CelluleLDC* cel){

	if(ldc->premier == cel){
		ldc->premier = cel->suiv;
		free(cel);
		return;
	}
	if(ldc->dernier == cel){
		ldc->dernier = cel->prec;
		free(cel);
		return;
	}

	cel->prec->suiv = cel->suiv;
	cel->suiv->prec = cel->prec;

	free(cel);

}

void LDCafficher(LDC* ldc){
	CelluleLDC* tmp = ldc->premier;
	while(tmp){
		printf("(%d,%d)\n", tmp->i, tmp->j);
		tmp = tmp->suiv;
	}
}

void LDCdesalloue(LDC* ldc){
	CelluleLDC* tmp = ldc->premier;
	CelluleLDC* tmp2;
	while(tmp){
		tmp2 = tmp->suiv;
		LDCenleverCellule(ldc, tmp);
		tmp = tmp2;
	}
}

CelluleLDC* LDCrechercherPlusProcheCase(LDC* ldc, int i, int j){
	CelluleLDC* temp = ldc->premier;
	CelluleLDC* plus_petit = temp;

	while(temp){
		if ((abs(temp->i - i) + abs(temp->j - j)) <= (abs(plus_petit->i - i) + abs(plus_petit->j - j))){
			plus_petit = temp;
		}
		temp = temp->suiv;
	} 
	return plus_petit;
}

void algorithme_parcouleur(Grille *G, Solution *S, int graine){

	int nb_tot_noir = G->m * G->n;
	int k, l, i, j;
	CelluleLDC* temp;
	
	Solution_init(S);

	LDC* TC = (LDC*) malloc(sizeof(LDC)*G->nbcoul);

	for(i = 0; i < G->nbcoul; i++){
		LDCInitialise(&TC[i]);  
	}
	
	for(j = G->n - 1; j >= 0; j--){
		for(i = G->m - 1; i >= 0; i--){
			if(G->T[i][j].fond != G->T[i][j].piece){
				LDCInsererEnFin(&(TC[(G->T[i][j]).fond]), i, j);
			}
		}
	}



	while (G->cptr_noire < nb_tot_noir){
		printf("J'ai la couleur %d \n", G->T[G->ir][G->jr].robot);
		if (G->T[G->ir][G->jr].robot >= 0){
		/* Le robot a une piece, il cherche la case la plus proche de la meme couleur. */

			
			temp = LDCrechercherPlusProcheCase(&(TC[G->T[G->ir][G->jr].robot]), G->ir, G->jr);

			printf("liste de meme couleur avant suppression\n");
			LDCafficher(&(TC[G->T[G->ir][G->jr].robot]));


			k = temp->i;
			l = temp->j;

			LDCenleverCellule(&(TC[G->T[G->ir][G->jr].robot]), temp);
			printf("liste de meme couleur apres suppression\n");
			LDCafficher(&(TC[G->T[G->ir][G->jr].robot]));


		}else{
		/* Le robot n'a pas de piece, il cherche la case la plus proche avec une piece libre. */
			printf("je n'ai pas de piece\n");

			RechercheCaseCirculaire_nn(G, G->ir, G->jr, &k, &l);		
		}
				
		PlusCourtChemin(S, G->ir, G->jr, k, l);
		changement_case(G, k, l);
		swap_case(G);
		Ajout_action(S, 'S');
		printf("%d, %d\n", G->ir, G->jr);

	}
	Ecriture_Disque(G->m, G->n, G->nbcoul, graine, S);

}