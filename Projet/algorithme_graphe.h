#ifndef __ALGOGRA__
#define __ALGOGRA__

#include <stdlib.h>
#include <stdio.h>

#include "Graphe.h"
#include "algorithme_couleur.h"
#include "circuit.h"
#include "Solution.h"
#include "Grille.h"


Cell_char* Ajout_action_apres_c(Solution* S, Cell_char* c, int j, char a, Cell_char** Tref);

Cell_char* pluscourtchemin_apres_c(Solution* S, Cell_char* c, int j, int l, Cell_char** Tref);

void Ajout_circuit_dans_solution(Cell_circuit* cc, Solution* S, Cell_char* c, Cell_char** Tref, int* Jdroite);

void algorithme_circuit_CasLigne1x1(Grille *G, Solution *S, int graine);

#endif