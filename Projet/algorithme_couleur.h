#ifndef __ALGOCOUL__
#define __ALGOCOUL__

#include "Solution.h"
#include "Grille.h"


typedef	struct celluleLDC{
	int i, j;
	struct celluleLDC* prec;
	struct celluleLDC* suiv;
}CelluleLDC;

typedef struct {
	CelluleLDC* premier;
	CelluleLDC* dernier;
}LDC;

/* Alloue une cellule CelluleLDC et l'initialise avec i et j. */
CelluleLDC* creerCellule( int i, int j);

/* Initialise la liste LDC comme vide. */
void LDCInitialise(LDC* ldc);

/* Teste si la liste passe en argument est vide. */
int LDCVide(LDC* ldc);

/* Cree et insere une cellule avec les valeurs i et j a la fin de liste LDC passe en argument */
void LDCInsererEnFin(LDC* ldc , int i, int j);  

/* Supprime la cellule de la liste et la desaloue. La cellule doit appartenir a la liste. */
void LDCenleverCellule(LDC* ldc, CelluleLDC* cel) ;

/* Affiche la liste. */
void LDCafficher(LDC* ldc);

/* Supprime la liste entiere. */
void LDCdesalloue(LDC* ldc);

/* Recherche la plus proche case de (i,j) dans la liste ldc. */
CelluleLDC* LDCrechercherPlusProcheCase(LDC* ldc, int i, int j);

/* Initialise et rempli le tableau de LDC* a partir de la grille (Un LDC* par couleur de la grille) */
LDC* initialise_TC(Grille* G);

/* Implemente l'algorithme circulaire par couleur decrit dans l'enonce. La solution S est initialise a l'interieur de la fonction. Le parametre graine est utilisee lors de l'ecriture de la solution en disque, on a choisi de le passer en argument. Pour la recherche d'une case non-vide, il utilise la recherche circulaire. */
void algorithme_couleur(Grille *G, Solution *S, int graine);

#endif