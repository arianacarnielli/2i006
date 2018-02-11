#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BiblioSimpleChaine.h"
#include "entree_sortie.h"

#define NV_LIVRE_NB -1

int main(int argc ,char** argv){

	int ch;
	char* nomfic;
	int nlignes;
	Biblio B, B2;
	
	int  num;
	char titre[100];
	char auteur[100];
	s_livre* L;

	initialise_biblio(&B);
	initialise_biblio(&B2);

	if(argc!=3){
		printf("Erreur format :	%s <NomFichierBiblio.txt> <NbLigneALire>\n", argv [0]);
		return 1;
	}
	
	nomfic = strdup(argv [1]);
	nlignes = atoi(argv [2]);
	
	printf("Lecture\n");
	lecture_n_entree(nomfic ,nlignes ,&B);
	
	
	do{
		menu();
		scanf("%d", &ch);
		
		switch(ch){
			
		case 1:
			printf("Affichage : \n");
			affichage (&B);
			
			break;
			
		case 2: 
			printf("Insertion d'un nouvel ouvrage : \n\n");
			printf("Tapez le titre de l'ouvrage : \n");
			scanf("%s", titre);
			printf("Tapez l'auteur de l'ouvrage : \n");
			scanf("%s", auteur);
			
			L = creation_livre(NV_LIVRE_NB, titre, auteur);
			insertion_livre(&B, L);
			
			break;
		
		case 3:
			printf("Suppression d'un ouvrage : \n\n");
			printf("Tapez le numero d'identification de l'ouvrage : \n");
			scanf("%d", &num);
			
			L = rec_livre_num(&B, num);
			if(L != NULL){
				supression_livre(&B,L);
				printf ("L'ouvrage a ete supprime\n");
			}else{
				printf("L'ouvrage n'ete pas dans la bibliotheque\n");
			}
			
			break;
			
		case 4:
			printf("Recherche d'un ouvrage par titre : \n\n");
			printf("Tapez le titre de l'ouvrage : \n");
			scanf("%s", titre);
			
			L = rec_livre_titre(&B, titre);
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
			
			L = rec_livre_num(&B, num);
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
			
			B2 = rec_livres_auteur(&B, auteur);
			if(B2.L != NULL){
				affichage (&B2);
			}else{
				printf("Pas d'ouvrages de l'auteur %s\n", auteur);
			}
			supression_biblio(&B2);
			
			break;
				
		case 7:
			printf("Recherche des ouvrages repetes : \n\n");
			B2 = rec_livres_double(&B);

			if(B2.L != NULL){
				affichage (&B2);
			}else{
				printf("Pas d'ouvrages repetes\n");
			}
			supression_biblio(&B2);

			break;

		}	
			
	}while(ch!=0);

	printf("Au revoir\n");
	supression_biblio(&B);

	return 0;
}





