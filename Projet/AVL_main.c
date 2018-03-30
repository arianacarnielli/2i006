#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "AVL.h" 

int main(){

	srand(time(NULL));

	AVL* test = creer_noeud(15);
	int i;

	for(i = 0; i < 10; i++){
		test = inserer_AVL(test, i);
	}

	affiche_infixe(test);

	return 0;


}