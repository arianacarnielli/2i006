#include <stdlib.h>
#include <stdio.h>

#include "Graphe.h"
#include "algorithme_couleur.h"
#include "circuit.h"



void Graphe_Affiche_Circuit(Graphe *H){
	int i, j;
	
	for(i = 0; i < H->m; i++){
		for(j = 0; j < H->n; j++){
			if(H->Tsom[i][j]->visit == -1){
				Affiche_Circuit(H->Tsom[i][j]);
			}
		}
	}
}

void Graphe_Rech_Circuit(Graphe *H, Lcircuit* l_c){
	int i, j;
	Cell_circuit* temp;
	
	for(i = 0; i < H->m; i++){
		for(j = 0; j < H->n; j++){
			if(H->Tsom[i][j]->visit == -1){
				temp = creer_Cell_circuit();
				Rech_Circuit(H->Tsom[i][j], &(temp->L));
				LcircuitInsererEnFin(l_c, temp);
			}
		}
	}
}

void Rech_Circuit(Sommet *S, LDC* L){
	Sommet* tempS;
	Arc* tempA;
	
	int trouve = 0;
	tempS = S;
	
	if(tempS->visit == -1){
		tempS->visit = 0;
		LDCInsererEnFin(L, S->i, S->j);
	
		while(!trouve){
			for(tempA = tempS->Lsucc; tempA != NULL; tempA = tempA->suiv){
				if(tempA->succ == S){
					trouve = 1;
					LDCInsererEnFin(L, S->i, S->j);
					break;
				}
				if(tempA->succ->visit == -1){
					tempS = tempA->succ;
					tempS->visit = 0;
					LDCInsererEnFin(L, tempS->i, tempS->j);
					break;
				}
			}
		}
	}
}


void Affiche_Circuit(Sommet *S){
	Sommet* tempS;
	Arc* tempA;
	
	int trouve = 0;
	tempS = S;
	
	if(tempS->visit == -1){
		tempS->visit = 0;
		printf("Circuit : \n(%d, %d)\n", S->i, S->j);
	
		while(!trouve){
			for(tempA = tempS->Lsucc; tempA != NULL; tempA = tempA->suiv){
				if(tempA->succ == S){
					trouve = 1;
					printf("(%d, %d)\n", S->i, S->j);
					printf("Circuit ferme.\n\n");
					break;
				}
				if(tempA->succ->visit == -1){
					tempS = tempA->succ;
					tempS->visit = 0;
					printf("(%d, %d)\n",tempS->i, tempS->j);
					break;
				}
			}
		}
	}
}

void reset_visit(Graphe* H){
	int i, j;
	
	for(i = 0; i < H->m; i++){
		for(j = 0; j < H->n; j++){
			if (H->Tsom[i][j]->Lsucc != NULL){
				H->Tsom[i][j]->visit = -1;
			}
		}
	}
}


Cell_circuit* creer_Cell_circuit(){
	Cell_circuit* new = (Cell_circuit*)malloc(sizeof(Cell_circuit));
	LDCInitialise(&(new->L));
	new->jmin = -1;
	new->jmax = -1;
	new->suiv = NULL;
	return new;
}

void LcircuitInitialise(Lcircuit* l_c){
	l_c->nb_circuit = 0;
	l_c->premier = NULL;
	l_c->dernier = NULL;
}

int LcircuitVide(Lcircuit* l_c){
	return (l_c->premier == NULL);
}

void LcircuitInsererEnFin(Lcircuit* l_c, Cell_circuit* cc){
	if(LcircuitVide(l_c)){
		l_c->premier = cc;
	}else{
		l_c->dernier->suiv = cc;
	}
	l_c->dernier = cc;
	l_c->nb_circuit++;
}

void Affiche_Lcircuit(Lcircuit* l_c){
	Cell_circuit* temp;
	for(temp = l_c->premier; temp; temp = temp->suiv){
		printf("jmin : %d, jmax : %d\n", temp->jmin, temp->jmax);
		LDCafficher(&(temp->L));	
	}
}

void CalculJminJmax(Lcircuit *l_c){
	Cell_circuit* temp;
	CelluleLDC* temp2;
	for(temp = l_c->premier; temp!= NULL; temp = temp->suiv){
		temp->jmin = (temp->L).premier->j;
		temp->jmax = (temp->L).premier->j;
		for (temp2 = (temp->L).premier; temp2 != NULL; temp2 = temp2->suiv){
			if(temp->jmax < temp2->j){
				temp->jmax = temp2->j;
			}
		}
	}
}

void Lcircuit_desalloue(Lcircuit* l_c){
	Cell_circuit* temp1;
	Cell_circuit* temp2;
	temp1 = l_c->premier;
	while(temp1){
		LDCdesalloue(&(temp1->L));
		temp2 = temp1->suiv;
		free(temp1);
		temp1 = temp2;
	}
}