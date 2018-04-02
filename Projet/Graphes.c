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
#define PROP_COUL 0.001
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
	printf("### Nombre de couleurs constante ###\n\n");
	
	fprintf(save, "# Version naive\n");
	fprintf(save, "# Nombre de couleurs constante : %d\n\n", CONST_COUL);
	fprintf(save, "n_naif_cst = []\n");
	fprintf(save, "temps_naif_cst = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_naif_cst.append(%d)\n", n);
		
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
		fprintf(save, "temps_naif_cst.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	
	n = 10;
	duree = 0.0;
	
	printf("### Version naive ###\n");
	printf("### Nombre de couleurs proportionnel ###\n\n");
	
	fprintf(save, "# Version naive\n");
	fprintf(save, "# Nombre de couleurs proportionnel : %f\n\n", PROP_COUL);
	fprintf(save, "n_naif_prp = []\n");
	fprintf(save, "temps_naif_prp = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_naif_prp.append(%d)\n", n);
		
		G.n = n;
		G.m = n;
		G.nbcoul = (int) ceil((double) PROP_COUL*n*n);
		if (G.nbcoul < 3) {
			G.nbcoul = 3;
		}
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
		fprintf(save, "temps_naif_prp.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}

	n = 10;
	duree = 0.0;
	
	printf("### Version circulaire ###\n");
	printf("### Nombre de couleurs constante ###\n\n");
	
	fprintf(save, "# Version circulaire\n");
	fprintf(save, "# Nombre de couleurs constante : %d\n\n", CONST_COUL);
	fprintf(save, "n_circ_cst = []\n");
	fprintf(save, "temps_circ_cst = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_circ_cst.append(%d)\n", n);
		
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
		fprintf(save, "temps_circ_cst.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	
	n = 10;
	duree = 0.0;
	
	printf("### Version circulaire ###\n");
	printf("### Nombre de couleurs proportionnel ###\n\n");
	
	fprintf(save, "# Version circulaire\n");
	fprintf(save, "# Nombre de couleurs proportionnel : %f\n\n", PROP_COUL);
	fprintf(save, "n_circ_prp = []\n");
	fprintf(save, "temps_circ_prp = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_circ_prp.append(%d)\n", n);
		
		G.n = n;
		G.m = n;
		G.nbcoul = (int) ceil((double) PROP_COUL*n*n);
		if (G.nbcoul < 3) {
			G.nbcoul = 3;
		}
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
		fprintf(save, "temps_circ_prp.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	
	n = 10;
	duree = 0.0;

	printf("### Version par couleur ###\n");
	printf("### Nombre de couleurs constante ###\n\n");
	
	fprintf(save, "# Version par couleur\n");
	fprintf(save, "# Nombre de couleurs constante : %d\n\n", CONST_COUL);
	fprintf(save, "n_coul_cst = []\n");
	fprintf(save, "temps_coul_cst = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_coul_cst.append(%d)\n", n);
		
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
		fprintf(save, "temps_coul_cst.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	
	n = 10;
	duree = 0.0;
	
	printf("### Version par couleur ###\n");
	printf("### Nombre de couleurs proportionnel ###\n\n");
	
	fprintf(save, "# Version par couleur\n");
	fprintf(save, "# Nombre de couleurs proportionnel : %f\n\n", PROP_COUL);
	fprintf(save, "n_coul_prp = []\n");
	fprintf(save, "temps_coul_prp = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_coul_prp.append(%d)\n", n);
		
		G.n = n;
		G.m = n;
		G.nbcoul = (int) ceil((double) PROP_COUL*n*n);
		if (G.nbcoul < 3) {
			G.nbcoul = 3;
		}
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
		fprintf(save, "temps_coul_prp.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	
	n = 10;
	duree = 0.0;
	
	printf("### Version par AVL ###\n");
	printf("### Nombre de couleurs constante ###\n\n");
	
	fprintf(save, "# Version par AVL\n");
	fprintf(save, "# Nombre de couleurs constante : %d\n\n", CONST_COUL);
	fprintf(save, "n_AVL_cst = []\n");
	fprintf(save, "temps_AVL_cst = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_AVL_cst.append(%d)\n", n);
		
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
		fprintf(save, "temps_AVL_cst.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	
	n = 10;
	duree = 0.0;
	
	printf("### Version par AVL ###\n");
	printf("### Nombre de couleurs proportionnel ###\n\n");
	
	fprintf(save, "# Version par AVL\n");
	fprintf(save, "# Nombre de couleurs proportionnel : %f\n\n", PROP_COUL);
	fprintf(save, "n_AVL_prp = []\n");
	fprintf(save, "temps_AVL_prp = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_AVL_prp.append(%d)\n", n);
		
		G.n = n;
		G.m = n;
		G.nbcoul = (int) ceil((double) PROP_COUL*n*n);
		if (G.nbcoul < 3) {
			G.nbcoul = 3;
		}
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
		fprintf(save, "temps_AVL_prp.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	
	fclose(save);
	
	return 0;
}