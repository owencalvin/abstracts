# Qu'est-ce qu'un algorithme
- Décrit un **traitement** sur un nombre fini de **données**

- Est une composition fini d'étapes qui sont eux-même formée d'un nombre finis d'opérations dont chacune est **définie** et **effective**

- Doit toujours pouvoir se terminer après un nombre **fini** d'opérations et fournir un **résultat**

- Executé avec les **même données** doit toujours donner le **même résultat**

- Est **indépendant** d'un langage de programmation
  
- Est **implémenté** dans un langage de programmation

## Opération définie
Une opération doit être définit de façon rigoureuse et non ambiguës

## Opération effective
Pouvant être fait dans un temps fini (réalisable par une machine)

Une division avec un nombre **fini** de décimal est une **opération effective**

Une division avec un nombre **infini** de décimales n'est **pas une opération effective**


# Complexité d'un algorithme
Le but est de déterminer:
- **Le temps d'éxecution**
- **La place mémoire**

Afin de comparer différent algorithme qui résolvent le même problème entre eux

## Quelle mesure utiliser
On peut exprimer la complexité en **temps** ou **nombre de cycles machine**

### Temps
Nombre d'opération effectuées par la programme et le temps nécessaire pour chaque opérations

### Nombre de cycles machine
- Le nombre d'instructions et le nombre de données du programme  
- Le nombre de "mots" nécessaires pour stocker chacune des instructions
- Le nombre de "mots" mémoire pour la manipulation des données

> 1 "mot" = 2 octets = 16 bits

## Composantes influent sur la mesure de la complexité
- L'algorithme
- Le programme
- L'ordinateur
- Les données

Ce qui donnes des énoncé comme:  

**L'algorithme A** implémenté par le **programme P** sur **l'ordinateur O** et executé sur les **données D** utilise **_k secondes_** et **_j bits de mémoire_**

## But de la complexité
Cependant on voudrait connaître la complexité d'un algorithme indépendamment de ces composantes

Ce qui donnerait une énoncé comme:

Sur **toutes machines** pour **n'importe quel le langage de programmation**, **l'algorithme A1** est meilleur que **l'algorithme A2** pour les **données de "grande taille"**

# Mesure de la complexité en temps
Une solution est constituée d'opérations fondamentales et le temps d'exécution d'un algorithme est donc toujours proportionnel au nombre de ces opérations

Si on a plusieurs opérations fondamentales, on les comptent séparément et on leur affecte éventuellement un poids qui tient compte des temps d'exécution différents

Ces opérations fondamentales peuvent êtres:

- Pour le recherche d'un élément dans une liste en RAM  
  **Le nombre de comparaisons entre cet élément et les éléments de la liste**

- Pour la recherche d'un élément sur un disque  
  **Le nombre d'accès à la mémoire ROM**

- Pour multiplier deux matrices  
  **Le nombre de multiplications / additions**

- Pour trier une liste d'éléments  
  1. **Le nombre de comparaisons entre deux éléments**
  2. **Le nombre de déplacement d'éléments**

> Souvent un algorithme plus rapide utilise plus de place  
> 
> Il faut éviter d'utiliser un algorithme utilisant trop de ROM, car ceci est beaucoup plus lent


# Comparaison de deux algorithmes
En général, la complexité d'un algorithme est **fonction de la taille des données**

On détermine alors la rapidité de croissance de cette fonction lorsque la taille des données croît

## Exemple 1
Pour 3 algorithmes avec faisant `A1(n)`, `A2(n)` et `A3(n)` opérations

`A1(n) = n + C`  
`A2(n) = 2n`  
`A3(n) = n^2`

On sait que `A1` est mieux que `A2` qui est mieux que `A3`

> `A2` est mieux que `A3` dès que `n >= 2`

## Exemple 2
Pour 2 algorithmes avec faisant `A1(n)` et `A2(n)` opérations

`A1(n) = 3(n^2)`  
`A2(n) = 25n`  

On sait que `A2` est mieux que `A1` dès que `n > 8`

## Exemple 3
Pour 2 algorithmes avec faisant `A1(n)` et `A2(n)` opérations

`A1(n) = a(n^2)`  
`A2(n) = bn`  

On sait que `A2` est mieux que `A1`  
Car `f(n) = n^2` croît plus vite que `g(n) = n`

On dit que l'**ordre de grandeur asymptotique** de `f(n)` est strictement plus grand que celui de `g(n)`

> On dit aussi que "`f` domine `g` quand `n` temps vers l'infini"

## Ordres de grandeurs asymptotiques

![](./images/complexity.png)

## Tableaux
Voici un tableau montrant les différentes informations sur les fonctions de complexité

### Temps d'execution
Temps d'éxecution de ces algorithmes pour différente taille de données n   

![](./images/execution_time.png)

> Sur un ordinateur pouvant effectuer 10^6 opérations par seconde

### Taille maximale des données
La taille maximale des données que l'on peut traiter par chacun des algorithmes pour un certain temps

![](./images/data_size.png)

### Evolution de la taille des données et du temps d'éxecution
Montre comment la taille des données et le temps d'éxecution varient en fonction de l'un l'autre

![](./images/size_time.png)

### Conclusion

#### Algorithme en temps polynomial
Les algorithme en temps polynomial (`n^k, k > 0`) sont vraiment utilisable que pour `k < 2`  
Lorsque `2 <= k <= 3`, on peut régler des problème de taille moyenne  
Lorsque `k > 3`, on peut régler des petits problèmes


#### Algorithme en temps exponentiel
Les algorithme en temps exponentiel `2^n` sont pas vraiment utilisable, que pour les problèmes de petites tailles

# Quelques algorithmes avec leur complexité

| Notation grand O | Nom | "Rapidité" | Exemple |
| ---------------- | --- | ---------- | ----------- |
| `O(1)` | Constant | Rapide | Nombre pair ou impair |
| `O(log n)` | Logarithmique | Rapide | Trouver un élément dans un tableau trié avec du "Binary search" |
| `O(n)` | Linéaire | Rapide | Trouver le plus grand élément dans un tableau (non trié) |
| `O(n log n)` | Quasi-linéaire (Linearithmic) | Rapide | Trier un tableau avec "Merge sort" |
| `O(n^2)` | Quadratique | Moyenne | Trier un tableau avec "Bubble sort" |
| `O(n^3)` | Cubique | Moyenne | Résolution de système à 3 inconnues |
| `O(2^n)` | Exponentielle | Lente | Trouver tous les sous-ensembles |
| `O(n!)` | Factorielle | Lente | Trouver toutes les permutations d'un ensemble |

##  Nombre pair ou impair
`O(1)`  
Complexité constante
```cpp
bool isEven(n)
{
  return n % 2 == 0; // Opération fondamentale
}
```


> [Source](https://adrianmejia.com/most-popular-algorithms-time-complexity-every-programmer-should-know-free-online-tutorial-course/)