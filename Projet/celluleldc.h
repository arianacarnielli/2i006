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

CelluleLDC* creerCellule( int i, int j);

void LDCInitialise(LDC* ldc);

int LDCVide(LDC* ldc);

void LDCInsererEnFin(LDC* ldc , int i, int j);  

void LDCenleverCellule(LDC* ldc, CelluleLDC* cel) ;

void LDCafficher(LDC* ldc);

void LDCdesalloue(LDC* ldc);

CelluleLDC* LDCrechercherPlusProcheCase(LDC* ldc, int i, int j);

void algorithme_parcouleur(Grille *G, Solution *S, int graine);

#endif