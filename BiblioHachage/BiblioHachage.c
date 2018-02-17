#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "BiblioHachage.h"
#include "entree_sortie.h"

#define TAILLE_CHAINE_MAX 200

tableHachage_t* initTableHachage(int m){
	tableHachage_t* res = (tableHachage_t*) malloc(sizeof(tableHachage_t));
	res->m = m;
	res->nE = 0;
	res->ind_max = 0;
	res->T = (s_livre**) malloc(sizeof(s_livre*)*m);
	int i;
	for(i = 0; i < m; i++){
		res->T[i] = NULL;
	}
	return res;
}

unsigned int fonctionClef(char* nom){
	unsigned int s = 1;
	int i = 0;
	while(nom[i] != '\0'){
		s = s * nom[i];
		/* On a choisii de multiplier les codes ASCII car cela donne des nombres plus grands, on a beaucoup plus de clefs possibles. */
		i++;
	}
	return s;
}

unsigned int fonctionHachage(int m, unsigned int clef){
	double A = (sqrt(5) - 1) / 2.;
	return (unsigned int)(m * (clef * A - (unsigned int)(clef * A)));
	//return (unsigned int)(m * fmod(clef * A, 1));
	
}

void affichage_livre(s_livre* L){
	if(L != NULL){
		printf("Livre numero %d :\ntitre : %s \nauteur : %s\n\n",L->num,L->titre,L->auteur);
	}
}

void affichage(tableHachage_t* t){
	int i;
	s_livre* tmp;
	for(i = 0; i < t->m; i++){
		tmp = t->T[i];
		while(tmp){
			affichage_livre(tmp);
			tmp = tmp->suiv;
		}
	}
}

s_livre* creation_livre(int num, char* titre, char* auteur){
	s_livre* L = (s_livre*) malloc(sizeof(s_livre));
	L->num = num;
	L->titre = strdup(titre);
	L->auteur = strdup(auteur);
	L->suiv = NULL;
	L->clef = fonctionClef(auteur);
	return L;
}
	
void insertion_livre(tableHachage_t* t, s_livre* L){
	if(L->num == -1){
		L->num = t->ind_max + 1;
	}
	unsigned int indice = fonctionHachage(t->m, L->clef);
	L->suiv = t->T[indice];
	t->T[indice] = L;
	t->nE++;
	if(L->num > t->ind_max){
		t->ind_max = L->num;
	}	
}

void supression_livre(tableHachage_t* t, s_livre* L){
	unsigned int indice = fonctionHachage(t->m, L->clef);
	s_livre* tmp = t->T[indice];
	int trouve = 0;
	if(tmp == L){
		t->T[indice] = tmp->suiv;
		free(tmp->titre);
		free(tmp->auteur);
		free(tmp);
		t->nE--;
		return;
	}
	while((tmp->suiv)&&(!trouve)){
		if(tmp->suiv==L){
			tmp->suiv = L->suiv;
			free(L->titre);
			free(L->auteur);
			free(L);
			trouve = 1;
		}else{
			tmp = tmp->suiv;
		}
	}
	if(!trouve){
		printf("Le livre a supprimer n'a pas ete trouve dans cette bibliotheque.\n");
	}else{
		t->nE--;
	}
}

void supression_biblio(tableHachage_t* t){
	int i;
	s_livre* tmp;
	for(i = 0; i < t->m; i++){
		tmp = t->T[i];
		while(tmp){
			supression_livre(t, tmp);
			tmp = t->T[i];
		}
	}
	free(t->T);
	free(t);
}

void lecture_n_entree(char* nomfic, int n, tableHachage_t* t){
	FILE *f =fopen(nomfic ,"r"); 
	if(f==NULL){
		fprintf(stderr ,"Erreur lors de l'overture du fichier");
		return;
	}
	char titre[TAILLE_CHAINE_MAX];
	char auteur[TAILLE_CHAINE_MAX];
	int num;
	int cpt = 0;
	s_livre* tmp;
	while((cpt < n)&&(!feof(f))){
		num = GetEntier(f);
		GetChaine(f,TAILLE_CHAINE_MAX, titre);
		GetChaine(f,TAILLE_CHAINE_MAX, auteur);
		tmp = creation_livre(num, titre, auteur);
		insertion_livre(t, tmp);
		cpt++;		
	}	
	fclose(f);
}

s_livre* rec_livre_num(tableHachage_t* t, int nb){
	int i;
	s_livre* tmp;
	for(i = 0; i < t->m; i++){
		tmp = t->T[i];
		while(tmp){
			if(tmp->num == nb){
				return tmp;
			}
			tmp = tmp->suiv;
		}
	}
	return NULL;
}

s_livre* rec_livre_titre(tableHachage_t* t, char* titre){
	int i;
	s_livre* tmp;
	for(i = 0; i < t->m; i++){
		tmp = t->T[i];
		while(tmp){
			if(strcmp(tmp->titre, titre) == 0){
				return tmp;
			}
			tmp = tmp->suiv;
		}
	}
	return NULL;
}

int rec_livres_auteur(tableHachage_t* t, char* auteur){
	int cpt = 0;
	unsigned int indice = fonctionHachage(t->m, fonctionClef(auteur));
	s_livre* tmp = t->T[indice];
	while(tmp){
		if(strcmp(tmp->auteur, auteur) == 0){
			affichage_livre(tmp);
			cpt++;
		}
		tmp = tmp->suiv;
	}
	return cpt;
}

int rec_livres_double(tableHachage_t* t){
	s_livre* tmp; 
	s_livre* test;
	int cpt = 0;
	int i;

	for(i = 0; i < t->m; i++){
		tmp = t->T[i];
		while(tmp){
			test = t->T[i];
			while(test){
				if((tmp != test) && (strcmp(tmp->auteur, test->auteur) == 0) && (strcmp(tmp->titre, test->titre) == 0)){
					affichage_livre(tmp);
					cpt++;
					break;
				}
				test = test->suiv;
			}
			tmp = tmp->suiv;
		}
	}
	return cpt;
}

void menu(){
	printf("#####Menu#####\n\n");
	printf("1 : Affichage de la bibliotheque\n");
	printf("2 : Insertion d'un nouvel ouvrage\n");
	printf("3 : Suppression d'un ouvrage\n");
	printf("4 : Recherche d'un ouvrage par titre\n");
	printf("5 : Recherche d'un ouvrage par numero d'identification\n");
	printf("6 : Recherche des ouvrages d'un meme auteur\n");
	printf("7 : Recherche des ouvrages repetes\n");
	printf("0 : Sortir du programme\n");	
}






	
