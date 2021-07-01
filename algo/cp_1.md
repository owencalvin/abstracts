# Exercice 1: Types abstraits de données

## Qu'est-ce qu'un type abstrait de données (TAD) ?
Une description "théorique" (abstraite) d'un type de donnée et des opérations, qui est implémenté dans un langage de programmation (concret).

## Quelles sont les informations contenues dans une spécification algébrique ?
- La sorte
- La description
- La signature
- Les axiomes

## Quel est l'intérêt de cet définition abstraite ?
Séparer le concret de l'abstrait permet d'avoir une solution applicable et implémentable dans n'importe quel langage de programmation

## Comment appelle-t-on son implémentation
SCD, Structure Concrète de Données


# Exercice 2: Algorithme et complexité

## Qu'est-ce qu'un algorithme ?
- Un algorithme défini un traitement sur un nombre fini de données en un temps fini
- Il est indépendant de son implémentation
- On l'implémente dans un langage de programmation

## Quels sont les avantage d'évaluer la complexité des algorithmes (au lieu de mesurer les temps d'exécution ou l'espace pris en mémoire) ?
Ca nous permet de comparer des algorithme entre eux afin de connaître le meilleur.  
On peut déterminer si l'opération est faisable dans un temps raisonnable pour un nombre *n* de données.

## Donner les 6 fonctions de référence pour les classes de complexité vues en cours, en les classant par ordre d'efficacité
1. O(n!)
2. O(n^2)
3. O(n*log(n))
4. O(n)
5. O(log(n))
6. O(1)


# Exercice 3: Comparaison de complexité

## Comparer la complexité de ces 3 algorithmes et les classer du plus efficace au moins efficaces
- **A**: `somme = 0; pour i = 1 -> n { somme += i }`
- **B**: `somme = 0; pour i = 1 -> n { pour j = 1 -> i { somme += 1} }`
- **C**: `somme = n * (n + 1) / 2`

---

### Leur complexité
- **A**: O(n)
- **B**: O(n^2)
- **C**: O(1)

### Classement
1. **C**: O(1)
2. **A**: O(n)
3. **B**: O(n^2)

# Exercice 4: Algorithme de tri

## Quel est la différence entre les tris internes et externes ?
Un tri interne se fait dans la mémoire vive (RAM)  
Un tri externe se fait par l'intermédiaire de fichiers

## Qu'est-ce qu'un tri en place ?
Un tri qui n'alloue pas une structure de données supplémentaire afin d'en trier une

## Qu'est-ce que la stabilité pour un algorithme de tri ?
Soit deux clés **identiques** *i* et *j*, se trouvent dans notre SCD à l'indice *k* et *m* avec *k < m*.  
L'algorithme est stable si après le tri *i* et *j* se trouve respectivement à l'indice *k* et *k + 1*

En gros que l'ordre initiale entre deux clés **identiques** soit le même après le tri

## En quoi la stabilité est importante
Si les données d'un tableau sont déjà triées par rapport à une autre clé différente, en utilisant alors un algorithme de tri non stable on va perdre le tri précédemment fait
