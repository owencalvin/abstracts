# TP Docker

## Partie sans Docker-Compose

### Créer les Images Docker

Dans ce répertoire, vous trouverez 2 dossier (Backend / Frontend).

Pour chaqu'un des dossiers, créez une image (Dockerfile) à la racine.

Pour la partie Backend, faites des recherches pour voir comment créer un Dockerfile pour une application Node.js.
Vous devez créer un Dockerfile multistage qui compilera les sources typescript dans le premier stage et qui lancera l'application dans le 2ème stage.

Pour la partie Frontend faites des recherches pour pouvoir créer un image Docker à partir d'une application Vuejs

Pour les 2 images, essayez de rendre l'image la plus petite possible grâce aux multistages.

Veillez également à ce que vos images puissent être construites sur une machine avec uniquement Docker d'installé (Pas de compilation en dehors du Dockerfile)

### Créer les containers

Créez 3 containers :

1. Un container mongodb (Recherchez l'image à utiliser)
2. Un container Frontend (Avec l'image que vous avez créé)
3. Un container Backend (Avec l'image que vous avez créé)

### Ouvrir les ports / network / volumes

Gérez les networks et les ports ouverts afin que :
* Votre navigateur puisse communiquer avec le container frontend
* Votre navigateur puisse accéder au container backend (utilisez un logiciel tel que insomnia ou postman).
* Le container backend puisse accéder au container mongodb
* Le container mongodb ne soit pas accessible depuis l'extérieur (Seulement depuis backend)

Créez un volume et configurez le de manière à sauvegarder les données de mongodb

## Partie avec Docker-Compose

Adaptez votre projet pour utiliser Docker-Compose : créez les containers, liez les ports, volumes, networks, etc...

## Documents à rendre

Les 2 dossiers avec :

* 2 Dockerfiles pour le frontend et le backend
* Toutes les commandes utilisées avec une petite explication
* Fichier docker-compose.yml
* Autres fichiers utilisés pour la configuration (.env par exemple)
* Références vers le(s) éventuel(s) Dockerfile dont vous vous êtes inspirés
