#ifndef BIBLIO_
#define BIBLIO_

typedef struct livre{
	int num;
	char* titre;
	char* auteur;
	struct livre* suiv;
}s_livre;

typedef struct{
	s_livre* L;
	int nbliv;
}Biblio;

/* Fonctions basiques */

	/* Cree une bibliotheque vide */
	void initialise_biblio(Biblio* b);
	
	/* Afiche le livre passe en argument */
	void affichage_livre(s_livre* L);
	
	/* Afiche tous les livres presentes en une bibliotheque passe en argument */
	void affichage(Biblio* b);

	/* Cree une nouvelle instance de livre */
	s_livre* creation_livre(int num, char* titre, char* auteur);
	
	/* Insertion d'un nouvel ouvrage. L'insertion se fait en tete de liste */
	void insertion_livre(Biblio* b, s_livre* L);

	/* Suppression d'un ouvrage */
	void supression_livre(Biblio* b, s_livre* L);
	
	/* Suppression de tous les ouvrages d'une bibliotheque */
	void supression_biblio(Biblio* b);
	
	/* Clone une instance de livre, avec le pointeur suiv = NULL */
	//s_livre* clone_livre(s_livre* L);
	
	/*permet de lire n entrees du fichier passe en argument et de les stocker dans une bibliotheque */
	void lecture_n_entree(char* nomfic, int n, Biblio* b);

/* Fonctions de Recherche */
	
	/* Recherche d'un ouvrage par son numero, retourne un pointeur sur le livre correspondant s'il existe, NULL sinon */
	s_livre* rec_livre_num(Biblio* b, int nb);

	/* Recherche d'un ouvrage par son titre, retourne un pointeur sur la premier instance de livre correspondant s'il existe, NULL sinon */
	s_livre* rec_livre_titre(Biblio* b, char* titre);

	/* Recherche tous les livres d'un meme auteur et les affiche a l'ecran. Retourne le nombre ded livres trouves */
	int rec_livres_auteur(Biblio* b, char* auteur);
	
	/* Recherche des ouvrages au moins en double (meme auteur et titre). Affiche tous les ouvrages repetes a l'ecran. Retourne le nombre de livres trouves */
	int rec_livres_double(Biblio* b);
	
/* ETC */

	/* Fonction d'affichage du menu de choix possibles de l'utilisateur*/
	void menu();

#endif
