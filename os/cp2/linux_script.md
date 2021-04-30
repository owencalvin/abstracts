# Variables
Le système de variable dans un script est le même quand un shell

**Par défaut, les variables sont de type texte**

## Accolade autour d'une variable
Les accolades permettent de lever une ambiguïté sur le nom d’une variable

```sh
$ a=Bon
$ echo $ajour
```

```sh
$ a=Bon
$ echo ${a}jour Bonjour
```

```
Bonjour
```

## La variable `$?`
`$?` est la variable contenant le code d’erreur de la dernière commande
- 0 pour pas d’erreur
- \>0 pour erreur

## Obtention des arguments du script
- `$#`  
Nombre d’arguments reçus par le script

- `$0`  
Nom du script
  
- `$n`  
Argument reçu en position n (de 1 à 9)

- `${m}`  
Argument reçu en position m (dès 10)

- `$*` ou `$@`  
Liste de tous les arguments

```bash
#!/bin/bash

echo "Nb arguments: $#"
echo "Script: $0"
echo "Arg 1: $1"
echo "Arg 2: $2"
echo "Tous : $*"
```

```
$ ./script A B C D E
Nb arguments: 5
Script: script
Arg 1: A
Arg 2: B
Tous : A B C D E
```

## La commande `read`
La commande `read` permet de demander une chaîne de caractère (entrée standard) à l'utilisateur et l'assigner à plusieurs variables

`read [-p text] [var1] [var2] [...]`

- `-p`  
Affiche un texte avant d’entrer la valeur
- Les caractères espaces et tabulations séparent les sous-chaînes
- Une sous-chaînes affectée à chaque variable
- **Si plus de sous-chaînes que de variables:**  
dernière variable contient les sous-chaînes restantes
- **Si plus de variables que de sous-chaînes:**  
dernières variables contiennent `nul`

```bash
#!/bin/bash

read -p "Texte? " mot1 mot2 suite
echo "Mot 1: $mot1"
echo "Mot 2: $mot2"
echo "Suite: $suite"
```

```
$ ./script
Texte? Bienvenue au cours OS
Mot 1: Bienvenue
Mot 2: au
Suite: cours OS
```

## La commande `printf`
Permet d’afficher un message avec plus d’options que la commande echo

`printf [-v var] <text> [arguments...]`
- `text`  
Texte à afficher avec formatage identique à la même fonction en C

- `arguments`  
Suite de variables à utiliser

- `-v`  
Au lieu d'afficher, enregistrer dans la variable var

```bash
#!/bin/bash

article=fourniture; qte=3; prix=45.2
printf "%-20s %03d %+10.2f\n"   $qte $article $prix
```
```
$ ./script
fourniture 003 +45.20
```

# Arithmétique

## Déclaration d'un nombre entier
La commande `declare -i` permet de créer une variable de type nombre entier

```bash
declare -i x=10
```

## Evaluation d'une expression arithmétique `((...))`
La notation `((...))` permet d’évaluer l’expression arithmétique entre doubles parenthèses contenant:

- Des opérateurs identiques au langage C  
Mais avec `a**b` pour `a^b` (a puissance b)

- Des variables (`$` facultatif, **sauf pour les arguments**)

- Des espaces (non significatifs)

```bash
#!/bin/bash

declare -i x=10
((x = x+x+1))
echo $x
```
```
21
```

# Condition (`if`)
La commande `if` exécute des commandes en fonction d’une condition

> `if`, `then`, `elif`, `else` et `fi` sont des commandes  
> elles doivent être en début de ligne ou précédées de `;`

```bash
if <cond> ; then
  <commandes>
fi
```

```bash
if <cond> ; then
  <commandes1>
else
  <commandes2>
fi
```

```bash
if <cond1> ; then
  <commandes1>
elif <cond2> ; then
  <commandes2>
else
  <commandes3>
fi
```

## Condition
Les conditions peuvent être
- Une commande
- Une expression arithmétique
- Une expression conditionnelle

## Une commande  
vraie si le code d’erreur est `0`
```bash
#!/bin/bash

if rm "$1" ; then
  echo "$1 supprimé"
else
  echo "$1 pas supprimé"
fi
```

## Une expression arithmétique
On peut utiliser tout les opérateurs arithmétiques suivant

- `==`
- `!=`
- `<`
- `<=`
- `>`
- `>=`

```bash
#!/bin/bash

if (($1 % 2 == 0)) ; then
  echo "$1 est un multiple de 2"
fi
```

## Une expression conditionnelle
La notation `[[ ... ]]` permet d’évaluer l’expression   
conditionnelle entre doubles crochets contenant:

`[[ <item1> <op> <item2> ]]`

**ATTENTION:**  
**Les espaces sont obligatoire dans `[[ ... ]]` (après `[[` et avant `]]`)**  
**Et entre chaque opérateur et opérande `<op>`, `<itemI>`**


- Les opérateurs booléens semblables à ceux du langage C  
`&&` `||` `!` `( )`

- D'autres opérateurs pour traiter fichiers, arguments...

```bash
#!/bin/bash

if (($1 % 2 == 0)) ; then
  echo "$1 est un multiple de 2"
fi
```

### Comparaison numérique
`[[ <item1> <op> <item2> ]]`  

`item1` et `item2` sont variables ou nombres entiers  

`op` est un opérateur de comparaison numérique:
- `-eq` ==
- `-ne` !=
- `-lt` <
- `-le` <=
- `-gt` >
- `-ge` >=

```bash
#!/bin/bash

if [[ $# -lt 2 ]] ; then
  echo Pas assez d’arguments
fi
```

### Comparaison de chaîne de caractères
`[[ <string1> <op> <string2> ]]`  

`string1` et `string2` sont chaînes de caractères, variables ou non  
`string2` peut contenir des métacaractères  

