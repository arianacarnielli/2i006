# -*- coding: utf-8 -*-
"""
Created on Sat Feb 17 02:36:20 2018

@author: arian
"""

import matplotlib.pyplot as plt
from Question3_3_hachage import n_taille, temps

plt.close(0)
plt.figure(0)
x30 = n_taille[29]
x50 = n_taille[49]
y30 = 1e3*temps[29]
y50 = 1e3*temps[49]
a = (y50 - y30)/(x50 - x30)
plt.plot([x30 - y30/a, 50500], [0, y30 + a*(50500 - x30)], 'r--')
plt.plot(n_taille, [1e3*x for x in temps], 'b-')
plt.grid(True)
plt.title("Temps de la recherche de doublons : table de hachage", fontsize="medium")
plt.xlabel("Nombre d'éléments de la bibliothèque")
plt.ylabel("Temps [ms]")


plt.close(1)
plt.figure(1)
plt.plot(n_taille, [1e6*x/y for x, y in zip(temps, n_taille)])
plt.grid(True)
plt.title("Rapport entre le temps de la recherche de doublons et le nombre d'éléments", fontsize="medium")
plt.xlabel("Nombre d'éléments de la bibliothèque")
plt.ylabel("Temps [ms] / nombre d'éléments × 1000")
plt.ylim([-0.5, 0.5])