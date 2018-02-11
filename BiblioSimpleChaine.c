#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BiblioSimpleChaine.h"
#include "entree_sortie.h"

#define TAILLE_CHAINE_MAX 200

void initialise_biblio(Biblio *b){
	b->L = NULL;
	b->nbliv = 0;
}

void affichage_livre(s_livre* L){
	if(L != NULL){
		printf("Livre numero %d :\ntitre : %s \nauteur : %s\n\n",L->num,L->titre,L->auteur);
	}
}

void affichage(Biblio *b){
	s_livre* tmp = b->L;
	while(tmp){
		affichage_livre(tmp);
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
	if(L->num == -1){
		L->num = b->L->num + 1;
	}
	L->suiv = b->L;
	b->L = L;
	b->nbliv++;
}

void supression_livre(Biblio* b, s_livre* L){
	s_livre* tmp = b->L;
	int trouve = 0;
	if(tmp==L){
		b->L = tmp->suiv;
		free(tmp->titre);
		free(tmp->auteur);
		free(tmp);
		b->nbliv--;
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
		b->nbliv--;
	}
}

void supression_biblio(Biblio* b){
	s_livre* tmp = b->L;
	while(tmp){
		supression_livre(b, tmp);
		tmp = b->L;
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
			insertion_livre(&new_b, clone_livre(tmp));
		}
		tmp = tmp->suiv;
	}
	return new_b;
}

Biblio rec_livres_double(Biblio* b){
	s_livre* tmp = b->L;
	Biblio new_b;
	initialise_biblio(&new_b);
	while(tmp){
		s_livre* test = b->L;
		while(test){
				if((tmp != test) && (strcmp(tmp->auteur, test->auteur) == 0) && (strcmp(tmp->titre, test->titre) == 0)){
					insertion_livre(&new_b, clone_livre(tmp));
					break;
				}
				test = test->suiv;
		}
		tmp = tmp->suiv;
	}
	return new_b;
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


