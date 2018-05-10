#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Grille.h"
#include "Solution.h"
#include "algorithme_graphe.h"

#define FILENAME "graphes_donnes_partie2.py"
#define REPEAT 50
#define DUREE_MAX 5.0

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
	
	printf("### Version Graphe ###\n");
	
	fprintf(save, "# Version graphe\n");
	fprintf(save, "n_graphe = []\n");
	fprintf(save, "temps_graphe = []\n\n");
	
	while (duree < DUREE_MAX) {
		printf("n = %d\n", n);
		fprintf(save, "n_graphe.append(%d)\n", n);
		
		G.n = n;
		G.m = 1;
		G.nbcoul = G.n;
		Grille_allocation(&G);
		
		duree = 0.0;
		
		for (i = 0; i < REPEAT; i++) {
			graine = rand();
			Gene_Grille(&G, graine);
			start = clock();
			algorithme_circuit_CasLigne1x1(&G, &S, graine);
			duree += (double)(clock() - start) / CLOCKS_PER_SEC;
		}
		
		duree /= REPEAT;
		
		printf("duree = %.16f\n\n", duree);
		fprintf(save, "temps_graphe.append(%.16f)\n\n", duree);
		fflush(save);
		
		Grille_desallocation(&G);
		n += 10;
	}
	fclose(save);
	return 0;
}
	