`op` un des opérateurs suivants:
- `==`
- `!=`
- `=~` *utilise une regex pour la comparaison*

```bash
#!/bin/bash

if [[ $1 == A* ]] ; then
  echo Commence par A
fi
```

### Tester une chaîne vide
`[[ <op> <string> ]]`

`string` est une chaîne de caractères, variables ou non  

`op` peut être:
- `-z`  
`true` si chaîne vide

- `-n`  
`false` si chaîne vide

```bash
#!/bin/bash

if [[ -z $1 ]] ; then
  echo Paramètre manquant
fi
```

### Test sur des fichiers
`[[ <op> <file> ]]`

`file` est un chemin vers un fichier
`op` peut être:
- `-e` résultat vrai si le fichier existe
- `-f` résultat vrai si c’est un fichier ordinaire
- `-d` résultat vrai si c’est un dossier
- `-s` résultat vrai si le fichier est vide
- `-w` résultat vrai si l’utilisateur courant à accès en écriture

### Mixage des conditions
Il est possible de mélanger ces types de conditions avec les opérateurs booléens

```bash
#!/bin/bash

if [[ $1 -lt $2 && $3 == A* ]] ; then
  echo $1 est plus petit que $2 et $3 commence par A
fi

if [[ (($1 < $2)) && $3 == A* ]] ; then
  echo $1 est plus petit que $2 et $3 commence par A
fi
```

# Itération `for`
La commande for répète une suite de commandes pour une liste d’éléments qui peuvent être:
- Les arguments du script
- Les mots d’une ligne de texte
- Des fichiers du dossier courant
- Une variable incrémentée

```bash
#!/bin/bash

for <var> in <text> do
  <commandes>
done
```
- `text`  
Est une ligne de texte ou résultat d’une commande

- `var`  
Est une variable qui contient à chaque itération un mot du
texte

- `commandes`
Les commandes à exécuter

- `for`, `do` et `done`  
Sont des commandes, elles doivent être placées en début de ligne ou précédées de `;`

```bash
#!/bin/bash

for var in 5 4 3 2 1 Feu! do
  echo $var
done
```

```
$ ./script 5
4
3
2
1 Feu!
```

### Itérer sur tous les arguments du script `$*`
```bash
for <var> do
  <commandes>
done
```

- `var`  
Variable qui contient à chaque itération la valeur d’un argument

- `commandes`  
Les commandes à exécuter

```bash
#!/bin/bash

for fichier do
  if [[ -f $fichier ]] ; then
    echo "$fichier: fichier ordinaire"
  elif [[ -d $fichier ]] ; then
    echo "$fichier: dossier"
  fi
done
```

```
$ ./script /bin /etc/passwd
/bin: dossier
/etc/passwd: fichier ordinaire
```

### Itérer sur les fichiers du dossier courant
```bash
for <var> in <filename> do
   <commandes>
done
```

- Une itération pour chaque fichier correspondant au nom de fichier avec métacaractères `filename`

- `var`  
variable qui contient à chaque itération le nom du fichier

```bash
#!/bin/bash

for fichier in *.h do
  mv $fichier pro_$fichier
done
```

```
$ ls
a.h b.h c.h script
$ ./script
$ ls
pro_a.h pro_b.h pro_c.h script
```

### Itération générique
```bash
for ((<init>; <end>; <inc>)) ; do
  <commandes>
done
```
- `init`, `end` et `inc` sont des expressions arithmétiques
- Fonctionnement similaire à la boucle for du C

```bash
#!/bin/bash

sum=0
for ((a=1; a<=10; a++)) ; do
  ((sum+=a))
done

echo Resultat: $sum
```

```
$ ./mon_script
Resultat: 55
```

# Itération `while`
La commande `while` répète une suite de commandes tant qu’une condition est vraie

```bash
while <cond> ; do
  <commandes>
done
```
`cond` peut être, comme pour la commande `if`:
- Une commande: vraie si le code d’erreur est `0`
- Une expression arithmétique
- Une expression conditionnelle

```bash
#!/bin/bash

while [[ $var1 != end ]] ; do
  result=${result}$var1
  read -p "Input: " var1
done
echo $result
```

```
$ ./script
Input: a
Input: b
Input: c
Input: end
abc
```

# Fonctions
Il est possible de créer des fonctions dans un script

- Pour appeler une fonction il faut écrire son nom  
- La fonction doit être définie au moment de son appel
- Les variables du script sont accessibles dans la fonction et vice-versa

```bash
<fonction> () {
  <cmd>
}
```

```bash
function <fonction> () {
  <cmd>
}
```

> L'accolade fermante doit être en début de ligne

## Valeur de retour
La commande `return` permet de définir le **code d’erreur** de la fonction

`return` ne retourne pas le résultat, on utilise une variable pour ça

## Arguments
Une fonction peut recevoir des arguments comme un script
- Arguments de la fonction accessibles avec $n...
- Arguments du script pas accessibles dans la fonction

```bash
#!/bin/bash

aide () {
  echo "Ceci est l'aide de ce script"
}

if [[ $1 == --help ]] ; then
  aide
  exit 0 fi
if [[ $# -ne 2 ]] ; then
  echo "Erreur: pas assez d'arguments"
  aide
  exit 1
fi

# [...] suite du déroulement du script
exit 0
```

```bash
#!/bin/bash

declare -i result=0

add() {
  # Ici $1 et $2 sont les arguments de la fonction
  (( result = $1 + $2 ))
}

sub() {
  (( result = $1 - $2 ))
}

# Ici $1, $2 et $3 sont les arguments du script
if [[ $2 == + ]] ; then
  add $1 $3
elif [[ $2 == - ]] ; then
  sub $1 $3
fi

echo $1$2$3=$result
```