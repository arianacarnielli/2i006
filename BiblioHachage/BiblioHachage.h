#ifndef HACH_
#define HACH_

typedef struct livre{
	unsigned int clef;
	int num;
	char* titre;
	char* auteur;
	struct livre* suiv;
}s_livre;

typedef struct{
	int nE;
	int m;
	int ind_max;
	s_livre** T;
}tableHachage_t;


/* Fonctions basiques */

	/* Cree une bibliotheque vide, avec une table de hachage de taille m avec tous ses elements initiases a NULL */
	tableHachage_t* initTableHachage(int m);

	/* Calcule la clef associee a une chaine de caracteres donnee */
	unsigned int fonctionClef(char* nom);

	/* Calcule l'indice de la table de hachage a partir de la clef passee en argument */
	unsigned int fonctionHachage(int m, unsigned int clef);

	/* Afiche le livre passe en argument */
	void affichage_livre(s_livre* L);

	/* Afiche tous les livres presentes en une bibliotheque passe en argument */
	void affichage(tableHachage_t* t);
	
	/* Cree une nouvelle instance de livre */
	s_livre* creation_livre(int num, char* titre, char* auteur);
	
	/* Insertion d'un nouvel ouvrage. L'insertion se fait en tete de liste de la liste correspondante a la clef */
	void insertion_livre(tableHachage_t* t, s_livre* L);
	
	/* Suppression d'un ouvrage */
	void supression_livre(tableHachage_t* t, s_livre* L);
	
	/* Suppression de la bibliotheque */
	void supression_biblio(tableHachage_t* t);
	
	/*permet de lire n entrees du fichier passe en argument et de les stocker dans une bibliotheque */
	void lecture_n_entree(char* nomfic, int n, tableHachage_t* t);

/* Fonctions de Recherche */
	
	/* Recherche d'un ouvrage par son numero, retourne un pointeur sur le livre correspondant s'il existe, NULL sinon */
	s_livre* rec_livre_num(tableHachage_t* t, int nb);

	/* Recherche d'un ouvrage par son titre, retourne un pointeur sur la premier instance de livre correspondant s'il existe, NULL sinon */
	s_livre* rec_livre_titre(tableHachage_t* t, char* titre);

	/* Recherche tous les livres d'un meme auteur et les affiche a l'ecran. Retourne le nombre ded livres trouves */
	int rec_livres_auteur(tableHachage_t* t, char* auteur);

	/* Recherche des ouvrages au moins en double (meme auteur et titre). Affiche tous les ouvrages repetes a l'ecran. Retourne le nombre de livres trouves */
	int rec_livres_double(tableHachage_t* t);
	
/* ETC */

	/* Fonction d'affichage du menu de choix possibles de l'utilisateur*/
	void menu();

#endif
