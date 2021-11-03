FROM node:lts-alpine AS build
COPY . .
RUN npm i
RUN npm run build

FROM node:lts-alpine AS runtime
COPY --from=build ./node_modules ./node_modules
COPY --from=build ./*.js .
CMD node server.js
