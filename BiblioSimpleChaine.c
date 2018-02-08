#include<stdio.h>
#include<stlib.h>
#include "Biblio.h"
#include "entree_sortie.h"

void  initialise_biblio (Biblio *b){

		b->L=NULL;
		b->nbliv=0;

}


void affichage(Biblio *b){

	if(b==NULL)
		return ;
	s_livre *tmp=b->L;
	
	while(tmp){
		printf("Les informations du livre numero %d sont : \n titre : %s \n 	auteur :%s\n\n",tmp->num,tmp->titre,tmp->auteur);
		tmp=tmp->suiv;
	
	
	}
	

}


void lecture_n_entree(char *nomfic ,int n,Biblio *b){
	FILE *f =fopen(nomfic ,"w"); 
	if(f==NULL){
		fprintf(stderr ,"ERREUR LORS DE L'OUVERTURE");
		return ;
	}
	char ligne[200];
	char *auteur,titre;
	int num,cpt=0;
	while(cpt!=n){
		
		fgets(ligne ,200,f);
		sscanf(ligne ,"%d %s %s",&num,auteur,titre);
		
		cpt++;
	}

}


