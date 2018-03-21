#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibliotheque.h"
#include "Solution.h"
#include "Grille.h"

AVL *creer_noeud(int val){
	AVL *res =malloc(sizeof(AVL));
	res->hauteur=0;
	res->val=val;
	res->fg=NULL;
	res->fd=NULL;
	return res ;
}

void construire(AVL** arbre ,int val){

	if((*arbre)==NULL){
		*(arbre)=creer_noeud(val);

	}
	else{
		if(val>(*arbre)->val)
			construire(&(*arbre)->fd,val);
		else
			construire(&(*arbre)->fg,val);
	}
}

int ABR_hauteur(AVL *arbre){
	if(arbre==NULL){
		return-1;
	}
	return arbre->hauteur;
}

void maj_hauteur(AVL * arbre){

	if(arbre)
		arbre->hauteur=max(ARB_hauteur(arbre->fd),ARB_hauteur(arbre->fg));
}

void rotation_droite(AVL ** arbre){
	AVL *r=*arbre;
	AVL*g=r->fg;
	AVL*v=g->fd;
	r->fg=v;
	g->fd=r;
	*arbre=g;
	maj_hauteur(*arbre);
	maj_hauteur((*arbre)->fd);

}

void rotation_gauche(AVL** arbre){

	AVL *P=*arbre;
	AVL *q=p->fd;
	AVL *v=q->fg;
	q->fg=p;
	p->fd=v;
	(*arbre)=q;

	maj_hauteur(*arbre);
	maj_hauteur((*arbre)->fg);
}
