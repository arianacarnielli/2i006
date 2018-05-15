#include <stdlib.h>
#include <stdio.h>

#include "Graphe.h"
#include "algorithme_couleur.h"
#include "circuit.h"
#include "Solution.h"
#include "Grille.h"


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
	if (temp->suiv == NULL){
		S->dern = temp;
	}
	if (a != 'S'){
		(S->cptr_pas)++;
		Tref[j] = temp;
	}
	return temp;
}


Cell_char* pluscourtchemin_apres_c(Solution* S, Cell_char* c, int j, int l, Cell_char** Tref){
	int i;
	int cpt = j - l;
	int val = abs(cpt);
	int temp = j;
	Cell_char* new = c;

	for(i = 0; i < val; i++){
		if(cpt > 0){
			temp--;
			new = Ajout_action_apres_c(S, new, temp, 'L', Tref);
		}else{
			temp++;
			new = Ajout_action_apres_c(S, new, temp, 'R', Tref);
		}
	}
	return new;
}


void Ajout_circuit_dans_solution(Cell_circuit* cc, Solution* S, Cell_char* c, Cell_char** Tref, int* Jdroite){
	CelluleLDC* temp1 = (cc->L).premier;
	CelluleLDC* temp2 = temp1->suiv;
	Cell_char* new = c;
	
	if (cc->jmax > *Jdroite){
		*Jdroite = cc->jmax;
	}
	new = Ajout_action_apres_c(S, new, cc->jmin, 'S', Tref);

	while(temp2 != NULL){
		new = pluscourtchemin_apres_c(S, new, temp1->j, temp2->j, Tref);	
		new = Ajout_action_apres_c(S, new, temp2->j, 'S', Tref);
		temp1 = temp2;
		temp2=temp2->suiv;	
	}
}

void algorithme_circuit_CasLigne1x1(Grille *G, Solution *S, int graine){
	if ((G->m != 1) || (G->n != G->nbcoul)){
		printf("Pas possible de resoudre le jeu.\n");
		return;
	}
	int k, l;
	int Jdroite, JdroiteSav, Drapeau;
	Cell_circuit* temp;
	
	//Creer le graphe H
	Graphe H;
	Graphe_creation(G, &H);
	
	//Creer la liste LC des circuits de H
	Lcircuit l_c;
	LcircuitInitialise(&l_c);
	Graphe_Rech_Circuit(&H, &l_c);
	
	//Calculer jmin et jmax pour chaque circuit
	//Faire en sorte que chaque circuit commence par sa case jmin
	//Trier la liste LC des circuits selon les jmin croissants
	CalculJminJmax(&l_c);
	
	//Creer une solution S vide
	Solution_init(S);
	
	//Creer un tableau de pointeurs Tref de n cases NULL.
	Cell_char** Tref = (Cell_char**)calloc(G->n, sizeof(Cell_char*)); 
	
	//Intialiser un indice de case Jdroite a 0.
	Jdroite = 0;
	Drapeau = 0;
	
	//Pour chaque circuit temp de LC dans l’ordre des jmin croissants
	for (temp = l_c.premier; temp!= NULL; temp = temp->suiv){
		//Si Tref[temp->jmin] est NULL Alors:
		if (Tref[temp->jmin] == NULL){
			//On met Drapeau a vrai et on sauvegarde Jdroite dans JdroiteSav
			Drapeau = 1;
			// Il faut tester pour eviter le cas ou le robot essaie de retourner vers la case (0,0) même si elle etait noire au debut.
			if(Jdroite == 0){
				JdroiteSav = temp->jmin;
			}else{	
				JdroiteSav = Jdroite;
			}
			
			//Inserez une sequence de deplacements "R" allant de Jdroite a C->jmin dans la solution S a la suite du pointeur Tref[Jdroite]
			//mettre a jour Tref
			pluscourtchemin_apres_c(S, Tref[Jdroite], Jdroite, temp->jmin, Tref);
			
			//mettre a jour Jdroite 
			Jdroite = temp->jmin;
		}
		// Ajouter une sequence de deplacements "S", "L" et "R" correspondant au circuit C dans la solution S a la suite du pointeur Tref[temp->jmin]
		//Ne pas oublier de mettre a jour Jdroite et Tref
		Ajout_circuit_dans_solution(temp, S, Tref[temp->jmin], Tref, &Jdroite);
		
		//Si Drapeau Alors :
		if (Drapeau){
			//On met Drapeau a faux
			Drapeau = 0;
		
			//Inserez une sequence de deplacements "L" allant de temp->jmin a JdroiteSav dans la solution S a la suite du pointeur Tref pour la case temp->jmin
			//[Attention, il faut inserer cette sequence apres l’action "S" et non avant]
			//Ne pas oublier de mettre a jour Tref
			pluscourtchemin_apres_c(S, Tref[temp->jmin]->suiv, temp->jmin, JdroiteSav, Tref);
		}
	}
	Ecriture_Disque(G->m, G->n, G->nbcoul, graine, S);
	
	Graphe_desalloue(&H);
	
	Lcircuit_desalloue(&l_c);
	
	Solution_desalloue(S);
}