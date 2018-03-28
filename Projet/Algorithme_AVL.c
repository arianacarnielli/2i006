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

AVL* insererABR_AVL(AVL *arbre,int val){

	if((arbre)==NULL){
		return creer_noeud(val);

	}
	
		if(val<arbre->val){
			if(arbre->fg==NULL){
				AVL *nv=creer_noeud(val);
				arbre->fg=nv;
			}
			else
				arbre->fg=insererABR_AVL((arbre)->fg,val);
			
		}
		else{
			if(arbre->fd==NULL){
				AVL *nv=creer_noeud(val);
				arbre->fd=nv;
			}
			else
				arbre->fd=insererABR_AVL((arbre)->fd,val);
		}
	

	maj_hauteur(arbre);
	arbre=bien_equilibre(arbre);
	return arbre;

}

AVL * supprimer_noed{


}

int ABR_hauteur(AVL *arbre){
	if(arbre==NULL){
		return-1;
	}
	return arbre->hauteur;
}

void maj_hauteur(AVL * arbre){

	if(arbre)
		arbre->hauteur=max(ABR_hauteur(arbre->fd),ABR_hauteur(arbre->fg));
}

AVL* rotation_droite(AVL * arbre){
	AVL *r=arbre;
	AVL*g=r->fg;
	AVL*v=g->fd;
	r->fg=v;
	g->fd=r;
	arbre=g;
	maj_hauteur(arbre);
	maj_hauteur((arbre)->fd);
	return arbre;

}

AVL *rotation_gauche(AVL* arbre){

	AVL *P=arbre;
	AVL *q=p->fd;
	AVL *v=q->fg;
	q->fg=p;
	p->fd=v;
	(arbre)=q;

	maj_hauteur(arbre);
	maj_hauteur((arbre)->fg);
return arbre;
}
AVL *rotation_double_gauche(AVL** arbre ){
	arbre->fd=rotation_droite(arbre->fd);
	maj_hauteur(arbre);
	return rotation_gauche(arbre);
}

}
AVL * rotation_double_droit(AVL* arbre){
	arbre->fg=rotation_gauche(arbre->fg);
	maj_hauteur(arbre);
	return rotation_droite(arbre);
}


AVL * bien_equilibre(AVL *arbre){
	int HD,HG;
	int hd,hg;
if(arbre){
	HD=ABR_hauteur(arbre->fd);
	HG=ABR_hauteur(arbre->fg);
	if((HG-HD)==2){
		hg=ABR_hauteur(arbre->fg->fg);
		hd=ABR_hauteur(arbre->fg->fd);
		if(hg<hd)
			rotation_gauche(arbre->fg);
		rotation_droite(arbre);
	
	}
	if((HG-HD)==-2){
		hg=ABR_hauteur(arbre->fd->fg);
		hd=ABR_hauteur(arbre->fd->fd);
		if(hg<hd)
			rotation_gauche(arbre->fd);
		rotation_droite(arbre);
	}

}

}

