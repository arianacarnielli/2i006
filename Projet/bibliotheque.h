#ifndef __BIBLIO__
#define __BIBLIO__

#include "Solution.h"
#include "Grille.h"

/* Mettre dans solution S le chemin le plus court entre (i,j) et (k,l). Il fait d'abord le deplacement vertical et après le deplacement horizontal. */
void PlusCourtChemin(Solution *S, int i, int j, int k, int l);

/* Retourne 1 si la case (i,j) de la grille G est noire, 0 sinon. */
int EstCaseNoire(Grille* G, int i, int j);

/* Retourne 1 si la couleur de la piece c et celle du fond de la case (i, j) de la grille sont egales. */
int PieceEgaleFond(Grille* G, int i, int j, int c);
 
/* Retourne 1 s'il existe une piece dans la case (i,j) de la grille G. */
int ExistePiece(Grille* G, int i, int j);

/* Retourne 1 si le robot porte une piece, 0 sinon. */
int RobotPortePiece(Grille* G);

/* Retourne la couleur porte par le robot. */
int CouleurPieceRobot(Grille* G);

/* Retourne 1 si la position (i,j) est une case du tableau. */
int EstDansGrille(Grille* G, int i, int j);

#endif