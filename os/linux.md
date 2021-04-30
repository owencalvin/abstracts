# GNU
Le but du projet était de réaliser un système similaire à UNIX mais libre

# Linux
## Historique
- Linus Torvalds conçoit un noyau semblable à UNIX
- Repose sur les outils GNU, appelé GNU/Linux
- Partagé comme logiciel libre (licence GPL, forcé par l'utilisation de GNU qui l'oblige)

## Introduction
- Propose un gestionnaire de paquets pour le téléchargement, l'installation et la mise à jour des programmes (dkpg, RPM, ...)
- Version de la distribution ≠ Version du noyau
- Certaines distribution propose une version *live* qui
démarre l'OS à partir d'un périphérique (CD-ROM, USB) sans installation sur le disque dur

## Exemples de distribution communautaire
- Code source et binaires libres
- Pas d’assistance technique obligatoire

### Debian 
- Stable et sûre mais avec une prise en main difficile
- Cible: serveur

### Ubuntu 
- Basé sur Debian
- Prise en main facile

### Fedora  

### Arch Linux

## Exemples de distribution commerciales
- Code source libre
- Binaires pas libre d’accès (commercialisés)
- Avec assistance technique

### RHEL (Red Hat Entreprise Linux) 
- La plus utilisée
- Marché des serveurs d'entreprises
- Basé sur Fedora

### Suse 
- Alternative principale

## Systèmes UNIX (MacOS) / Linux
Tout système d’exploitation UNIX / Linux inclut normalement :
- Interpréteurs de lignes de commandes (CLI)
- Commandes de manipulation de fichiers
- Commandes de gestion des processus
- Éditeurs de texte
- Compilateur C (usage parfois abandonné de nos jours)
- Outils de développement
  - compilateurs
  - débogueurs
  - analyseurs lexicaux et syntaxiques
  - ...

## Structure de fichiers Linux
- Seul le caractère `/` est interdit dans le nom de fichier
- La racine du système est `/`
- Chaque dossier content au moins 2 fichier
  - `.` qui fait référence au dossier courant
  - `..` qui fait référence au dossier parent

### Chemin (path)
Le chemin (path) est une suite de dossier séparé par le caractère `/` amenant à un fichier ou dossier

### Fichier caché
Un fichier et caché si il est préfixé par `.`  
`.profile`  
`.bashrc`

#### Absolu
- Commence par le caractère `/`
- Interprété à partir de la **racine**

#### Relatif
- Ne commence **pas** par `/`
- Interprété en partant du **dossier courant**

### Dossier personnel
Chaque utilisateur a son dossier personnel dans `/home` (par exemple: `/home/owen`)

Il contient en général
- Les fichiers personnels
- Certains fichiers de configuration (souvent caché => préfixés par `.`)

#### Le caractère `~`
Un chemin préfixé par `~` est interprété à partir du dossier personnel de l'utilisateur courant

Si le caractère `~` est suivi d’un nom d’utilisateur, il est interprété en partant du dossier personnel de cet utilisateur

`cd ~/dox` = `cd /home/durand/doc`  
`~dupond/` = `/home/dupond`

### Fichiers système
A la racine `/` on peut trouver ces dossiers utilisé par le système:

#### `/bin`
Commandes de base du système

#### `/boot`
Noyau et fichiers de configuration

#### `/dev`
Fichiers représentant des périphériques

#### `/etc`
Fichiers de configuration du système

#### `/home`
Répertoires utilisateurs

#### `/lib`
Bibliothèques de base du système

#### `/lost+found`
Fichiers détériorés que le système a essayé de récupérer

#### `/mnt`
Systèmes de fichiers montés (p. ex. /mnt/usbdisk)

#### `/opt`
Outils spécifiques installés par l’administrateur (souvent remplacé par /usr/local)

#### `/proc`
Accès aux informations du système /proc/cpuinfo, /proc/version...

#### `/root`
Répertoire utilisateur de l’administrateur

