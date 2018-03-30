#ifndef __AVL__
#define __AVL__

typedef struct element{
	int val;
	int hauteur;
	struct element* fg;
	struct element* fd;
}AVL;


/* Cree un noeud de l'AVL et initialise ses fils a NULL. */
AVL* creer_noeud(int val);

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

/* Supprime le noeud de l'AVL passe en argument avec la plus grande valeur. Sauvegarde cette valeur dans max. */
AVL* supprimer_noeud_max(AVL* arbre, int* max);

/* Supprime le noeud de l'AVL qui a val comme valeur et renvoie la nouvelle AVR. Si la valeur recherche n'est pas dans l'arbre, ne fait rien. */
AVL* supprimer_noeud(AVL* arbre, int val);

void affiche_infixe(AVL* arbre);

/* Calcule le max entre du entiers. On l'utilise car la fonction max de stdlib retourne de resultats bizarres. */
int maximum(int i, int j);



// AVL *rotation_double_gauche(AVL* arbre );
// AVL * rotation_double_droit(AVL* arbre);


#endif