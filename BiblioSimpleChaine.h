#ifndef BIBLIO_
#define BIBLIO_

typedef struct livre {
	int num ;
	char* titre;
	char* auteur;
	struct livre* suiv;
}s_livre;

typedef struct{
	s_livre* L;
	int nbliv;
}Biblio;

	/* Cree une bibliotheque vide */
	void initialise_biblio (Biblio* b);

	/* Afiche tous les livres presentes en une bibliotheque passé en argument */
	void affichage(Biblio* b);

	/* Recherche d'un ouvrage par son numero, retourne un pointeur sur le livre correspondant s'il existe, NULL sinon */
	s_livre* rec_livre_num(Biblio* b, int nb);

	/* Recherche d'un ouvrage par son titre, retourne un pointeur sur la premier instance de livre correspondant s'il existe, NULL sinon */
	s_livre* rec_livre_titre(Biblio* b, char* titre);

	/* Recherche de tous les livres d'un meme auteur, retourne une liste des livres de l'auteur passe en paramètre ou NULL si aucun livre est trouve */
	Biblio* rec_livres_auteur(Biblio* b, char* auteur);

	/* Insertion d'un nouvel ouvrage */
	void insertion_livre(Biblio* b, s_livre* L);

	/* Suppression d'un ouvrage */
	void supression_livre(Biblio* b, s_livre* L);

	/* Recherche des ouvrages au moins en double (meme auteur et titre). Renvoie une liste comprenant les ouvrages qui sont au moins en double ou NULL si aucune ouvrage est en double */
	Biblio* rec_livres_double(Biblio* b);
	
	/* Fonction d'affichage du menu de choix possibles de l'utilisateur*/
	void menu();

#endif
