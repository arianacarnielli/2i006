#include <stdlib.h>
#include <stdio.h>

#include "Graphe.h"
#include "ListeDC.h"
#include "circuit.h"


Cell_char* Ajout_action_apres_c(Solution* S, Cell_char* c, int j, char a, Cell_char** Tref){
	Cell_char* temp = (Cell_char*) malloc(sizeof(Cell_char));
	temp->a = a;
	if (c != NULL){
		temp->suiv = c->suiv;
		c->suiv = temp;

	}else{
		temp->suiv = S->prem;
		S->prem = temp;
	}

	if (S->dern == NULL){
		S->dern = temp;
	}

	if (a != 'S'){
		(s->cptr_pas)++;
	}
	Tref[j] = c;
	return temp;
}


Cell_char* pluscourtchemin_apres_c(Solution* S, Cell_char* c, int j, int l, Cell_char** Tref){
	int cpt=j-l;
	int val = abs(cpt);
	int temp = j;
	Cell_char* new;

	for(i=0;i<val;i++){
		if(cpt>0){
			temp--;
			new = Ajout_action_apres_c(S, c, temp,'L',Tref);
		}else{
			temp++;
			new = Ajout_action_apres_c(S, c, temp,'R',Tref);
		}
	}
	return new;
}


void Ajout_circuit_dans_solution(LDC* L, Solution* S, Cell_char* c, Cell_char** Tref, int* Jdroite){


}

qui insere une sequence de deplacements “L”, “R” et “S” du robot dans S correspondant au circuit C. 
Cette fonction a pour pre-requis que le tableau Tref pour la case C->jmin pointe sur un d eeplacement 
menant le robot a cette case. Cette fonction consiste a appeler la fonction pluscourtchemin_apres_c
pour chaque arc de C. La fonction doit mettre a jour en continu Tref et Jdroite.
