#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "AVL.h" 

AVL* creer_noeud(int val){
	AVL* res = malloc(sizeof(AVL));
	res->hauteur = 0;
	res->val = val;
	res->fg = NULL;
	res->fd = NULL;
	return res;
}

int ABR_hauteur(AVL* arbre){
	if(arbre == NULL){
		return -1;
	}
	return arbre->hauteur;
}

void maj_hauteur(AVL* arbre){

	if(arbre){
		printf ("%d",fmax(2,1));
		arbre->hauteur = 1 + fmax(ABR_hauteur(arbre->fd), ABR_hauteur(arbre->fg));
	}
}

void maj_toutes_hauteurs(AVL* arbre){
	if(arbre){
		maj_toutes_hauteurs(arbre->fg);
		maj_toutes_hauteurs(arbre->fd);
		maj_hauteur(arbre);
	}
}

AVL* inserer_AVL(AVL* arbre,int val){

	if(arbre == NULL){
		return creer_noeud(val);
	}	
	if(val < arbre->val){ /* Si la nouvelle valeur est plus petite que la racine */
		if(arbre->fg == NULL){ /* Si la racine n'a pas de fils gauche */
			AVL*nv = creer_noeud(val);
			arbre->fg = nv;
		}else{ /* La racine a un fils gauche deja, on fait l'appel recursif */
			arbre->fg = inserer_AVL(arbre->fg,val);
		}
	}else{ /* La nouvelle valeur est plus grande que la racine */
		if(arbre->fd == NULL){ /* Si la racine n'a pas de fils droit */
			AVL* nv = creer_noeud(val);
			arbre->fd = nv;
		}else{ /* La racine a un fils droit deja, on fait l'appel recursif*/
			arbre->fd = inserer_AVL(arbre->fd,val);
		}
	}
	arbre = equilibrer(arbre);
	return arbre;
}

AVL* equilibrer(AVL* arbre){
	int HD,HG; /* Les hauteurs des fils gauche et droite de l'arbre */
	int hd,hg; /* Les hauteurs de 2 petits fils de l'arbre, soit les fils du fils gauche ou droit. */
	if(arbre){
		HD = ABR_hauteur(arbre->fd);
		HG = ABR_hauteur(arbre->fg);
		if(HG-HD == 2){
			hg = ABR_hauteur(arbre->fg->fg);
			hd = ABR_hauteur(arbre->fg->fd);
			if(hg < hd){
				arbre->fg = rotation_gauche(arbre->fg);
			}
			arbre = rotation_droite(arbre);
		}
		if(HG-HD == -2){
			hg = ABR_hauteur(arbre->fd->fg);
			hd = ABR_hauteur(arbre->fd->fd);
			if(hg < hd){
				arbre->fd = rotation_gauche(arbre->fd);
			}
			arbre = rotation_droite(arbre);
		}
	maj_hauteur(arbre);
	}
	return arbre;
}

AVL* rotation_droite(AVL* arbre){
	
	AVL* racine = arbre;
	AVL* gauche = arbre->fg;
	AVL* ptf_droit = gauche->fd;
	racine->fg = ptf_droit;
	gauche->fd = racine;
	arbre = gauche;
	
	maj_hauteur(arbre->fd);
	maj_hauteur(arbre);

	return arbre;
}

AVL* rotation_gauche(AVL* arbre){

	AVL* racine = arbre;
	AVL* droit = racine->fd;
	AVL* ptf_gauche = droit->fg;
	droit->fg = racine;
	racine->fd = ptf_gauche;
	arbre = droit;
		
	maj_hauteur(arbre->fg);
	maj_hauteur(arbre);

	return arbre;
}

AVL* supprimer_noeud(AVL* arbre, int val){
	AVL* racine = arbre;
	
	if(arbre->val < val){ /* Si la valeur recherche est plus petite que la racine. */
		arbre->fg = supprimer_noeud(arbre->fg, val);
	}else{
		if(arbre->val > val){ /* Si la valeur recherche est plus grande que la racine. */
			arbre->fd = supprimer_noeud(arbre->fd, val);
		}else{
			if (arbre->fg == NULL){ /* On a que le fils droit, il devient la nouvelle racine */
				racine = arbre->fd;
				free(arbre);
			}else{
				int max;
				arbre->fg = supprimer_noeud(arbre->fg, max);
				arbre->val = max;
			}
		}
	}
	return racine;
}

void affiche_infixe(AVL* arbre){

	if (arbre){
		affiche_infixe(arbre->fg);
		printf("val: %d et hauteur: %d \n", arbre->val, ABR_hauteur(arbre));
		affiche_infixe(arbre->fd);
	}
}
/* 
AVL* rotation_double_gauche(AVL* arbre ){
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
 */



