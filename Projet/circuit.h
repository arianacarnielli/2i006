#ifndef __CIRCUIT__
#define __CIRCUIT__

#include "Graphe.h"
#include "algorithme_couleur.h"

typedef struct cell_circuit{
	LDC L;
	int jmin, jmax;
	struct cell_circuit *suiv;
} Cell_circuit;

typedef struct{
	int nb_circuit;
	Cell_circuit *premier;
	Cell_circuit *dernier;
} Lcircuit;

/* Affiche tous les circuits d'un graphe. La fonction marque comme visite (=0) tous les sommets non-noires. */
void Graphe_Affiche_Circuit(Graphe *H);

/* Affiche le circuit commencant par le sommet passe en argument. La fonction marque comme visite (=0) tous les sommets non-noires. Elle ne fait rien si le sommet passe en argument a ete deja visite. */
void Affiche_Circuit(Sommet *S);

/* Sauvegarde dans la LDC passe en argument le circuit commencant par le sommet passe en argument. La fonction marque comme visite (=0) tous les sommets non-noires. Elle ne fait rien si le sommet passe en argument a ete deja visite. Le sommet de depart est mis deux fois : au debut et a la fin de la LDC. */ 
void Rech_Circuit(Sommet *S, LDC* L);

/* Sauvegarde tous les circuits d'un graphe dans le Lcircuit passe en argument. La fonction marque comme visite (=0) tous les sommets non-noires. La liste Lcircuit doit etre initialise avant. */
void Graphe_Rech_Circuit(Graphe *H, Lcircuit* l_c);

/* Alloue et retourne un Cell_circuit. La LDC est deja initialisee. */
Cell_circuit* creer_Cell_circuit();

/* Initialise la liste Lcircuit comme vide. */
void LcircuitInitialise(Lcircuit* l_c);

/* Teste si la liste Lcircuit passe en argument est vide. */
int LcircuitVide(Lcircuit* l_c);

/* Insere une cellule Cell_circuit donne a la fin de liste Lcircuit passe en argument. */
void LcircuitInsererEnFin(Lcircuit* l_c, Cell_circuit* cc);

/* Affiche tous les circuits stockes dans la liste Lcircuit passe en argument. Pour la debuggage. */
void Affiche_Lcircuit(Lcircuit* l_c);

/* Remet tous les sommets non-noire au etat non visité. Pour la debuggage. */
void reset_visit(Graphe* H);

/* Calcule et met a jour les jmin et jmax de tous les Cell_circuit dans l_c. */
void CalculJminJmax(Lcircuit *l_c);

#endif