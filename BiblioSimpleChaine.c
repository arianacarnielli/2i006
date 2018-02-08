#include <stdio.h>
#include <stlib.h>
#include "BiblioSimpleChaine.h"
#include "entree_sortie.h"

#define TAILLE_CHAINE_MAX 200

void  initialise_biblio(Biblio *b){
	b->L = NULL;
	b->nbliv = 0;
}

void affichage(Biblio *b){
	s_livre* tmp = b->L;
	while(tmp){
		printf("Les informations du livre numero %d sont :\ntitre : %s \nauteur : %s\n\n",tmp->num,tmp->titre,tmp->auteur);
		tmp = tmp->suiv;
	}
}

s_livre* creation_livre(int num, char* titre, char* auteur){
	s_livre* L = (s_livre*) malloc(sizeof(s_livre));
	L->num = num;
	L->titre = strdup(titre);
	L->auteur = strdup(auteur);
	L->suiv = NULL;
	return L;
}

void insertion_livre(Biblio* b, s_livre* L){
	L->suiv = b->L;
	b->L = L;
}

void supression_livre(Biblio* b, s_livre* L){
	s_livre* tmp = b->L;
	int trouve = 0;
	if(tmp==L){
		b->L = tmp->suiv;
		free(tmp->titre);
		free(tmp->auteur);
		free(tmp);
		return;
	}
	while((tmp->suiv)&&(!trouve)){
		if(tmp->suiv==L){
			tmp->suiv = L->suiv;
			free(L->titre);
			free(L->auteur);
			free(L);
			trouve = 1;
		}
		tmp = tmp->suiv;
	}
	if(!trouve){
		printf("Le livre a supprimer n'a pas ete trouve dans cette bibliotheque.\n");
	}
}

s_livre* clone_livre(s_livre* L){
	return creation_livre(L->num, L->titre, L->auteur);
}

void lecture_n_entree(char* nomfic, int n, Biblio* b){
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
		insertion_livre(b, tmp);
		cpt++;		
	}	
}

s_livre* rec_livre_num(Biblio* b, int nb){
	s_livre* tmp = b->L;
	while(tmp){
		if(tmp->num == nb){
			return tmp;
		}
		tmp = tmp->suiv;
	}
	return NULL;
}

s_livre* rec_livre_titre(Biblio* b, char* titre){
	s_livre* tmp = b->L;
	while(tmp){
		if(strcmp(tmp->titre, titre) == 0){
			return tmp;
		}
		tmp = tmp->suiv;
	}
	return NULL;
}

Biblio rec_livres_auteur(Biblio* b, char* auteur){
	s_livre* tmp = b->L;
	Biblio new_b;
	initialise_biblio(&new_b);
	while(tmp){
		if(strcmp(tmp->auteur, auteur) == 0){
			insertion_livre(new_b, clone_livre(tmp));
		}
		tmp = tmp->suiv;
	}
	return new_b;
}

void menu(){
	
	
	
	
}


