#ifndef __ALGOAVL__
#define __ALGOAVL__

typedef struct element
{
	int val;
	struct element* fd;
	struct element* fq;


}AVL;

AVL * crer_noeud (int val);
void construire (AVL * arbre,int val);


#endif