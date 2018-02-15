#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BiblioHachage.h"
#include "entree_sortie.h"

#define NV_LIVRE_NB -1

int main(int argc ,char** argv){

	if(argc!=3){
		printf("Erreur format :	%s <NomFichierBiblio.txt> <NbLigneALire>\n", argv [0]);
		return 1;
	}
	
	int ch;
	char* nomfic;
	int nlignes;
	tableHachage_t* t;
	
	int  num;
	char titre[100];
	char auteur[100];
	s_livre* L;

	nomfic = strdup(argv [1]);
	nlignes = atoi(argv [2]);
	
	t = initTableHachage(nlignes);
	
	printf("Lecture\n");
	lecture_n_entree(nomfic, nlignes, t);
		
	do{
		menu();
		scanf("%d", &ch);
		
		switch(ch){
			
		case 1:
			printf("Affichage : \n");
			affichage (t);
			
			break;
			
		case 2: 
			printf("Insertion d'un nouvel ouvrage : \n\n");
			printf("Tapez le titre de l'ouvrage : \n");
			scanf("%s", titre);
			printf("Tapez l'auteur de l'ouvrage : \n");
			scanf("%s", auteur);
			
			L = creation_livre(NV_LIVRE_NB, titre, auteur);
			insertion_livre(t, L);
			
			break;
		
		case 3:
			printf("Suppression d'un ouvrage : \n\n");
			printf("Tapez le numero d'identification de l'ouvrage : \n");
			scanf("%d", &num);
			
			L = rec_livre_num(t, num);
			if(L != NULL){
				supression_livre(t,L);
				printf ("L'ouvrage a ete supprime\n");
			}else{
				printf("L'ouvrage n'ete pas dans la bibliotheque\n");
			}
			
			break;
			
		case 4:
			printf("Recherche d'un ouvrage par titre : \n\n");
			printf("Tapez le titre de l'ouvrage : \n");
			scanf("%s", titre);
			
			L = rec_livre_titre(t, titre);
			if(L != NULL){
				affichage_livre(L);
			}else{
				printf("Pas d'ouvrage avec le titre %s \n", titre);
			}
			
			break;
			
		case 5:
			printf("Recherche d'un ouvrage par numero d'identification : \n\n");
			printf("Tapez le numero d'identification de l'ouvrage : \n");
			scanf("%d", &num);
			
			L = rec_livre_num(t, num);
			if(L != NULL){
				affichage_livre(L);
			}else{
				printf("Pas d'ouvrage avec le numero d'identification %d \n", num);
			}

			break;
			
		case 6: 
			printf("Recherche des ouvrages d'un meme auteur : \n\n");
			printf("Tapez l'auteur de l'ouvrage : \n");
			scanf("%s", auteur);
			
			if (!rec_livres_auteur(t, auteur)){
				printf("Pas d'ouvrages de l'auteur %s\n", auteur);
			}
			
			break;
				
		case 7:
			printf("Recherche des ouvrages repetes : \n\n");
			
			if(!rec_livres_double(t)){
				printf("Pas d'ouvrages repetes\n");
			}

			break;

		}	
			
	}while(ch!=0);

	printf("Au revoir\n");
	supression_biblio(t);

	return 0;
}





