# La récursivité
En programmation, ce concept peut s’appliquer aux structures de données et aux algorithmes:

- Structures de données récursives : listes, arbres et graphes.

- Algorithmes récursifs: un algorithme est dit récursif, si l’une de ses opérations est un appel à une autre instance de ce même algorithme (même opérations, mais avec des données différentes).
  En résumé si l'algorithme s'appel lui-même, il est récursif.

Notre appel récursif doit forcément figurer après une condition, sinon l’algorithme ne s’arrêterait jamais. Cette condition, nommée condition terminale, doit impérativement être remplie à un moment donné pour garantir l’exécution de l’algorithme dans un temps fini.

## Structure de donnée récursive
```ts
class Node {
  nodes: Node[];
}
```

## Algorithme récursif
```ts
/**
* Node1
* ├── Node2
* ├── Node3
* │   └── Node4
* ├── Node5
* │   ├── Node6
* │   ├── Node7
* │   └── Node8
* │       └── Node9
* └── Node10
**/

function find_node(node: Node) {
  // ...

  // If this condition do not exist our algorithme will never stop
  if (node.nodes.length <= 0) return;
  
  return find_node(node.nodes);
}

input_node = new Node(/* ... */);
find_node(input_node);
```

```cpp
int sum(int n) {
  if (n<=0) return 0;
  else return n + sum(n-1);
}
```

# Récursivité et récurrence
La démonstration par récurrence et un algorithme récursif sont assez similaire. Les 2 points importants jouent un rôle similaire

- Le point d’ancrage et la condition terminale servent à garantir que le résultat est connu ou vérifié pour un cas trivial. Sans eux, une preuve par récurrence ne serait pas fondée et un algorithme récursif ne se terminerait jamais.

- Le passage d’un rang au rang suivant (ou précédent) permet d’étendre le domaine de validité d’une relation (pour une preuve par induction) ou de reporter le problème à un cas plus simple (pour un algorithme récursif).

Si on cherche à calculer la somme des premiers entiers, on peut dire : “Calculer la somme des n premiers entiers est facile, si je connais cette somme pour n-1 : il suffit d’y ajouter n”. Il suffit ensuite de reproduire cette démarche jusqu’à arriver au cas trivial : la somme des 0 premiers entiers est nulle.

### Définition récursive
![](images/2021-06-30-15-49-49.png)

### Preuve par récurrence
Point d’ancrage  
Passage de *n-1* à *n*

### Algorithme récursif
```
SOMME(n):  
  SI n<=0  
      somme ← 0  
  SINON
      somme ← n + SOMME(n-1)
```

### Fonction récursive
```cpp
int sum(int n) {
  if (n<=0) return 0;
  else return n + sum(n-1);
}
```

# Conception d'un algorithme jusqu'à la récursivité
Le travail d’un programmeur commence toujours par analyser un problème concret. Cela permet de modéliser le problème afin d’écrire un algorithme, qui sera finalement implémenté par un programme capable de résoudre ce problème.

Dans cette démarche, le principe souvent mis en œuvre est de décomposer le problème en sous-problèmes, puis de reprendre cette démarche pour chacun des sous-problèmes, jusqu’à arriver à des opérations élémentaires, faciles à réaliser.

La récursivité est un cas particulier de la mise en pratique de ce principe. Le sous-problème est de même nature que le problème initial, mais à un rang moins élevé. On peut dire que le principe de récursivité consiste à reporter un problème à son cas trivial.

# Quand utiliser un algorithme récursif ?
La récursivité est solution pour des problèmes qui se présentent sous forme récurrente.

Reprenons le calcul de la somme des *n* premiers entiers, lorsque le problème est énoncé de la façon suivante: "la somme des *n* premiers entiers vaut: (*n* + la somme des *n-1* premiers entiers)", l’algorithme récursif découle directement de l’énoncé. Tandis qu'un l’algorithme itératif demanderait une adaptation.

Pour la même raison, la récursivité est pratique pour des algorithmes qui s'appliques à des structures de données récursives (listes, arbres, graphes, ...)

**Exemples courants d’algorithmes récursifs**: parcours d’arbre (arborescence de fichiers d’un répertoire), Fractales, Quicksort, MinMax, etc.

# Exécution d’une fonction récursive
Lors de l’exécution d’une fonction récursive, un nouveau contexte (adresse de retour, paramètres et variables locales) sera créé dans la mémoire lors de chacun des appels récursifs.

