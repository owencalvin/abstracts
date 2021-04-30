# Le CLI
**C**ommand **L**ine **I**nterface  
Interface homme-machine en mode texte

## Fonctionnement
1. L’utilisateur tape une commande au clavier
2. L’ordinateur exécute la commande
3. L’ordinateur affiche le résultat ou pose une question à l’utilisateur
4. L’utilisateur tape une commande ou répond à la question
5. ...

## Utilisation
- Les informaticiens (dev. et IT): plus riche et rapide que les GUI
- Incontournable pour l’IT sur Linux
- La plupart des serveurs web (Linux) n’ont pas de GUI mais que du **CLI** (accès SSH)
- L’exécution de scripts

# CMD.exe
Version moderne du CLI de MS-DOS, appelé aussi «Invite de commandes» ou «Console»

# PowerShell
- Depuis MS Windows 7
- Orienté objet et basé sur le framework .NET

# Le système de commandes

## Prompt
Le prompt est ce qui se trouve avant la commande:
```batch
C:\>
```

## Commande
Peut être:
- Une commande interne *(par exemple: `dir`)*
- Un logiciel *(par exemple: `mspaint`)*
- Un script

## Argument
- Options: permettent de changer le fonctionnement *(par exemple: `-R -f`)*
- D’autres données : noms de fichiers, de dossiers... *(par exemple: `-o out.o`)*

### Les options
Elles peuvent être préfixées par un ou deux `-` ou sur Windows par `/`
- `/?`, `?`, `-?`
- `/h`, `-h`, `h`, `-help`, `--help`

## Echappement
Sur Windows les caractères `& | ^ < > ( )` doivent être échappé par `^`

