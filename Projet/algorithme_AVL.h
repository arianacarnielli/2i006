#ifndef __ALGOAVL__
#define __ALGOAVL__

#include "Grille.h"
#include "AVL.h" 

/* Cree un tableau a deux dimensions d'AVL* et les initialise. L'element d'indice (i, c) de ce tableau contient une AVL avec tous les indices de colonnes de la ligne i avec la couleur de fond c.. */
AVL*** creer_table_AVL(Grille* G);

/* Retourne dans k et j les coordonnees de la premiere case la plus proche de (i,j) de couleur c et qui n'est pas deja noire. Si aucune case de cette couleur n'est disponible, k et l restent inchanges (ce cas n'est pas cense arriver). */
void RechercheCaseAVL_c(Grille *G, int c, int i, int j, int* k, int* l, AVL*** M);

/* Retourne dans k et j les coordonnees de la premiere case la plus proche de (i,j) qui n'est pas noire et qui contient une piece. Si aucune case remplissant ces conditions n'est disponible, k et l restent inchanges (ce cas n'est pas cense arriver). */
void RechercheCaseAVL_nn(Grille *G, int i, int j, int* k, int* l, AVL*** M);

/* Implemente l'algorithme avec AVL decrit dans l'enonce de l'exercice 4. La solution S est initialise a l'interieur de la fonction. Le parametre graine est utilisee lors de l'ecriture de la solution en disque, on a choisi de le passer en argument. */
void algorithme_AVL(Grille *G, Solution *S, int graine);

#endif