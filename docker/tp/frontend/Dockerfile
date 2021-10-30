FROM node:16.13.0 AS build
COPY . .
run npm i
run npm run build

FROM httpd AS runtime
COPY --from=build ./dist /usr/local/apache2/htdocs/
# COPY ./dist /usr/local/apache2/htdocs/