```batch
C:\>echo Caractères à échapper: ^& ^| ^^ ^< ^> ^( ^)`
Caractères à échapper: & | ^ < > ( )
```

**Le caractère `%` doit être échappé ainsi: `%%`**

## Fichiers et dossiers
- Windows ne fais pas de différence entre majuscules et minuscules
- Caractères interdits: `< > : " / \ | ? *`
- Noms réservés à l’OS: `CON, PRN, AUX, NUL, COM1, COM2, COM3, COM4, LPT1, LPT2, LPT3, LPT4...`
- Un chemin **absolu** commence par le nom du lecteur ou du serveur
- Un chemin **relatif** commence par le dossier courant
- Le dossier `.` fait référence au dossier courant
- Le dossier `..` fait référence au dossier parent
- Le caractère `\` fait référence à la racine du lecteur courant

Un chemin (path) est une suite de dossier amenant à un fichier ou un dossier:  

*Local*  
`<drive>:\dir1\dir2\...\<name>.<extension>`
`C:\test\data.txt`  

*Réseau*  
`\\<server>\<share>\dir1\...\<name>.<extension>`
`\\intra.he-arc.ch\ORG\ING\Formation`

## Caractères génériques
Ils permettent de faire référence à plus d'un nom de fichier
- Pour remplacer plusieurs caractères on utilise `*`  
*liste tous les fichiers qui ont l'extension `.c`*  
`dir *.c`  

- Pour remplacer **un seul** caractères on utilise `?`  
*Efface les fichiers dont le nom commence par "liste" suivi par exactement 2 caractères et avec l’extension "out"*  
`del liste??.out`

## Variables
Le CMD permet d’utiliser des variables de types
- Chaîne de caractères **(par défaut)**
- Nombre entier signé (32 bits)

Il y'a plusieurs catégories de variables
- Définies au niveau de l’OS
- Définies et utilisées par des logiciels
- Définies par l’utilisateur

Un utilisateur peut définir des "variables utilisateurs" dans la session courante CMD
- Nom composé de lettres, le caractère `_` et de chiffres
- En minuscule par convention
- Valables que dans la session courante

Le système possède des variable d'environnement (ou système).   
- Elles sont globales, définies dans toutes sessions CMD.
- En majuscule par convention
- Accessibles via GUI dans Panneau de config. > Système > Paramètres systèmes avancés
- `PATH`: Liste des dossiers où cmd doit chercher une commande externe  
  `PROMPT`: Format et contenu du prompt  
  `TMP`: Dossier des fichiers temporaires  
  `WINDIR`: Dossier des programmes Windows

### La commande `set`
La commande `set` sans argument liste toutes les variables

Permet de chercher et afficher une variable  
`C:\>set PROMPT`  
`PROMPT=$P$G`

Permet de définir une variable  
`C:\>set couleur=Bleu`  *(Pas d’espace autour du signe =)*

Permet d'effacer une variable  
`C:\>set couleur=`

Entourer le nom d'une variable avec `%` pour utiliser sa valeur dans une commande  
`C:\>echo %couleur%`  
`Bleu`

`set /P` demande à l’utilisateur d’entrer la valeur
```batch
C:\>set /P entree="largeur : ? "
largeur : ? 12
C:\>set entree
entree=12
```

`set /A` permet de définir une variable de type entier  
  - Opérateurs arithmétiques: `+ - * / % et ( )`
  - Opérateurs binaires bit à bit: `& | ^`
  - Opérateurs de décalages binaires: `<< >>`  

``` batch
set /A total=12+25
```

il est possible d'évaluer plusieurs expressions
``` batch
C:\>set /A num=2,result=num*5
10
```

### Changer la variable d'environnement `PATH`
Pour la session courante *(non permanent)*  
`C:\>set PATH=%PATH%;C:\MyScripts\`  
ou  
`C:\>path %PATH%;C:\MyScripts\`

Avec la commande `setx` qui permet de modifier des variables d’environnement **de façon permanente**   
`C:\>setx PATH %PATH%;C:\MyScripts\`

## Types de commandes
**Commandes de contrôle**
- Contrôle l’interpréteur de commandes
- Exemple: CTRL+C interrompt la commande en cours

**Commandes internes**
- Fournies par l’interpréteur de commande
- D’usage fréquent
- Exemples:`dir`, `cd`, ...

**Commandes internes algorithmiques**
- Utilisé dans les scripts
- Exemples: `if`, `goto`, `for`, ...

**Commandes externes**
- Pas nécessaire de préciser l’extension (sauf ambiguïté)
- Exécute un fichier portant le nom de la commande
  - Exécutable binaire (`.exe`)
  - Script (`.cmd`, `.bat`)
- Le fichier est recherché dans l’ordre:
  - Dans le répertoire courant
  - Dans les répertoires listés par la variable d’environnement `PATH`

## Enchaînements et redirections

### Enchaînements
`cmd1 & cmd2`  
Exécute cmd1 puis cmd2

`cmd1 && cmd2`  
Exécute cmd1 puis cmd2 si cmd1 a réussi

`cmd1 || cmd2`  
Exécute cmd1 puis cmd2 si cmd1 a échoué

### Redirections
`cmd < file`  
Contenu du fichier envoyé dans l’entrée de cmd (*STDIN*)

`cmd > file`  
Sortie (*STDOUT*) de cmd écrit dans le fichier

`cmd >> file`  
Sortie (*STDOUT*) de cmd écrit **à la fin** du fichier

### Pipe (Concaténation de commandes)
`cmd1 | cmd2 | cmd3 | ...`
1. Exécute cmd1 et redirige sa sortie sur l’entrée de cmd2
2. Exécute cmd2 et redirige sa sortie sur l’entrée de cmd3...

`cmd2`, `cmd3`, ... doivent pouvoir traiter les données de l’entrée standard (STDIN), comme:

- `find` / `findstr`  
Recherche une chaîne de caractères

- `sort`  
Trie par ordre alphabétique des lignes

- `more`  
Découpe en nombre de lignes <= à la taille de la fenêtre

```bat
C:\>dir | find "F"
03.08.2020 08:21   <DIR>    Program Files
26.06.2020 07:42   <DIR>    Program Files (x86)
```

# Batch
Un fichier batch:
- Fichier avec l’extension .bat ou .cmd
- Permet l’automatisation des tâches en exécutant plusieurs commandes

Fonctionnement:
- Démarré dans le CLI avec le nom du fichier (extension
facultative)
- Commandes **interprétées** par le CLI ligne par ligne
- S’arrête à la fin du fichier

`C:\script.bat`
```bat
:: Mon premier script batch
@echo off
echo Bienvenue au cours OS
pause
```
```
C:\>script
Bienvenue au cours OS
Appuyez sur une touche pour continuer...
```

# Conventions de codage et nommage
### Commandes
- Casse pas significative, mais doit être cohérente

### Variables
- `camelCase`  
- Noms courts et compréhensibles  
- Variables des boucles FOR : une majuscule

### Labels
- Casse cohérente: `camelCase` ou `PascalCase`  
- Noms courts et compréhensibles

### Commentaires:
- Pour toutes les commandes qui ne sont pas évidentes  
- Expliquer en langage courant ce que vous souhaitez faire

### Indentation
- Indenter le contenu des blocs (`IF`, `FOR`...): espace ou tabulation  

### Langue
- Une seule langue (anglais, français, ...) par script

# Les commandes

### `@`
Exécute la commande qui suit sans l’afficher  
`@echo off`

### `::` / `REM`
Commentaire
`:: Mon commentaire`

### `echo`
Afficher un message ou une ligne vide 
Activer/désactiver l’affichage des commandes  
`echo`  
`echo Hello`   
`echo commande: %0, argument1: %1`  
`@echo off`

### `dir`
Liste les fichiers/dossiers du répertoire courant  
`dir`

### `cd`
Se déplacer dans les dossiers  
`cd mon_dossier`  
`cd ..` 

### `call`
Exécute la commande qui suit dans un nouveau CLI après avoir évalué les variables  
`call set newText=%%text:~%a%,%b%%%`

### `find`  
Recherche une chaîne de caractères dans un fichier ou l'entrée standard (STDIN)   

`find [/V] [/C] [/N] [/I] [/OFF[LINE]] "chaîne" [[lecteur:][chemin]nom_de_fichier[...]]`  

`find "F"`  
`find "Charlie" find-data-txt`  

*Recherche la ligne ne contenant pas la chaîne*  
`find /V "Charlie" find-data.txt`

*Compte le nombre de lignes*  
`find /C "Charlie" find-data.txt`  
`find /C /V "Charlie" find-data.txt`

*Recherche en ignorant la casse (l'ignore pas par défaut)*  
`find /I "charlie" find-data.txt`

*Affiche les numéros des lignes*
`find /N "juillet" find-data.txt`

## `findstr`
Similaire à `find` mais avec plus d'options  

`FINDSTR [/B] [/E] [/L] [/R] [/S] [/I] [/X] [/V] [/N] [/M] [/O] [/P] [/F:fichier] [/C:chaîne] [/G:fichier] [/D:liste de répertoires] [/A:attributs de couleur] [/OFF[LINE]] chaînes [[lecteur:][chemin]nom de fichier[
...]]`

*Recherche de plusieurs mots*
`findstr "Women Man" find-data.txt`

*Recherche de chaîne de caractères avec espaces*
`findstr /C:"The Man" find-data.txt`

*Recherche en début de ligne (qui commence par 15 dans l'exemple)*
`findstr /B "15" find-data.txt`

### Supporte un sous ensemble de *regex*
> Echapper avec `\` les caractères utilisable dans regex : `. * $ \ [ ] -`.  
> En plus des échappements de CMD avec `^` pour ` : & | ^ < > ( )`
- `.`
Joker: Une occurrence d’un caractère quelconque

- `*`
Zéro occurrence ou plus du caractère ou de la classe précédent

- `^`  
Emplacement : début de ligne

- `$`  
Emplacement : fin de ligne

- `[class]`  
Tout caractère compris dans la classe

- `[^class]`  
Tout sauf les caractères compris dans la classe

- `[x-y]`  
Tout caractère compris dans l’intervalle

- `\<xyz`  
Emplacement : début du mot

- `xyz\>`  
Emplacement : fin du mot

*Recherche en début de ligne avec regex `^`*  
`findstr ^^15 find-data.txt`

*Recherche en fin de ligne avec regex `$`*  
`findstr 1966$ find-data.txt`

*Recherche en début de mot avec regex `\^<`*  
`findstr \^<Wh find-data.txt`

*Recherche en fin de mot avec regex `\^>`*  
`findstr ri\^> find-data.txt`

*Recherche avec caractère joker `.` (remplace un seul caractère à la position du `.`)*  
`findstr .0 find-data.txt`

*Recherche avec caractère joker `*` (remplace plusieurs caractères à la position du `*`)*  
`findstr mm*e find-data.txt`

*Recherche avec une classe `[class]` et un caractère espace*  
*(`/C:"... ...."` car il y'a un espace dans la chaîne)*  
`findstr /R /C:"2[0-5] aout" find-data.txt`

*Recherche avec une classe d'exclusion `[^class]`*   
`findstr 1[^^0-9a-z] aout" find-data.txt`