#### `/sbin`
Commandes réservées à l’administrateur

#### `/sys`
Contrôle du système et des périphériques (fréquence du processeur, gestion de l’alimentation des périphériques...)

#### `/tmp`
Fichiers temporaires

#### `/usr`
Programmes utilisateurs ordinaires, non essentiels au système: `/usr/bin`, `/usr/lib`, `/usr/sbin`, ...

#### `/usr/local`
Outils spécifiques installés par l’administrateur (souvent préféré à `/opt`)

#### `/var`
Données utilisées par le système ou ses serveurs: journaux (`/var/log`), courrier entrant (`/var/spool/mail`), travaux d’impression (`/var/spool/lpd`)


# Le shell
Le shell est un **CLI** (Interpréteur de commandes en mode texte)

Il peut s'utiliser de plusieurs façon:
- En mode interactif
  - Il affiche une invite de commande en début de ligne (**prompt**), souvent terminé par `$`
  - L'utilisateur entre une commande au clavier
  - La commande est interprétée et exécutée après la frappe de la touche ENTER
- Pour exécuter des scripts écrits dans le langage du shell

## Les différents shell Linux

### Bourne Shell - `sh`
- Offre des fonctions de programmation basiques

### C-Shell - `csh` ou `tcsh`
- Incompatible avec Bourne Shell
- Offre des fonctions supplémentaires  
  - Historique de commande
  - Contrôle de tâches
  - Alias de commandes

### Korn Shell - `ksh`
- Reprend le Bourne Shell et l’enrichit
- De plus en plus utilisé, devient un standard
- La version datant de 1988 (ksh88) a servi à la normalisation du shell (IEEE POSIX 1003.2)

### Bourne Again Shell - `bash`
- Proposé par la Free Software Foundation
- Conforme à la norme POSIX
- Fourni en standard avec les distributions Linux
- Porté sur MS Windows avec *Cygwin* ou *MinGW*

# Commandes

## Les commandes interne
- Intégrées au programme shell
- Ne correspond pas à un fichier sur le disque
- Exécutée par le shell courant

### Exécution d'une commande interne
1. Le shell identifie la commande comme interne
2. Il effectue les opérations demandées (par exemple change le dossier courant pour la commande `cd`)

## Commande externe
- Fichier localisé dans l’arborescence
  - Au format binaire exécutable
  - Au format texte contenant un script (script shell, Perl, ...)

### Exécution d'une commande externe
1. Le shell ne reconnaît pas la commande comme interne
2. Il recherche le fichier dans les dossiers de la variable d’environnement **`PATH`**
3. Il démarre un shell enfant (nouveau processus) et y exécute la commande externe

## Si une commande existe en interne et externe
- Commande interne exécutée par défaut
- Préciser le chemin vers le fichier pour la commande externe

## La commande `type` 
permet de savoir si une commande est interne ou externe  
`type cd`  
`type ls`

## Détails des commandes

### `ls`
*Commande externe*  

Permet de lister les dossier et fichiers d'un dossier
Ou afficher les droits d'un dossier / fichier

`ls [-aldF] [<chemin1>...<cheminN>]`

- `-a`  
Liste aussi les fichiers cachés

- `-l`  
Format long: taille, date, droits...

- `-d`  
Décrit le répertoire et non son contenu

- `-F`  
Format court avec indication du type de fichier (ajoute `*` si 
exécutable, `/` si répertoire)

`ls mondossier`
`ls -l mondossier` (affiche les droits)
`ls -l monfichier` (affiche les droits du fichier)
`ls -a mondossier` (affiche les fichiers / dossiers cachés)

#### Interprétation des informations
`-rwxr-x--- 1 owen users 32420 Mar 25 23:29 monfichier`
- `owen` est le propriétaire du fichier et fait parti du groupe *user* (modifiable avec `chown`)
- Le premier caractère affiche le type de fichier
  - `-` pour ordinaire
  - `d` pour dossier
  - `l` pour un lien symbolique
