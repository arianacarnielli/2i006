#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "AVL.h"  

int main(){

	srand(time(NULL));
	AVL* test = creer_noeud(15);
	int i;

	for(i = 0; i < 40; i++){
		test = inserer_AVL(test, rand() % 30);
	}

	printf("Avant la suppression: \n\n");
	affiche_infixe(test);

	i = est_AVL(test);
	
	printf("%d\n", i);
	
	int temp;
	
	printf("Tapez le numero a supprimer : \n");
	scanf(" %d", &temp);
	
	printf("\n\nApres la suppression de %d \n\n", temp);
	test = supprimer_noeud(test, temp);
	affiche_infixe(test);
	
	printf("Tapez le numero a chercher le plus proche : \n");
	scanf(" %d", &temp);
	
	i = recherche_plus_proche(test, temp);
	
	printf("Le numero le plus proche de %d est %d.\n", temp, i);
	
	/*printf("\n\nApres la suppression de 7 \n\n");
	test = supprimer_noeud(test, 7);
	affiche_infixe(test);
	*/
	
	/*printf("\n\nApres la suppression de 0 \n\n");
	test = supprimer_noeud(test, 0);
	affiche_infixe(test);

	printf("\n\nApres la suppression de 2 \n\n");
	test = supprimer_noeud(test, 2);
	affiche_infixe(test);

	printf("\n\nApres la suppression de 1 \n\n");
	test = supprimer_noeud(test, 1);
	affiche_infixe(test);*/

	/*printf("\n\nApres la suppression de 6 \n\n");
	test = supprimer_noeud(test, 6);
	affiche_infixe(test);*/

	return 0;


}