### `pause`
Demande à l’utilisateur de presser une touche avant de poursuivre l’exécution  
`pause`

### `shift`
Décale tous les arguments  
`shift`

### `goto`
Sauter à une autre ligne  
`goto :eof`  
`goto fn`

# Les arguments
`%0` : nom de la commande  
`%1` : 1er argument  
`%2` : 2ème argument  
...    
`%*` : tous les arguments  
La commande `shift` permet de les décaler

```bat
@echo off
echo commande: %0
echo arguments: %1, %2, %3, %4
```

```
C:\>script A B C D
commande: script2
arguments: A, B, C, D
```

## Extension des arguments pour les noms de fichiers 
### %~fn
Nom complet du fichier  
`C:\utils\MyFile.txt`  

### %~dn  
Nom du disque  
`C:`  

### %~pn 
Dossier complet  
`\utils\`  

### %~dpn  
Lecteur et dossier  
`C:\utils\`  

### %~nn  
Nom sans extension  
`MyFile`  

### %~xn  
Uniquement l’extension  
`.txt`  

### %~nxn  
Nom et extension  
`MyFile.txt`  

### %~n  
Supprime les guillemets autour de l’argument  

### %~an  
Attributs du fichier  

### %~tn  
Date et heure du fichier  

### %~zn  
Taille du fichier  


# Instructions conditionnelles
La commande `IF` exécute des commandes en fonction d’une expression booléenne

```bat
IF [NOT] <cond> <command> [ELSE <command>]
```
- `cond` : condition (voir diapositives suivantes)
- `NOT` : permet d’inverser la condition
- `command` : une commande ou *un bloc de commandes entouré de `( )`*

> La commande suivant la commande ELSE est exécutée si la condition est fausse

## Bloc d'execution (`( )` équivalent à `{ }` en C)
```bat
if <cond> (
  <command1>
  <command2>
) else if <cond2> (
  <command3>
  <command4>
) else (
  <command5>
  <command6>
)
```

Avec blocs (avec `( )`):
- une ligne par commande

Sans bloc (sans `( )`):
- une seule ligne possible
- parenthèses parfois nécessaires 

## Exemples
```bat
if "Marcel"==%password% (
  echo OK
) else (
  echo KO
)
```
```bat
if "%1"=="/?" (
  echo Aide sur la commande
)
```

## Comparaison d'entiers
**`EQU`**
Egalité =

**`LSS`**
Plus petit (strictement) <

**`LEQ`**
Plus petit ou égal <=

**`GTR`**
Plus grand (strictement) >

**`GEQ`**
Plus grand ou égal >=

```bat
if %age% GEQ 18 (
  echo Majeur
)
```
```bat
if not %scoreJoueur% LEQ %scoreMax% (
  echo Win!
)
```

## `exist`
Pour savoir si un chemin existe
```bat
if exist "%cd%" (
  echo %cd% Existe
)
```

## `defined`
Pour savoir si une variable existe
```bat
if defined commission (
  set /A salary=%salary% + %commission%
)
```

## `errorlevel`
Pour se renseigner sur une erreur
- Si tout s’est bien passé, en général 0
- En cas d’erreur: un autre nombre, le code d’erreur
- Pas de code d’erreur pour toutes les commandes
- La variable `%errorlevel%` peut aussi être utilisée
```bat
if errorlevel 1 (
  echo The last command failed
)
```

## `AND` / `OR`
Il n'y a as d’opérateur permettant le ET et le OU logique entre plusieurs conditions.
On utilise alors des astuces:

### `AND`
```bat
:: Exemple ET logique

