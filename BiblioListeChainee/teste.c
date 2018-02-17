#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "BiblioSimpleChaine.h"
#include "entree_sortie.h"

#define NV_LIVRE_NB -1
#define TAILLE_BIBLIO 100000
#define FICHIER "GdeBiblio.txt"
#define REPEAT 10000

int main(){
	
	int nlignes;
	int ch;
	Biblio b;
	
	
	FILE* py;
	
	int cpt;
	time_t start;
	double duree;  
	
	printf("Tapez l'option souhaite :\n");
	scanf("%d", &ch);
	switch(ch){
			
		case 1:
			initialise_biblio(&b);
			nlignes = TAILLE_BIBLIO;
	
			lecture_n_entree(FICHIER, nlignes, &b);
			
			/* Recherche par le numero d'identification */
			
			/* initialization start */
			start = time(NULL);
			
			for(cpt = 0; cpt < REPEAT; cpt++){
				rec_livre_num(&b, TAILLE_BIBLIO); 
				/* On n'a pas de livre avec TAILLE_BIBLIO comme numero d'identification, on est dans le pire cas */
			}
			
			duree = difftime(time(NULL), start) / REPEAT;
			printf("temps moyen pour la recherche par numero dans le pire cas: %f\n", duree);
			
			/* Recherche par titre */
			
			/* initialization start */
			start = time(NULL);
			
			for(cpt = 0; cpt < REPEAT; cpt++){
				rec_livre_titre(&b, ""); 
				/* On n'a pas de livre avec "" comme titre, on est dans le pire cas */
			}
			
			duree = difftime(time(NULL), start) / REPEAT;
			printf("temps moyen pour la recherche par titre dans le pire cas: %f\n", duree);
			
			/* Recherche par le auteur */
			
			/* initialization start */
			start = time(NULL);
			
			for(cpt = 0; cpt < REPEAT; cpt++){
				rec_livres_auteur(&b, ""); 
				/* On n'a pas de livre avec "" comme auteur, on est dans le pire cas */
			}
			
			duree = difftime(time(NULL), start) / REPEAT;
			printf("temps moyen pour la recherche par auteur dans le pire cas: %f\n", duree);
			
			supression_biblio(&b);				
			break;

			
		case 3:
			py = fopen("Question3_3_liste.py", "w");
			if(py==NULL){
				fprintf(stderr ,"Erreur lors de l'overture du fichier");
				return 1;
			}
			fprintf(py, "n_taille = []\n");
			fprintf(py, "temps = []\n");
			
			for(nlignes = 1000; nlignes <= 50000; nlignes += 1000){
				printf("nlignes = %d\n", nlignes);
				
				fprintf(py, "n_taille.append(%d)\n", nlignes);
				
				initialise_biblio(&b);
				lecture_n_entree(FICHIER, nlignes, &b);
			
				/* Recherche de doublons */
				
				/* initialization start */
				start = time(NULL);
				
				for(cpt = 0; cpt < 10; cpt++){
					rec_livres_double(&b); 
				}
				
				duree = difftime(time(NULL), start) / 10;
				fprintf(py, "temps.append(%f)\n", duree);
				
				fflush(py);
				
				supression_biblio(&b);
			}
			fclose(py);
			break;			
			
	}	
	
	return 0;
}