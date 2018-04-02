# -*- coding: utf-8 -*-
from graphes_donnes import n_naif, temps_naif, n_circ, temps_circ, \
                           n_coul, temps_coul, n_AVL, temps_AVL
import matplotlib.pyplot as plt

plt.close(1)
plt.figure(1, figsize=(5, 5))
plt.plot(n_naif, temps_naif, 'b-', lw=2, label="Naive")
plt.plot(n_circ, temps_circ, 'r-', lw=2, label="Circulaire")
plt.plot(n_coul, temps_coul, 'k-', lw=2, label="Couleur")
plt.plot(n_AVL, temps_AVL, 'g-', lw=2, label="AVL")
plt.grid(True)
plt.legend(loc="lower right", fontsize=11.3)
plt.xlabel(r"$n$", fontsize="large")
plt.ylabel("Temps moyen d'exécution", fontsize="medium")
plt.ylim([0, 7])
plt.yticks(range(7))
plt.title("Temps d'exécution avec 10 couleurs")