if %var1%==1 (
  if %var2%==1 (
    echo var1=1 ET var2=1
  )
)
```

### `OR`
```bat
:: Exemple OU logique
set tempvar=0

if %var1%==1 set tempvar=1
if %var2%==1 set tempvar=1

if %tempvar% EQU 1 (
  echo var1 OU var2 vaut 1
)
```

# Sauts et labels
Un script est exécuté ligne par ligne jusqu’à la fin du fichier

## `goto`
- Commande `goto` permet de sauter à une autre ligne
- La ligne de destination est précédée par un label l’identifiant
- Nom du label passé en argument à la commande `goto`
- Pour définir un label il faut précéder le nom du label par un caractère `:`
- L’argument `:eof` de la commande `goto` permet de terminer le script

```bat
@echo off

if not "%1"=="/?" (
  goto Suite
)
echo Aide de ce programme
echo ...

: Va à la fin du programme
goto :eof

:Suite
echo Bonjour!
pause
```

# Itérations
La commande `FOR` répète une commande pour une liste d'éléments

```bat
FOR %%<var> IN (<list>) DO <command>
```

`list`  
- Liste d'éléments à parcourir (nombre, textes, fichiers, ...)  
- Séparés par des espaces ou des virgules  

`var`  
- Variable définie dans la boucle 
- `%` doit être échappée donc `%%`
- Un seul caractère => casse importante
- A chaque itération, var contiendra l'élément `list[i]`
- Extension d'argument utilisable `%~fn`, `%~dn`, `%~pn`, ...

`command`
- Une commande ou un bloc de commandes (avec `( )`)

```bat
for %%C in (rouge bleu vert) do (
  echo Couleur %%C
)
```
```
Couleur rouge
Couleur bleu
Couleur vert
```

## Itération basé sur un compteur
Equivalent à `for(int i = begin; i < end; i += inc)` en C.

```bat
FOR /l %%<var> IN (<begin> <inc> <end>) DO <cmd>
```

> Attention à l'ordre, en C c'est `begin`, **`end`, `inc`** 
> En bat c'est `begin`, **`inc`, `end`**

`begin`
Nombre entier à attribuer à var à la 1ère itération

`inc`
Nombre entier à additionner à var à chaque itération

`end`
Nombre entier limite du compteur (inclus)

> Les nombres négatifs sont possibles

```bat
for /l %%A in (2 -3 -8) do (
  echo Valeur: %%A
)
```
```
Valeur: 2
Valeur: -1
Valeur: -4
Valeur: -7
```

## Syntaxe pour rechercher des fichiers
```bat
FOR %%<var> IN (<files>) DO <cmd>
```

`files`  
Nom du fichier avec des caractère génériques `*` ou `?`, entre parenthèses et guillemets doubles

```bat
for %%F in ("Chap4*.cmd") do (
  echo Script: %%~nF
)
```
```
Script: chap4-args
Script: chap4-for-folders
Script: chap4-for
Script: chap4-goto
...
```

## Syntaxe pour rechercher des dossiers
```bat
FOR /d [/r] %%<var> IN (<path>) DO <cmd>
```

`path`  
Le chemin du dossier où chercher  
Le **dernier** élément doit contenir un caractère générique `*` ou `?`

**L'option** `/r`  
Execute dans le dossier et sous dossier récursivement

**Non récursif**
```bat
for /d %%D in ("C:\Windows\Syst*") do (
  echo Dossier: %%D
)
```
```
Dossier: C:\Windows\System
Dossier: C:\Windows\System32
Dossier: C:\Windows\SystemApps
Dossier: C:\Windows\SystemResources
...
```

**Récursif**  
Recherche un fichier de manière récursive
```bat
for /r "C:\Program Files\" %%F in (g*.exe) do (
  echo Exe: %%F
)
```
```
Exe: C:\Program Files\Git\git-bash.exe
Exe: C:\Program Files\Git\git-cmd.exe
Exe: C:\Program Files\Git\bin\git.exe
Exe: C:\Program Files\Git\cmd\git-gui.exe ...
```

## Syntaxe pour *parser* chaque ligne d'un texte
```bat
FOR /f ["<options>"] %%<var> IN (<text>) DO <cmd>
```

`texte`  
Un fichier, un résultat d’une commande ou du texte

`options`  
Entre guillemets doubles  
Séparé par des espaces  
Parmis cette liste:

- `eol=c`
Caractère de début de ligne à ignorer (p. ex. commentaire).    
**Défaut: `;`**

- `skip=n`
Nombre de lignes en début de texte à ignorer.    
**Défaut: `0`**

- `delims=xyz`
Caractère(s) de séparation lors du découpage de chaque ligne en sous-chaînes.    
**Défaut: `espace`**

- `token=i,j-k*`
Numéro des sous-chaînes à affecter à une variable (1ère: 1).  
Individuellement `(i,j)` ou intervalle `(j-k)`.  
La 1ère est affecté à `<var>`, les suivantes aux variables nommées avec les lettres suivantes.  
`*` affecte le reste de la ligne à la prochaine variable.  
**Défaut: `1`**

*CP.csv*
```
Prénom;Nom;Classe;Note;Remarque
Alice;Dubois;a;5.5
Jean;Dupont;a;4;A surveiller
Bob;Robert;b;2.5;Redoublant
Corine;Droz;b;5
```

```bat
for /f "skip=1 tokens=1,2,4* delims=;" %%G in (CP.csv) do (
  :: G = Prénom, H = Nom, I = Note, J = Remarque
  echo %%H %%G : %%I %%J
)
```

```
Dubois Alice : 5.5
Dupont Jean : 4  A surveiller
Robert Bob : 2.5  Redoublant
Droz Corine : 5
```

## Sous-commande
On met la sous commande à exécuter entre guillemets simples
*(par exemple: `('dir /b')`)*

```bat
setlocal ENABLEDELAYEDEXPANSION

