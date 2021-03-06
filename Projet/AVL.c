#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "AVL.h" 


int maximum(int i, int j){
	if (i < j){
		return j;
	}else{
		return i;
	}
}


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
		arbre->hauteur = 1 + maximum(ABR_hauteur(arbre->fd), ABR_hauteur(arbre->fg));
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
	if (arbre->val == val) {
		return arbre;
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
		}else{ /* La racine a un fils droit deja, on fait l'appel recursif  */
			arbre->fd = inserer_AVL(arbre->fd,val);
		}
	}
	maj_hauteur(arbre);
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
			if(hg > hd){
				arbre->fd = rotation_droite(arbre->fd);
			}
			arbre = rotation_gauche(arbre);
		}
	maj_hauteur(arbre->fg);
	maj_hauteur(arbre->fd);
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

AVL* supprimer_noeud_max(AVL* arbre, int* max){
	if(arbre){
		AVL* racine;
		if(arbre->fd == NULL){
			*max = arbre->val;
			racine = arbre->fg;
			free(arbre);
			return racine;
		}
		arbre->fd = supprimer_noeud_max(arbre->fd, max);
		arbre = equilibrer(arbre);
		return arbre;
	}
	return arbre;
}

AVL* supprimer_noeud(AVL* arbre, int val){
	if(arbre){

		AVL* racine = arbre;
		
		if(val < arbre->val){ /* Si la valeur recherche est plus petite que la racine. */
			//printf("valeur plus petite\n ");
			arbre->fg = supprimer_noeud(arbre->fg, val);
			arbre = equilibrer(arbre);
			return arbre;
		}
		
		if(val > arbre->val){ /* Si la valeur recherche est plus grande que la racine. */
			//printf("valeur plus grande\n");
			arbre->fd = supprimer_noeud(arbre->fd, val);
			arbre = equilibrer(arbre);
			return arbre;
		}
		
		//printf("valeur trouve\n");
		if (arbre->fg == NULL){ /* On a que le fils droit, il devient la nouvelle racine */
			//printf("on essaie de liberer le noeud\n");
			racine = arbre->fd;
			free(arbre);
			return racine;
		}
		
		//printf("il a le fils gauche, on essaie de supprimer le fils gauche e remplacer la racine.\n");
		int max;
		arbre->fg = supprimer_noeud_max(arbre->fg, &max);
		arbre->val = max;
		arbre = equilibrer(arbre);
		return arbre;
	}
	return arbre;
}

void affiche_infixe(AVL* arbre){

	if (arbre){

		affiche_infixe(arbre->fg);

		printf("val: %d et hauteur: %d \n", arbre->val, ABR_hauteur(arbre));

		affiche_infixe(arbre->fd);
	}
}

int recherche_plus_proche(AVL* arbre, int c){
	int plus_proche;
	
	/* Cas de base, la valeur n'est pas dans l'arbre. */
	if(arbre == NULL){
		return -1;
	}
	
	/* Cas de base, la valeur est dans l'arbre. */
	if(arbre->val == c){
		return c;
	}
	
	/* Recherche dichotomique récursive. */
	if(arbre->val > c){
		plus_proche = recherche_plus_proche(arbre->fg, c);
	}else{
		plus_proche = recherche_plus_proche(arbre->fd, c);
	}
	
	/* Si le fils est NULL, alors la plus proche est la racine. */
	if(plus_proche == -1){
		return arbre->val;
	}
	
	/* Détermine si le plus proche est la racine ou la valeur de retour de l'appel récursif. */
	if(abs(plus_proche - c) < abs(arbre->val - c)){
		return plus_proche;
	}
	if(abs(plus_proche - c) > abs(arbre->val - c)){
		return arbre->val;
	}
	
	/* En cas d'égalité, la fonction retourne la plus petite valeur des deux. */
	if(arbre->val < plus_proche){
		return arbre->val;
	}
	return plus_proche;
}

int est_AVL(AVL* arbre){
	if(arbre){
		return ((abs(ABR_hauteur(arbre->fg) - ABR_hauteur(arbre->fd)) < 2) && (est_AVL(arbre->fg)) &&(est_AVL(arbre->fd)));
	}
	return 1;
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



