#ifndef __ALGOGRA__
#define __ALGOGRA__

#include <stdlib.h>
#include <stdio.h>

#include "Graphe.h"
#include "algorithme_couleur.h"
#include "circuit.h"
#include "Solution.h"
#include "Grille.h"

/* Insere l'action donnee par le char a dans la Solution* S apres le Cell_char* c (ou au debut si c est NULL). Met a jour Tref[j] avec l'action ajoutee (si ce n'est pas un S). */
Cell_char* Ajout_action_apres_c(Solution* S, Cell_char* c, int j, char a, Cell_char** Tref);

/* Insere dans S apres le Cell_char* c les actions de deplacement pour aller de j a l, en mettant a jour le tableau Tref. */
Cell_char* pluscourtchemin_apres_c(Solution* S, Cell_char* c, int j, int l, Cell_char** Tref);

/* Ajoute dans S apres le Cell_char* c les actions correspondantes au circuit Cell_circuit* cc, en mettant a jour Tref et Jdroite. */
void Ajout_circuit_dans_solution(Cell_circuit* cc, Solution* S, Cell_char* c, Cell_char** Tref, int* Jdroite);

/* Implementation de l'algorithme de Daniel Graf. */
void algorithme_circuit_CasLigne1x1(Grille *G, Solution *S, int graine);

#endif