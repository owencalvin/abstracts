# TD - Data Types (2)
## Traitement de fichier de grand taille en Python

Le but de l’exercice est d’écrire du code qui doit pouvoir fonctionner pour des fichiers de n’importe quelle taille !

Tâches :
- Télécharger le fichier my_huge_dataset.csv
- Sans bibliothèque externes, utilisant un **générateur** et l’opérateur ```yield```
    - Compter le nombre de lignes où ```meanfreq > 0.16``` (première colonne)
- Avec pandas:
    - Calculer la moyenne de la colonne ```meanfreq``` quand ```label = 'male'```
