#ifndef __ALGOAVL__
#define __ALGOAVL__

typedef struct element
{
	int val;
	struct element* fd;
	struct element* fq;


}AVL;

AVL * crer_noeud (int val);
AVL* rotation_droite(AVL * arbre)
void maj_hauteur(AVL * arbre);
AVL *rotation_gauche(AVL* arbre);
AVL *rotation_double_gauche(AVL** arbre );
AVL * rotation_double_droit(AVL* arbre);
AVL* insererABR_AVL(AVL *arbre,int val);
int ABR_hauteur(AVL *arbre);
#endif