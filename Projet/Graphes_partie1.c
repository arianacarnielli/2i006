#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "algorithme_naif.h"
#include "algorithme_circulaire.h"
#include "algorithme_couleur.h"
#include "algorithme_AVL.h"
#include "Grille.h"
#include "Solution.h"

#define FILENAME "graphes_donnes.py"
#define REPEAT 10
#define CONST_COUL 10
#define DUREE_MAX 6.0

void Grille_desallocation(Grille *G){
    int i;
    for (i = 0; i < G-> m; i++) {
	    free(G->T[i]);
    }
    free(G->T);
}

int main() {
	Grille G;
	Solution S;
	
	clock_t start;
	double duree;
	int i, graine;
	int n;
	
	srand(time(NULL));
	
	FILE* save = fopen(FILENAME, "w");
	
	n = 10;
	duree = 0.0;
	
	printf("### Version naive ###\n");
	
	fprintf(save, "# Version naive\n");
	fprintf(save, "# Nombre de couleurs : %d\n\n", CONST_COUL);
	fprintf(save, "n_naif = []\n");
	fprintf(save, "temps_naif = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_naif.append(%d)\n", n);
		
		G.n = n;
		G.m = n;
		G.nbcoul = CONST_COUL;
		Grille_allocation(&G);
		
		duree = 0.0;
		
		for (i = 0; i < REPEAT; i++) {
			graine = rand();
			Gene_Grille(&G, graine);
			start = clock();
			algorithme_naif(&G, &S, graine);
			duree += (double)(clock() - start) / CLOCKS_PER_SEC;
		}
		
		duree /= REPEAT;
		
		printf("duree = %.16f\n\n", duree);
		fprintf(save, "temps_naif.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	
	n = 10;
	duree = 0.0;
	
	printf("### Version circulaire ###\n");
	
	fprintf(save, "# Version circulaire\n");
	fprintf(save, "# Nombre de couleurs : %d\n\n", CONST_COUL);
	fprintf(save, "n_circ = []\n");
	fprintf(save, "temps_circ = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_circ.append(%d)\n", n);
		
		G.n = n;
		G.m = n;
		G.nbcoul = CONST_COUL;
		Grille_allocation(&G);
		
		duree = 0.0;
		
		for (i = 0; i < REPEAT; i++) {
			graine = rand();
			Gene_Grille(&G, graine);
			start = clock();
			algorithme_circulaire(&G, &S, graine);
			duree += (double)(clock() - start) / CLOCKS_PER_SEC;
		}
	
		duree /= REPEAT;
		
		printf("duree = %.16f\n\n", duree);
		fprintf(save, "temps_circ.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
		
	n = 10;
	duree = 0.0;

	printf("### Version par couleur ###\n");
	
	fprintf(save, "# Version par couleur\n");
	fprintf(save, "# Nombre de couleurs : %d\n\n", CONST_COUL);
	fprintf(save, "n_coul = []\n");
	fprintf(save, "temps_coul = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_coul.append(%d)\n", n);
		
		G.n = n;
		G.m = n;
		G.nbcoul = CONST_COUL;
		Grille_allocation(&G);
		
		duree = 0.0;
		
		for (i = 0; i < REPEAT; i++) {
			graine = rand();
			Gene_Grille(&G, graine);
			start = clock();
			algorithme_couleur(&G, &S, graine);
			duree += (double)(clock() - start) / CLOCKS_PER_SEC;
		}
		
		duree /= REPEAT;
		
		printf("duree = %.16f\n\n", duree);
		fprintf(save, "temps_coul.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
		
	n = 10;
	duree = 0.0;
	
	printf("### Version par AVL ###\n");
	
	fprintf(save, "# Version par AVL\n");
	fprintf(save, "# Nombre de couleurs : %d\n\n", CONST_COUL);
	fprintf(save, "n_AVL = []\n");
	fprintf(save, "temps_AVL = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_AVL.append(%d)\n", n);
		
		G.n = n;
		G.m = n;
		G.nbcoul = CONST_COUL;
		Grille_allocation(&G);
		
		duree = 0.0;
		
		for (i = 0; i < REPEAT; i++) {
			graine = rand();
			Gene_Grille(&G, graine);
			start = clock();
			algorithme_AVL(&G, &S, graine);
			duree += (double)(clock() - start) / CLOCKS_PER_SEC;
		}
		
		duree /= REPEAT;
		
		printf("duree = %.16f\n\n", duree);
		fprintf(save, "temps_AVL.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
		
	fclose(save);
	
	return 0;
}