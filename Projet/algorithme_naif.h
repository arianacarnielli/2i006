#ifndef __ALGONAIF__
#define __ALGONAIF__

#include "Solution.h"
#include "Grille.h"
 
/* Mettre dans solution S le chemin le plus court entre (i,j) et (k,l). Il fait d'abord le deplacement vertical et après le deplacement horizontal. */
void PlusCourtChemin(Solution *S, int i, int j, int k, int l);

/* Retourne dans k et j les coordonnees de la premiere case la plus proche de (i,j) de couleur c et qui n'est pas deja noire. Si aucune case de cette couleur n'est disponible, k et l restent inchanges (ce cas n'est pas cense arriver). */ 
void RechercheCaseNaif_c(Grille *G, int c, int i, int j, int* k, int* l);

/* Retourne dans k et j les coordonnees de la premiere case la plus proche de (i,j) qui n'est pas noire et qui contient une piece. Si aucune case remplissant ces conditions n'est disponible, k et l restent inchanges (ce cas n'est pas cense arriver). */
void RechercheCaseNaif_nn(Grille *G, int i, int j, int* k, int* l);

/* Implemente l'algorithme naif decrit dans l'enonce. La solution S est initialise a l'interieur de la fonction. Le parametre graine est utilisee lors de l'ecriture de la solution en disque, on a choisi de le passer en argument. */
void algorithme_naif(Grille *G, Solution *S, int graine);
 
#endif