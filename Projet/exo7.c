#include "Solution.h"
#include "Grille.h"
#include "bibliotheque.h"
#include "Graphe.h"
#include "ListeDC.h"
#include "Grille.h"
#include "circuit.h"
#include <stdlib.h>
#include <stdio.h>

void algorithme_exo7(Grille *G, Solution *S, int graine){
	int k, l;
	Graphe H;
	Lcircuit l_c;
	Cell_circuit* temp;
	CelluleLDC* temp2;
	
	Solution_init(S);

	Graphe_creation(G, &H);
	LcircuitInitialise(&l_c);
	Graphe_Rech_Circuit(&H, &l_c);

	Affiche_Lcircuit(&l_c);


	for (temp = l_c.premier; temp!= NULL; temp = temp->suiv){
		for (temp2 = (temp->L).premier; temp2 != NULL; temp2 = temp2->suiv){
			k = temp2->i;
			l = temp2->j;

			PlusCourtChemin(S, G->ir, G->jr, k, l);
			changement_case(G, k, l);
			swap_case(G);
			Ajout_action(S, 'S');
		}
	}
	Ecriture_Disque(G->m, G->n, G->nbcoul, graine, S);
}


