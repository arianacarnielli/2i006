#ifndef __ALGOAVL__
#define __ALGOAVL__

typedef struct element{
	int val;
	int hauteur;
	struct element* fg;
	struct element* fd;
}AVL;


/* Cree un noeud de l'AVL et initialise ses fils a NULL. */
AVL* crer_noeud(int val);

/* Insere la valeur passe en argument dans l'AVL, creant un nouveau noeud. L'AVL retourne est deja equilibre. */
AVL* inserer_AVL(AVL* arbre,int val);

/* Retourne la hauteur de l'AVL passe en argument. */
int ABR_hauteur(AVL* arbre);

/* Mis a jour la hauteur du noeud de l'AVL passe en argument. */
void maj_hauteur(AVL* arbre);

/* Mis a jour la hauteur de l'AVL passe en argument recursivement. */
void maj_toutes_hauteurs(AVL* arbre);

/* Reequilibre l'AVL passe en argument, actualisant les hauteurs des noeuds. */
AVL* equilibrer(AVL* arbre);

/* Fait une rotation droit. */
AVL* rotation_droite(AVL * arbre);

/* Fait une rotation gauche. */
AVL *rotation_gauche(AVL* arbre);

AVL *rotation_double_gauche(AVL* arbre );
AVL * rotation_double_droit(AVL* arbre);


#endif