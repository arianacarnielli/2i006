#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AVL.h" 

int main(){

	AVL* test = creer_noeud(15);
	affiche_infixe(test);
	printf("\n");
	int i;

	for(i = 0; i < 10; i++){
		test = inserer_AVL(test, i);

	}

	printf("Avant la suppression: \n\n");
	affiche_infixe(test);

	/*printf("\n\nApres la suppression de 7 \n\n");
	test = supprimer_noeud(test, 7);
	affiche_infixe(test);
*/
	
	printf("\n\nApres la suppression de 0 \n\n");
	test = supprimer_noeud(test, 0);
	affiche_infixe(test);

	printf("\n\nApres la suppression de 2 \n\n");
	test = supprimer_noeud(test, 2);
	affiche_infixe(test);

	printf("\n\nApres la suppression de 1 \n\n");
	test = supprimer_noeud(test, 1);
	affiche_infixe(test);

	/*printf("\n\nApres la suppression de 6 \n\n");
	test = supprimer_noeud(test, 6);
	affiche_infixe(test);*/



	return 0;


}