set count=1
:: 'dir /b' entre guillement pour l'executer
for /f "tokens=*" %%G in ('dir /b') do (
  echo !count! : %%G
  set /A count+=1
)
```
```
1 : chap4-args.cmd
2 : chap4-for-folders.cmd
3 : chap4-for-text.cmd
4 : chap4-for.cmd
...
```

## A noter
**Les variables utilisées dans le bloc <command> sont évaluées avant la 1ère itération**
```bat
set rep=0
for /l %%A in (1 1 4) do (
  set /A rep=%%A+%%A
  echo %%A+%%A = %rep%
)
```
`set /A rep=%%A+%%A`est évaluer avant la première itération et vaut donc `0`
```
1+1 = 0
2+2 = 0
3+3 = 0
4+4 = 0
```
**La commande `setlocal ENABLEDELAYEDEXPANSION` permet d'évaluer les variables à chaque itération**
```bat
setlocal ENABLEDELAYEDEXPANSION

set rep=0
for /l %%A in (1 1 4) do (
  set /A rep=%%A+%%A

  :: !rep! et non %rep% pour forcer l'évaluation
  echo %%A+%%A = !rep!
)
```
```
1+1 = 2
2+2 = 4
3+3 = 6
4+4 = 8
```

# Traitement de chaînes de caractères

## Extraire une partie d'une chaîne de caractères
`%variable:~skip%`  
ou  
`%variable:~skip,keep%`

`skip`  
Nombre de caractères à ignorer

`keep`  
Nombre de caractères à conserver 

> On utilise les nombre négatifs pour commencer depuis la fin  
> On commence par le début par défaut

```bat
set texte=0123456789abcdef
echo 1. %texte:~2%
echo 2. %texte:~2,5%
echo 3. %texte:~2,-1%
echo 4. %texte:~-3,2%
echo 5. %texte:~-3,-2%
echo 6. %texte:~-6,-2%
echo 7. %texte:~-6,2%
```

```
1. 23456789abcdef
2. 23456
3. 23456789abcde
4. de
5. d
6. abcd
7. ab
```

### Utiliser `skip` et `keep` avec de variables
Il y'a plusieurs conditions pour faire ceci:
- Le faire dans un script
- Le faire précéder par la commande `call`

> `call` exécute la commande qui suit dans un nouveau CLI après avoir évalué les variables

```bat
set text=0123456789abcdef
set a=2
set b=3

:: %% en début et fin: échappements pour l’appel à call
:: Dans le nouveau CLI après call: set newText=%text:~2,3%
call set newText=%%text:~%a%,%b%%%
echo %newText%
```

## `set`, `find`, `replace`
Une syntaxe de la commande `set` permet de remplacer des caractères d’une variable

`SET %<var>:<find>=[<replace>]%`

`var`  
**Nom de la variable**

`find`  
**Texte à rechercher**  
Si find est précédé de `*`: remplace la 1ère occurrence de find et tous les caractères précédents

`replace`  
**Texte qui va remplacer toutes les occurrences de `find`**  
Si replace est vide: efface au lieu de remplacer

```bat
set text=12345abcabc

set result1=%text:12345=Hello %
set result2=%text:ab=xy%
set result3=%text:ab=%
set result4=%text:*ab=ZZZ%
set result5=%text:*5=%

echo 1. %result1%
echo 2. %result2%
echo 3. %result3%
echo 4. %result4%
echo 5. %result5%
```

```
1. Hello abcabc
2. 12345xycxyc
3. 12345cc
4. ZZZcabc
5. abcabc
```









