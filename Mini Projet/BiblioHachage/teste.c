#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "BiblioHachage.h"
#include "entree_sortie.h"

#define NV_LIVRE_NB -1
#define TAILLE_BIBLIO 100000
#define FICHIER "GdeBiblio.txt"
#define REPEAT 10000

int main(){

	
	int nlignes;
	int ch;
	tableHachage_t* t;
	
	int cpt, m;
	time_t start;
	double duree;
	
	FILE* py;
	
	printf("Tapez l'option souhaite :\n");
	scanf("%d", &ch);
	switch(ch){
			
		case 1:
			nlignes = TAILLE_BIBLIO;
			t = initTableHachage(nlignes/2);
	
			lecture_n_entree(FICHIER, nlignes, t);
		
			/* Recherche par le numero d'identification */
			
			/* initialization start */
			start = time(NULL);
			
			for(cpt = 0; cpt < REPEAT; cpt++){
				rec_livre_num(t, TAILLE_BIBLIO); 
				/* On n'a pas de livre avec TAILLE_BIBLIO comme numero d'identification, on est dans le pire cas */
			}
			
			duree = difftime(time(NULL), start) / REPEAT;
			printf("temps moyen pour la recherche par numero dans le pire cas: %f\n", duree);
			
			/* Recherche par titre */
			
			/* initialization start */
			start = time(NULL);
			
			for(cpt = 0; cpt < REPEAT; cpt++){
				rec_livre_titre(t, ""); 
				/* On n'a pas de livre avec "" comme titre, on est dans le pire cas */
			}
			
			duree = difftime(time(NULL), start) / REPEAT;
			printf("temps moyen pour la recherche par titre dans le pire cas: %f\n", duree);
			
			/* Recherche par le auteur */
			
			/* initialization start */
			start = time(NULL);
			
			for(cpt = 0; cpt < REPEAT * 1000; cpt++){
				rec_livres_auteur(t, ""); 
				/* On n'a pas de livre avec "" comme auteur, on est dans le pire cas */
			}
			
			duree = difftime(time(NULL), start) / (REPEAT * 1000);
			printf("temps moyen pour la recherche par auteur dans le pire cas: %f\n", duree);
			
			supression_biblio(t);
			
			break;
			
		case 2:
			nlignes = TAILLE_BIBLIO;
			py = fopen("Question3_2.py", "w");
			if(py==NULL){
				fprintf(stderr ,"Erreur lors de l'overture du fichier");
				return 1;
			}
			
			fprintf(py, "m = []\n");
			fprintf(py, "temps_num = []\n");
			fprintf(py, "temps_titre = []\n");
			fprintf(py, "temps_auteur = []\n\n");
			
			for (m = 5000; m <= TAILLE_BIBLIO; m += 5000){
				printf("m = %d\n", m);
				
				fprintf(py, "m.append(%d)\n", m);
				
				t = initTableHachage(m);
		
				lecture_n_entree(FICHIER, nlignes, t);
			
				/* Recherche par le numero d'identification */
				
				/* initialization start */
				start = time(NULL);
				
				for(cpt = 0; cpt < REPEAT/20; cpt++){
					rec_livre_num(t, TAILLE_BIBLIO); 
					/* On n'a pas de livre avec TAILLE_BIBLIO comme numero d'identification, on est dans le pire cas */
				}
				
				duree = difftime(time(NULL), start) / (REPEAT/20);
				fprintf(py, "temps_num.append(%f)\n", duree);
				
				/* Recherche par titre */
				
				/* initialization start */
				start = time(NULL);
				
				for(cpt = 0; cpt < REPEAT/20; cpt++){
					rec_livre_titre(t, ""); 
					/* On n'a pas de livre avec "" comme titre, on est dans le pire cas */
				}
				
				duree = difftime(time(NULL), start) / (REPEAT/20);
				fprintf(py, "temps_titre.append(%f)\n", duree);
				
				/* Recherche par le auteur */
				
				/* initialization start */
				start = time(NULL);
				
				for(cpt = 0; cpt < REPEAT/20; cpt++){
					rec_livres_auteur(t, ""); 
					/* On n'a pas de livre avec "" comme auteur, on est dans le pire cas */
				}
				
				duree = difftime(time(NULL), start) / (REPEAT/20);
				fprintf(py, "temps_auteur.append(%f)\n", duree);
				
				fflush(py);
				
				supression_biblio(t);
			}
			fclose(py);
			break;
		
		case 3:
			py = fopen("Question3_3_hachage.py", "w");
			if(py==NULL){
				fprintf(stderr ,"Erreur lors de l'overture du fichier");
				return 1;
			}
			fprintf(py, "n_taille = []\n");
			fprintf(py, "temps = []\n");
			
			for(nlignes = 1000; nlignes <= 50000; nlignes += 1000){
				printf("nlignes = %d\n", nlignes);
				
				fprintf(py, "n_taille.append(%d)\n", nlignes);
				
				t = initTableHachage(nlignes/2);
		
				lecture_n_entree(FICHIER, nlignes, t);
			
				/* Recherche de doublons */
				
				/* initialization start */
				start = time(NULL);
				
				for(cpt = 0; cpt < REPEAT; cpt++){
					rec_livres_double(t); 
				}
				
				duree = difftime(time(NULL), start) / (REPEAT);
				fprintf(py, "temps.append(%f)\n", duree);
				
				fflush(py);
				
				supression_biblio(t);
			}
			fclose(py);
			break;			
	}	
	
		
	
	return 0;
}