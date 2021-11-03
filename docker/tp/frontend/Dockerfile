FROM node:lts-alpine AS build
COPY . .
RUN npm i
RUN npm run build

FROM httpd:alpine AS runtime
COPY --from=build ./dist /usr/local/apache2/htdocs/
