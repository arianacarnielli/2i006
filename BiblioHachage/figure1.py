# -*- coding: utf-8 -*-
"""
Created on Sat Feb 17 01:51:36 2018

@author: arian
"""

import matplotlib.pyplot as plt
from Question3_2 import m, temps_num, temps_titre, temps_auteur

plt.close(0)
plt.figure(0)
plt.plot(m, [1e3*x for x in temps_num], label="Numéro")
plt.plot(m, [1e3*x for x in temps_titre], label="Titre")
plt.plot(m, [1e3*x for x in temps_auteur], label="Auteur")
plt.xlim([0, 100000])
plt.xticks([5000, 20000, 40000, 60000, 80000, 100000])
plt.grid(True)
plt.title("Temps de calcul des recherches en fonction de la taille de la table de hachage", fontsize="medium")
plt.xlabel("Taille de la table de hachage")
plt.ylabel("Temps [ms]")
plt.legend(loc="lower left", bbox_to_anchor = (0.01, 0.1), framealpha = 1)