- Les 9 suivants donnent les droits d’accès par ensemble:
  - Droits du propriétaire (`rwx`: lecture, écriture et exécution)
  - Droits des utilisateurs du groupe (`r-x`: lecture et exécution)
  - Droits des autres utilisateurs (`---`: aucun droit)

### `type`
*Commande interne*  
Permet de savoir si une commande est interne ou externe  
`type cd`  
`type ls`

### `cd`  
*Commande interne*  
Permet de changer le dossier courant  
`cd /var`  
`cd perso`  
`cd ../../var`

### `mkdir`
Crée un dossier
L'option `-p` permet de créer tous les dossier non existant dans le path précisé

`mkdir mondossier`  
`mkdir /home/owen/mondossier`

*dossier1 et dossier2 n'existe pas => création des deux avec `-p`*  
`mkdir -p /home/owen/dossier1/dossier2`

### `rm`
Supprime un dossier / fichier

`rm [-rfi] path`

- `-r`
Supprime de façon récursive des dossiers et fichiers (vide ou pleins)

- `-i`
Demande confirmation pour chaque fichier

- `-f`
Force la suppression

`rm monfichier`
`rm -Rf mondossier`

### `rmdir`
Supprime un dossier vide
`rmdir mondossier`

### `pwd`
Affiche le dossier courant
`pwd`

### `cat`
Affiche le(s) fichier(s) en argument ligne par ligne  
```sh
$ cat mon-texte.txt
a
b
c
```

