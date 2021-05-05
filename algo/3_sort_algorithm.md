# Les algorithme de tris
Il y'a deux classes d'algorithme de tri
- Les algorithmes de **tri interne**
- Les algorithmes de **tri externe**

## Le tri interne (internal sort)
Il s'effectue **dans la RAM**, souvent dans un tableau contenant les informations à trier

## Le tri externe (external sort)
Il s'effectue **dans la ROM** par l'intermédiaire de fichiers

## Algorithme de tri "en place"
Un algorithme de tri "**en place**" va trier un tableau en le transformant directement, sans en allouer un nouveau qui serait vide et qu'on remplirait avec les données triées

# Tableau
Les indices vont de **Gauche (G)** à **Droite (D)**

Chaque élément est appelé **valeur**

La partie de l'information utilisé pour le tri est la **clé**

> En C, Gauche vaut 0 et Droite vaut la taille du tableau moins 1

# Echanger
Pour trier les informations on doit savoir échanger le contenu de deux cases avec leurs indices `i` et `j`

![](images/swap.png)

# Bubblesort (tri bulle)

On compare les clés de deux élément consécutifs à partir du début jusqu'à la fin du tableau

> Ou depuis la fin jusqu'au début du du tableau

## Structogramme

`Parcours(T: Tableau, Haut: int, Bas: int)`  
![](images/bubble_sort2.png)  
Ceci est uniquement un parcours qui compare deux clés, il faut faire ceci pour tout le tableau

`BubbleSort(T: Tableau, Haut: int, Bas: int)`  
![](images/bubble_sort3.png)  
Il fait le `Parcours` de 1 à N - 1 fois  
(au final l'opération est faite N - 2 fois)

> j &larr; 1 car on compare les éléments i et i - 1

## Complexité
Au pire des cas la complexité est `O(n^2)`

## Exemple
Ce schéma montre l'évolution du tableau, à gauche le tableau n'est pas trié

On voir que l'élément avec une clé la plus petite (1)remonte dans le tableau jusqu'à atteindre la première place

`Parcours(T, 0, 7)`  
![](images/bubble_sort1.png)
![](images/bubble_sort6.png)

> Haut = 0, Bas = 7

## Améliorations

### Bubble Sort Itératif
Après j parcours, nous avons définitivement placé les j plus petites clés.  
On a donc plus besoin de se soucier de ces éléments, on peut alors commencer notre parcours à `Haut + j` (`0 + j`)

---

`BubbleSortIteratif(T: tableau, Haut: int, Bas: int)`
![](images/bubble_sort4.png)

Le nombre d'échange devient:  
`(N - 1) + (N - 2) + ... + 2 + 1 = N(N - 1) / 2`  
Donc la complexité est quadratique `O(n^2)`

### Bubble Sort Drapeau
Un tableau peut être trié avant la fin de la boucle (car plus d'un élément peut remonter lors d'un seul parcours), il est alors judicieux de stopper la boucle si le tableau est entièrement trié

On utilise la notion de "drapeau" qui permet de déterminer si le tableau est déjà trié

Le "drapeau" est baissé au début du parcours du tableau et on le lève lors d'un échange

**Si aucun échange à été fait lors d'un parcours cela signifie qu'on a terminé le tri &rarr; Drapeau à Faux**

On test alors l'état du drapeau avant de reparcourir le tableau

---

`BubbleSortDrapeau(T: tableau, Haut: int, Bas: int)`
![](images/bubble_sort5.png)

Le nombre d'échange reste `N(N - 1) / 2` mais la complexité à augmenté (donc la duré d'exécution aussi)

Cette méthode est adapté pour les tableaux presque complètement triés

## Stabilité
**On sait qu'un algorithme de tri est stable s'il n'échange pas la position de 2 valeurs égales**

---

Soient deux éléments du tableau, ayant la même clé, et d’indices i et j avec i < j

Tout élément de clé strictement **inférieure** se placera **au-dessus** d’eux et tout élément de clé strictement **supérieure** se placera **au-dessous** d’eux

Ils se trouveront donc dans les cases d’indice **k** et **k + 1**

**Lors de la comparaison des clés de ces deux éléments, ils ne sont pas échangés**

Donc leur ordre de départ est respecté car **i** se trouve à l'indice **k** et **j** à **k + 1**

La méthode est alors stable

## Analyse
Le nombre de comparaisons dans les méthodes de tri par échange d’éléments consécutifs est :  
`C = n(n - 1) / 2`

Le nombre minimum de déplacements  
`Dmin = 0`

Le nombre moyen de déplacements  
`Dmoy = 3n(n - 1) / 4`

Le nombre maximum de déplacements  
`Dmax = 3n(n - 1) / 2` 

> Un échange continent 3 déplacement (3 affectations), ce qui explique le facteur 3 dans le nombre d'opération effectuées

## Visualisation du Bubble Sort
![](images/bubble_sort7.png)

> [Source](https://corte.si/posts/code/visualisingsorting/)

# Tri par extraction (ou tri par séléction)

## Première étape: extraction
La première étape consiste à extraire l’élément ayant la plus petite clé et à l’échanger avec l’élément de **Gauche** du tableau

Pour trouver la plus petite clé le tableau est parcouru de **Gauche** à **Droite**, on garde en mémoire l'indice de la plus petite clé rencontrée

![](images/extraction_sort1.png)

### Structogramme

`PlacerLeMinimumÀGauche(T: tableau, Gauche: int, Droite: int)`
![](images/extraction_sort2.png)

## Deuxième étape: entièreté du tableau
On applique ceci pour tout le tableau, pour cela il faut que qu'on opère uniquement sur la partie du tableau qui n'est pas encore trié:  

1. De **Gauche + 0** à **Droite**
2. De **Gauche + 1** à **Droite**
3. De **Gauche + 2** à **Droite**
4. ...
5. De **Droite - 1** à **Droite**

**Gauche + C** est la partie déjà trié du tableau

> Lorsque les N − 1 éléments ayant les clés les plus petites sont à leur place, le dernier élément qui a la plus grande clé est aussi à sa place

![](images/extraction_sort4.png)

### Structogramme

![](images/extraction_sort3.png)


## Complexité
`PlacerLeMinimumAGauche` est executé `N - 1` fois pour un tableau de N éléments, à chaque execution l'algorithme effectue `Droite - Gauche + 1` comparaisons, le nombre de comparaison est donc
  
`C = ((N - 1) + 1) + ((N - 2) + 1) + ... + (3 + 1) + (2 + 1) + (1 + 1)`  
`C = N(N + 1) / 2 - 1`

> 1. `Droite = N` `Gauche = 1`  
> 2. `Droite = N` `Gauche = 2`  
> 3. `Droite = N` `Gauche = 3`  
> 4. ...
> 5. `Droite = N` `Gauche = N - 3`
> 5. `Droite = N` `Gauche = N - 2`
> 5. `Droite = N` `Gauche = N - 1`

Si les clés sont triées, le nombre de déplacement est **au minimum**  
`Dmin = 0`

Dans le pire des cas (chaque itération provoque un échange)  
`Dmax = 3(N - 1)`

## Stabilité
Voici un tableau avec deux clés identiques:

![](images/extraction_sort5.png)

En extrayant le premier minimum ça donne:

![](images/extraction_sort6.png)


**On voit que l'algorithme n'est pas stable**, car B (15) peut venir après A (15) 
