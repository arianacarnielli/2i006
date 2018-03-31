#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Solution.h"
#include "Grille.h"


void PlusCourtChemin(Solution *S, int i, int j, int k, int l){
	int cpt;
	
	int i_to_k = k - i;
	int j_to_l = l - j;
	
	if (i_to_k < 0){
		i_to_k *= -1;
		for (cpt = 0; cpt < i_to_k; cpt++){
			Ajout_action(S, 'U');
		}
	}else{
		for (cpt = 0; cpt < i_to_k; cpt++){
			Ajout_action(S, 'D');
		}
	}
	if (j_to_l < 0){
		j_to_l *= -1;
		for (cpt = 0; cpt < j_to_l; cpt++){
			Ajout_action(S, 'L');
		}
	}else{
		for (cpt = 0; cpt < j_to_l; cpt++){
			Ajout_action(S, 'R');
		}
	}
}

int EstCaseNoire(Grille* G, int i, int j){
	return G->T[i][j].fond == G->T[i][j].piece;
}

int PieceEgaleFond(Grille* G, int i, int j, int c){
	return c == G->T[i][j].fond;
}

int ExistePiece(Grille* G, int i, int j){
	return G->T[i][j].piece != -1;
}

int RobotPortePiece(Grille* G){
	return G->T[G->ir][G->jr].robot >= 0;
}

int CouleurPieceRobot(Grille* G){
	return G->T[G->ir][G->jr].robot;
}

int CouleurFond(Grille* G, int i, int j){
	return G->T[i][j].fond;
}

int EstDansGrille(Grille* G, int i, int j){
	return (i >= 0) && (i < G->m) && (j >= 0) && (j < G->n);
}

int Distance(int i, int j, int k, int l){
	return abs(i - k) + abs (j - l);
}