### `tac`
Exactement comme `cat` mais affiche dans le sens inverse (comme le nom l'indique).
Affiche le fichier de la dernière ligne à la première.
```sh
$ tac mon-texte.txt
c
b
a
```

### `head`
Affiche les `n` premières lignes d’un fichier

`head [-nF] file`

- `-n`  
Affiche `n` nombre de lignes

- `-F`  
Rafraîchit l'écran régulièrement avec les lignes ajoutées au fichier

```sh
$ head -n 2 mon-texte.txt
a
b
```
```sh
$ head -n 1 mon-texte.txt
a
```

### `tail`
Affiche les `n` dernières lignes d’un fichier

`tail [-nF] file`

- `-n`  
Affiche `n` nombre de lignes

- `-F`  
Rafraîchit l'écran régulièrement avec les lignes ajoutées au fichier

```sh
$ head -n 2 mon-texte.txt
b
c
```
```sh
$ head -n 1 mon-texte.txt
c
```

### `cp`
Permet de copier des fichiers

`cp [-ipr] <source> <dest>`

- `-i`  
Demande confirmation en cas d’écrasement de la destination

- `-p`  
Préserve les dates d’accès et de modification

- `-r`  
Copie récursive (dossier et sous-dossiers)

`cp a.txt dossier/b.txt`

### `mv`
Permet de déplacer / renommer un ou plusieurs fichiers

`mv [-i] <source> <dest>`

- `-i`  
Demande confirmation en cas d’écrasement de la destination

`mv a.txt dossier/b.txt`   

*Renomme a.txt en b.txt*  
`mv a.txt b.txt`

### `file`
*Commande externe*  
Donne des indications sur le type de données contenues dans un fichier.  
Si c'est un exécutable binaire ou texte sous forme de script  
`file /usr/bin/ls` => exécutable  
`file myscript` => ascii text => script

### `grep`
Recherche un texte dans un fichier  
Plusieurs fichiers possibles, avec ou sans métacaractère

`grep [-rnciv] <regex> [files...]`

- `regex`  
Peut aussi être un simple texte

- `-r`   
Recherche récursive dans tous les fichiers du dossier

- `-n`  
affiche les n° de ligne

- `-c`  
compte et affiche le nombre de lignes

- `-i`  
ne tient pas compte de la casse

- `-v`  
affiche les lignes qui ne respectent pas la regex

#### Affiche toutes les lignes contenant error dans les fichiers avec l'extension log du dossier courant
```bash
grep error *.log
```

#### Même recherche, mais dans tous les fichiers du dossier courant et des sous-dossiers
```bash
grep –r error .
```

#### Affiche les 20 dernières lignes contenant installed du fichier dpkg.log
```bash
grep installed dpkg.log | tail –n 20
```

### `find`
Permet de rechercher des fichiers ayant certaines caractéristiques

`find <path> <expression>`

- `path`  
Chemin(s) où rechercher

- `expression`  
liste d'arguments pouvant être:
  - Des options
  - Des critères de recherche  
    par exemple: `-name` le nom du fichier
  - Des actions  
    par exemple: `-delete` pour supprimer les fichiers
  - Des opérateurs logiques  
    parenthèses `( )`, `!` pour NON, `-o` pour OU et `-a` pour ET

```bash
find . -name "*.pdf"
```

#### Critères de recherches principaux
- `-name "<filename>"`
Nom du fichier  
  - `""`  
  protéger les métacaractères de l'interprétation par le shell

- `-iname`  
Idem, sans tenir compte de la casse

- `-type <t>`  
Type de fichier
  - `f`: fichier
  - `d`: dossier

- `-mmin [+-]<m>`  
Modifié il y a + ou - de m minutes

- `-mtime [+-]<n>`    
Modifié il y a + ou - n * 24h

- `-size [+-]<n>[bcwkMG]`  
Taille du fichier
  - `-`: inférieure à
  - `+`: supérieure à
  - unité  
    - `b`: bloc de 512o
    - `c`: octets
    - `w`: mot de 2 octets
    - `k`: kio
    - `M`: Mio
    - `G`: Gio

#### Arguments d'actions principaux
- `-print`  
Affiche le nom des fichiers trouvés (defaut)

- `-printf`  
Idem, mais avec un format personnalisable

- `-fprint[f] <file>`  
Enregistre le nom des fichiers trouvés dans le fichier file

- `-delete`  
Supprime les fichiers trouvés

- `-exec <command>;`  
Exécute une commande sur tous les fichiers trouvés
  - Le caractère `;` indique la fin de la commande
  - Le caractère `;` doit être protégé de l'interprétation par le shell, donc entouré de guillemets simples `'`
  - Les occurrences de `{}` sont remplacées par le nom du fichier
  - Idem pour les caractères `{}` dans un script bash


#### Ouvre avec xpdf tous les fichiers PDF se trouvant dans le dossier Documents et ses sous-dossiers
```bash
find ~/Documents -iname "*.pdf" –exec xpdf {} ';'
```

#### Liste tous les fichiers ordinaires de plus de 100 Mio
L'option `–printf` est utilisée pour afficher:
- La taille en octet avec `%s`
- Le nom du fichier avec` %p`

```bash
find / -type f –size +100M –printf '%so %p\n'
141978443o /usr/lib/jvm/java-11-openjdk-amd64/lib/modules
...
```

### `ps`
Permet d'afficher des informations sur les processus

- `UID`  
L'ID du l'utilisateur propriétaire du processus

- `PID`  
L'ID du processus

- `STAT`  
L'état
  - `R`: actif
  - `S`: inactif
  - `<`: haute priorité
  - `N`: basse priorité...)

#### Listes avec arborescence de tous les processus
```bash
ps aux --forest
```

#### Liste des 5 processus utilisant le plus de mémoire
```bash
ps –eF --sort=-%mem | head –n 6
```

### `nice`
L'OS partage le temps CPU en fonction de la priorité
des processus

La commande nice permet de démarrer une commande en spécifiant sa priorité

`nice -n <priority> <command>`

- `-n` Permet de définir la priorité entre
  - `-20` : priorité la plus haute
  - `19` : priorité la plus basse

> Priorités négatives utilisables qu'avec les droits root

### `kill`
Permet d'envoyer un signal à un processus

`kill [-s <sig>] <pid>`

> Il faut être propriétaire du processus ou avoir les droits root

- `sig`    
Le nom ou le numéro d'un signal (défaut `KILL`)

- `pid`  
L'ID du processus

- `-L`  
Affiche tous les signaux possibles

```bash
$ ps –e | grep firefox
1234 ?  00:23:23 firefox-esr

$ kill –s QUIT 1234
```

#### Avec numéro de tâche 
Le numéro de tâche peut aussi être passé à la
commande `kill` avec `%n`

```bash
$ kill %1
```

### `who`
liste les utilisateurs logués

`who`

#### seulement l'utilisateur courant
`who i am`

### `top`
Affiche avec rafraîchissement régulier:
- L'utilisation du système par les processus
- La liste des processus (comme `ps`)

Lorsque qu'elle est démarrée, plusieurs actions sont possibles avec le clavier: 
- Changer l'affichage
  - `t` et `m`: progress bar
  - `y` et `x`: highlight
- Changer l'ordre de tri
  - `P`: %CPU
  - `M`: %MEM
- Envoyer un signal à un processus 
  - `k`: kill
- Quitter
  - `q`

### `jobs`
Liste les tâches (jobs) du shell courant 

`jobs [-l]`

- `-l`  
Affiche aussi l'ID du processus de chaque tâche

> Chaque tâche (job) à un numéro de tâche

```bash
$ firefox &
[1] 2345
$ jobs –l
[1]+ 2345 Running
$ ps –-forest
firefox &
PID TTY
2020 pts/0
2345 pts/0
2385 pts/0
2435 pts/0 00:00:01 | \_ WebExtensions 2478 pts/0 00:00:00 | \_ Web Content 2512 pts/0 00:00:00 \_ ps
$
```

### `disown`
A l'arrêt du shell, les processus de ses tâches sont
arrêtés

La commande `disown` détache le processus d'une tâche du shell. Le processus ne sera pas arrêté avec le shell.

`disown %n`
- `n`  
Numéro de la tâche

#### Les sorties standard sont toujours liées au shell, il faut les redirigée vers le périphérique nul `/dev/null`
Démarre Firefox en arrière-plan en redirigeant les sorties standard puis détache ce processus du shell
```bash
$ firefox 2> /dev/null &
[1] 2345
$ jobs
[1]+  Running
$ disown %1
$ jobs
$
```

### `sudo`
*Commande externe*  
Permet de lancer une commande en tant que root  
```bash
apt-get install monProgramme
```

### `su`
*Commande externe*  
Permet de démarrer un shell en tant qu’autre utilisateur  
Souvent utilisée avec l’option `-` pour accéder au compte *root* qui a des droits illimités sur le système

La commande exit permet de quitter le shell *root*

```
su -
password:
# apt-get install monProgramme
...
#
```

### `exit`
*Commande interne*  
Permet de quitter le shell root

### `chown`  
*Commande externe*  
Change le propriétaire (peut être un groupe) d'un fichier / dossier 

```bash
chown owen monfichier
```

*Récursif*
```bash
chown -R owen mondossier
``` 

### `chmod`  
*Commande externe*  
Change les droit d'un fichier / dossier

*Donne tout les droit à tous le monde*  
`chmod 777 monfichier`   
`chown -R 777 mondossier` (récursif) 

*Façon explicite*  
- Le `=` permet d'assigner les droits  
- Le `+` permet d'ajouter des droits   
- Le `-` permet d'ajouter des droits    

`chmod u-r monfichier`   
`chmod g+x,o-x monfichier`   
`chmod u=rwx,g=rx-w,o=r-wx monfichier` 

### `wc`
Compte le nombre de caractères, de mots et de lignes de fichiers texte

> Utilisable sur plusieurs fichiers

`wc [-cmwl] file`

- `-c`  
Compte le nombre d'octets

- `-m`  
Compte le nombre de caractères

- `-w`  
Compte le nombre de mots

- `-l`  
Compte le nombre de lignes

### `sort`
Trie les lignes d'un fichier ou de l'entrée standard

`sort [-rnu] file`

- `-r`  
Ordre inverse

- `-n`  
Tri numérique (alphabétique par défaut)

- `-u`  
Supprime les doublons

### `more` et `less`
Utile par exemple pour de longs fichiers, l'entièreté du fichier n'est pas chargé en mémoire

> Commandes pour la navigation similaires à celles des éditeurs vi et vim

#### `more`
Affiche le fichier ou l'entrée standard écran par écran

#### `less`
Permet de revenir en arrière

`more file`  
`less file`


### `diff`
La commande diff liste les différences entre 2 fichiers
`diff <file1> <file2>`

#### Chaque différence est affichée ainsi :
Commence par les n° de lignes concernées et l'opération:
`<line file1>[acd]<line file2>`

- `a` : pour une ligne ajoutée dans le fichier 2
- `c` : pour une ligne changée
- `d` : pour une ligne supprimée dans le fichier 2

#### Les lignes différentes sont affichées ensuite
- Celles du fichier 1 commencent par >
- Celles du fichier 2 commencent par <

*file1.txt*
```
Une première ligne
Une deuxième ligne
Une troisième ligne
Une quatrième ligne
```

*file2.txt*
```
Une ligne ajoutée avant la première
Une première ligne
Une troisième ligne
Une quatrième ligne modifiée
```

```bash
$ diff file1.txt file2.txt
0a1
> Une ligne ajoutée avant la première
2d2
< Une deuxième ligne
4c4
< Une quatrième ligne
---
> Une quatrième ligne modifiée
```

### `declare -i`
permet de créer une variable de type nombre entier

`declare -i x=10`

### `printf`
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

### `read`
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

### `rsync`
Permet de synchroniser des dossiers
- Conçue la synchronisation entre 2 machines reliées par une connexion à faible débit
- Ne copie que les fichiers qui ont changé (comparaison avec la taille et une somme de contrôle)
- Ne transfère que les blocs de fichiers différents
- Conserve les liens symboliques et les permissions
- Peut fonctionner avec SSH

#### Utilisation
- Copie conséquente sur la même machine
- Mise à jour du contenu d’un site web sur un serveur

# Les droits
Pour chaque fichier il y'a 3 types de droits:
- Concernant le propriétaire du fichier (owner `u`)
- Le groupe d'utilisateurs propriétaire du fichier (group `g`)
- Les autres utilisateurs du système (other `o`)

Il y'a 3 permission possibles
- En lecture (read `r`)
- En écriture (write `w`)
- En exécution (execution `x`)

## Changement de droits
on peut changer tous ces droits avec la commande `chown` et `chmod`

## Changer d'utilisateur pour une session
On utilise la commande `su` démarrer un shell en tant qu'autre utilisateur
On utilise l'option `-` pour accéder au compte *root*
On utilise la commande `exit` pour quitter le compte *root*

## La commande `sudo`
La commande `sudo` permet de lancer une commande en tant que *root*  

Elle doit être suivie de la commande a exécuter:  
`sudo apt-get install monProgramme`

> L’utilisateur doit être dans le groupe `sudo`  
> Elle est plus sûr car se limite à l’exécution d’une seule commande

# Les métacaractères du shell (wildcard character)
Avant d’exécuter une commande, **le shell**:
- Analyse la ligne entrée
- Remplace les arguments correspondant a des noms de fichiers ou dossiers contenant des métacaractères par la liste de fichiers ou dossiers correspondante

**C'est le shell qui s'occupe de traiter les wildcards et non la commande exécutée (contrairement à Windows)**

> On place l'argument entre guillemets simples pour ne pas interpréter les wildcards  
> par exemple: `ls '*.c'`

## Le wildcard `*`
Remplace une suite de caractères de taille quelconque
```sh
ls *.c
```
```
abc.c
wxyz.c
hello.c
```

## Le wildcard `?`
Remplace un seul caractère
```sh
ls ?.c
```
```
a.c
b.c
d.c
```

## Le wildcard `[]`
Remplace par un des caractères mentionnés entre crochet  
La liste peut spécifier un intervalle avec le caractère: `[a-z]`
```sh
ls [hg]
```
```
gnu-txt
hello.o
```

## Le wildcard `{}`
Remplace par chaque élément de la liste, séparés par une virgule `{a,b,c}`  
```sh
ls os_{linux,macos}
```
```
os_linux
os_macos
```

# Redirections des I/O (Entrées / Sorties)
Chaque programme UNIX dispose d’au moins 3 flux de données

- **L’entrée standard**  
En lecture, normalement associée au clavier du shell

- **La sortie standard**  
En écriture, normalement associée à l’écran du terminal ou la fenêtre de lancement

- **La sortie standard des erreurs**  
Comme la sortie standard, pour afficher les messages d’erreurs

## Sortie standard dans un fichier `>` (o => file)
Permet de rediriger **la sortie** standard vers un fichier
```sh
$ ls > result.txt
```

*contenu de result.txt après exécution*
```
a.txt
b.txt
```

- Le résultat de la commande n’est pas affiché dans le terminal, mais stocké dans le fichier `result.txt`
- `result.txt` est créé si il n'existe pas ou son contenu est remplacé s'il existe

> Seuls les messages d’erreurs sont affichés dans le terminal

### Double chevron (`>>`)
Utiliser `>>` permet de conserver le contenu du fichier et ajouter la sortie à la fin du fichier
```sh
$ ls >> result.txt
```

*contenu de result.txt après exécution*
```
a.txt
b.txt
a.txt
b.txt
```

### Autres variantes
#### Utiliser `2>` ou `2>>` pour rediriger la sortie d’erreurs
#### Utiliser `&>` ou `&>>` pour rediriger les 2 sorties

## Entrée standard dans un fichier `<` (i <= file)
Permet de rediriger **le contenu** d'un fichier dans **l'entrée** standard
```sh
$ cat < unfichier
```

> Le contenu du fichier `unfichier` est affiché  
> Attention ce n'est pas équivalent à `cat $(cat unfichier)`

*Il est possible de rediriger l’entrée et la sortie standard*
```
$ cat < unfichier > result
```
> Rien n’est affiché
> Le contenu du fichier `unfichier` est inscrit dans le fichier `result`

## le pipe `|` (tube)
Permet de rediriger **la sortie** d’une commande vers **l’entrée** d’une autre commande  
`cmd1` => **o1 = i2** => `cmd2` => **o2 = i3** => `cmd3` => ...
> Les commandes sont exécutées en parallèle

*Affiche le contenu du répertoire trié à l’envers*
```sh
$ ls | sort -r
```

### Utilisation avec `tee`
La commande `tee` utilisée après un tube permet de diriger la sortie standard vers le shell et un fichier

`<command> | tee [-a] <file>`

- `-a`  
pour inscrire à la fin du fichier (équivalant à `>>`)

```sh
$ make | tee build.log
```
> Lance la commande make et enregistre sa sortie dans le fichier build.log

### Utilisation avec `yes`
La commande `yes` permet de remplir l’entrée standard avec une chaîne de caractères

`yes <string> | <command>`
- `string`  
Chaîne de caractères  
Défaut: `y`

```sh
$ yes | rm –r dir/
```

```sh
$ yes no | credit applicant
```

```sh
$ yes "" | make config
```

# Substitution de commande `$(<cmd>)`
Il est possible d’exécuter une commande à l’intérieur d’une autre commande avec `$(<cmd>)`

`cmd1 $(cmd2)`: 
1. La commande `cmd2` est exécutée par le shell
2. La chaîne `$(cmd2)` est remplacée par le résultat de la
commande `cmd2`
3. La commande `cmd1` est exécutée avec le résultat substitué de `cmd2`


```sh
apt-get install linux-headers-$(uname -r)
```
Ce qui donne:
```
apt-get install linux-headers-4.19.0-12-amd64
```

# Variables
La commande `env` liste les variables d’environnement  
La commande `set` liste en plus les variables locales

`$$`  
l'ID du processus de la commande courante

`$!`  
l'ID du dernier processus lancé en arrière plan

## Variable d'environnement (système)
UNIX / Linux défini pour chaque processus une liste de variables d’environnement avec certains paramètres
- Répertoires d’installation des utilitaires
- Variable `PATH`
- Type de terminal
- ...

Chaque programme peut utiliser ces variables pour obtenir ces informations du système

Ces variables peuvent être utilisées directement dans une ligne de commande.  
Le shell remplace chaque variable par sa valeur avant d’exécuter la commande

**Les variables d'environnement sont en MAJUSCULES**

## Variable utilisateur
Un utilisateur peut définir ses propres variables  
Une variable est identifiée par un nom:
- Composé de lettres, du caractères `_` et des chiffres
- Ne commence pas par un chiffre
- La casse est **importante**
- Variables d'environnement en MAJUSCULES
- Variables utilisateur en minuscules

### Définition d'une variable
Le caractère `=` permet de définir une variable **locale**

```sh
$ couleur=rouge
```

> Si la valeur a des espaces entourer la de guillemets simples

La commande `export` permet de rendre une variable globale

La commande `unset` supprime une variable

### Evaluation d'une variable
Pour évaluer une variable il faut précéder son nom de `$`

```sh
$ echo $couleur
rouge
```

# Chaîne de caractères
Une chaîne de caractères peut être entourée de
- Guillemets doubles
- Guillemets simples (apostrophes) 
- Accent graves (back quote)

## Guillemets doubles  
**Permet d'évaluer les variables de la chaîne**
```sh
$ echo "La maison $couleur"
La maison rouge
```

## Guillemets simples (apostrophes)  
N'évalue **pas** les variables de la chaîne
```sh
echo 'La maison $couleur'
La maison $couleur
```

## Accent graves (back quote)  
Exécute le contenu de la chaîne
```sh
$ dossier=`pwd`
$ echo "Vous êtes ici: $dossier"
Vous êtes ici: /home/user
```

# Initialisation d'un shell
Au démarrage, un shell exécute un script de configuration qui peut contenir des commandes  

> En général utilisé pour définir des variables d’environnement et des alias

## Pour le `bash`
- `~/.bashrc`  
Exécuté pour tout nouveau shell

- `~/.bash_profile` (ou à défaut `~/.profile`)  
Exécuté pour tout shell avec un login (démarrage en mode terminal, SSH...)  

## Pour le `csh`
- `~/.cshrc`  
Exécuté pour tout nouveau shell

## Pour le `sh`
- `~/.profile`  
Exécuté pour tout nouveau shell

# Les jobs
Un `&` à la fin d'une ligne de commande :
- Démarre celle-ci comme tâche en arrière plan
- Retourne au shell sans attendre la fin de son exécution

Si une commande est déjà démarrée 
-  CTRL+Z pour mettre la commande en pause
-  Commande bg: passe la tâche en arrière-plan

Une tâche (job) est un processus lié au shell

Chaque tâche (job) à un numéro de tâche

La commande `jobs` liste les tâches du shell courant 
- `-l` affiche aussi l'ID du processus de chaque tâche

Les commandes suivantes permettent la manipulation des jobs:
- `jobs`
- `ps`
- `kill`
- `who`
- `top`
- `disown`

```bash
$ firefox &
[1] 2345
$ jobs –l
[1]+ 2345 Running
$ ps –-forest
firefox &
PID TTY
2020 pts/0
2345 pts/0
2385 pts/0
2435 pts/0 00:00:01 | \_ WebExtensions 2478 pts/0 00:00:00 | \_ Web Content 2512 pts/0 00:00:00 \_ ps
$
```
