# -*- coding: utf-8 -*-
"""
Created on Sat Feb 17 03:21:04 2018

@author: arian
"""

import matplotlib.pyplot as plt
from Question3_3_liste import n_taille, temps

plt.close(0)
plt.figure(0)
plt.plot(n_taille, temps)
plt.grid(True)
plt.title("Temps de la recherche de doublons : liste chainée", fontsize="medium")
plt.xlabel("Nombre d'éléments de la bibliothèque")
plt.ylabel("Temps [s]")


plt.close(1)
plt.figure(1)
plt.plot(n_taille, [1e6*x/(y**2) for x, y in zip(temps, n_taille)])
plt.grid(True)
plt.title("Rapport entre le temps de la recherche de doublons et le carré du nombre d'éléments", fontsize="medium")
plt.xlabel("Nombre d'éléments de la bibliothèque")
plt.ylabel("Temps [s] / nombre d'éléments au carré × 1000000")
plt.ylim([-0.1, 0.1])
plt.yticks([-0.1, -0.08, -0.06, -0.04, -0.02, 0, 0.02, 0.04, 0.06, 0.08, 0.1])