# Images utilisées
On utilise la version LTS de node car c'est la version stable. On se base également sur la version `alpine` des images car elles sont plus légères.

# Backend
```docker
FROM node:lts-alpine AS build
COPY . .
RUN npm i
RUN npm run build

FROM node:lts-alpine AS runtime
COPY --from=build ./node_modules ./node_modules
COPY --from=build ./*.js .
CMD node server.js
```
Dans le stage `build` on va simplement installer les modules nodes requis par l'application (listés dans `package.json`), on va ensuite build notre application en transpilant notre code typescript en javascript avec la commande `npm run build` (=== commande `tsc`)  
Ensuite dans le stage `runtime` on va copier dans notre container le dossier `node_modules` qui contient les paquets requis au fonctionnement de notre application ainsi que les fichier `*.js` qui ont été produit par `npm run build`. Puis on lance notre application avec `node`.

# Frontend
```
FROM node:lts-alpine AS build
COPY . .
RUN npm i
RUN npm run build

FROM httpd:alpine AS runtime
COPY --from=build ./dist /usr/local/apache2/htdocs/
```

Dans le stage `runtime` on va utiliser apache2 (httpd) afin de servir notre site internet via un serveur web.  
Le dossier où se trouve les fichiers servis par le serveur apahce2 est dans `/usr/local/apache2/htdocs/` (dans le container), on copie alors le contenu du dossier `/dist` produit par `npm run build` pour servir ces fichiers via le serveur web.

# docker-compose.yml
```yml
version: "3.9"

services:
  front:
    image: tp-front
    networks:
      - back-front-net
    ports:
      - 80:80
  back:
    image: tp-back
    environment:
      - MONGODB_CONNECTION_URL=mongodb://mongo:27017/pizzas
    ports:
      - 8080:8080
    networks:
      - back-front-net
      - mongo-net
  mongo:
    image: mongo
    volumes:
      - mongo-volume:/data/db
    networks:
      - mongo-net
    ports:
      - 27017:27017

volumes:
  mongo-volume:

networks:
  mongo-net:
  back-front-net:
```

On déclare 3 container avec les images suivantes:
- `tp-front`
  - Ports mapping (host_port:container_port): 80:80
- `tp-back`
  - Ports mapping (host_port:container_port): 8080:8080
- `mongo`
  - Ports mapping (host_port:container_port): 27017:27017

On a également besoin de 2 network:
- Un network qui lie le backend avec la base de données mongodb (`mongo-net`)
- Un network qui lie le front end avec le backend (`back-front-net`)

Et finalement on utilise un volume pour notre base de données mongodb (`mongo-volume`)