Il est faux de dire qu’une fonction récursive est une fonction qui se rappelle elle-même: si cette affirmation est vraie pour les instructions qui seront exécutées, elle ne l’est pas pour les données qui seront traitées par la fonction. Le contexte étant différent pour chaque appel, chacun de ses appels a ses propres données, différentes d’un appel à l’autre.

En réalité, chaque appel correspond à une nouvelle instance de la fonction, même si le code n’est pas dupliqué en mémoire.

L’exécution proprement dite peut se décomposer en 2 temps:
- **Phase de descente**
  Appels récursifs (et création d’un contexte pour chacun d’entre eux) jusqu’à la condition terminale.
- **phase de remontée**
  Retour des résultats et libération des contextes devenus inutiles.

# Deux types de récursivité
En programmation, on distingue 2 types d’algorithmes récursifs

## Récursivité Terminale
Un algorithme récursif est terminal si aucune opération ne suit l’appel récursif.

C’est l’appel récursif qui "termine" l’algorithme. Toutes les opérations sont faites avant l’appel récursif: la phase de remontée devient alors inutile (elle ne fait aucun traitement, hormis le réajustement de la pile). La récursivité terminale revient à appliquer l’adage "diviser pour régner" de la façon suivante:

1. On traite la donnée courante,
2. Le même traitement est appliqué au reste des données.

```ts
/**
* Node1
* ├── Node2
* ├── Node3
* │   └── Node4
* ├── Node5
* │   ├── Node6
* │   ├── Node7
* │   └── Node8
* │       └── Node9
* └── Node10
**/

function find_node(node: Node) {
  // ...

  // If this condition do not exist our algorithme will never stop
  if (node.nodes.length <= 0) return;
  
  // Return directly the result of the recursive call
  return find_node(node.nodes);
}

input_node = new Node(/* ... */);
find_node(input_node);
```

## Récursivité Non-Terminale
Un algorithme récursif est non-terminal lorsque des opérations suivent l’appel récursif. C’est notamment le cas lorsque l’appel récursif est utilisé dans une expression pour calculer un résultat, comme dans l’exemple de la somme des *n* premiers entiers. On a besoin du résultat de l’appel récursif pour calculer le résultat à renvoyer: l’appel récursif ne "termine pas" l’algorithme. Toutes les opérations ne sont pas faites avant l’appel récursif: la phase de remontée fait une partie du traitement, elle contient souvent la majorité des opérations. La récursivité non-terminale revient à appliquer l’adage "diviser pour régner" de la façon suivante:

1. On réduit le problème à son cas trivial
2. On traite le cas et on élargit l’ensemble des données traitées.

```cpp
int sum(int n) {
  if (n<=0) {
    return 0;
  } else {
    int prev_sum = sum(n-1)

    // Operations after the recursive call
    return n + prev_sum;
  }
}
```

# Points cruciaux pour la programmation récursive
- Avoir une condition terminale.
- Avoir un appel récursif dont un des paramètres arrive à la condition terminale.
- S’assurer que la condition est TOUJOURS atteinte après un nombre fini d’appels.

# Quand éviter d’utiliser un algorithme récursif ?
Dans certains cas, notamment lorsque la récurrence est d’ordre plus grand que 1 (que la valeur au rang n ne dépend pas seulement du rang n-1, mais aussi de n-2, voire n-3, etc.), une utilisation de la récursivité impliquera une redondance de calculs.

Dans ce cas, il peut être utile de dérouler l’algorithme avant de l’implémenter pour s’assurer qu’il ne génère pas d’opérations inutiles.

# Récursivité et itérations
Tout algorithme récursif a un équivalent itératif. La réciproque est également vraie en théorie, mais le passage de l’un à l’autre n’est pas toujours aisé. La procédure de dé-récursivation consiste à gérer dans le programme le comportement de la pile lors des appels récursifs.

En règle générale, un algorithme récursif est moins performant qu’un algorithme itératif car chaque appel récursif nécessite d’empiler le contexte de la fonction, puis quand la condition terminale est atteinte, dépiler ce contexte avant d’exécuter les instructions qui suivent l’appel récursif. La création, le changement et la libération de contextes sont donc des opérations supplémentaires non réalisées par l’équivalent itératif. Les algorithmes récursifs sont donc moins performants que leurs équivalents itératifs.

Une exception existe pour la récursivité terminale qui est détectée par la majorité des compilateurs et comme il n’y pas d’instruction à exécuter après l’appel récursif terminal, la phase de remontée est supprimée. Dans la plupart des cas, une fonction récursive terminale aura donc la même performance que son équivalente itérative. La récursivité est alors privilégiée, pour sa lisibilité et son élégance.
