#ifndef BIBLIO_
#define BIBLIO_
typedef struct livre {
	int num ;
	char *titre;
	char *auteur;
	struct livre *suiv;
}s_livre;

typedef struct{
	s_livre *L;
	int nbliv;
}Biblio;

	void initialise_biblio (Biblio *b);
	void menu();
	void affichage(Biblio * b);
	

#endif
