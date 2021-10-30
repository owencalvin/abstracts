FROM node AS build
COPY . .
run npm i
run npm run build

FROM node AS runtime
COPY --from=build ./node_modules ./node_modules
COPY --from=build ./*.js .
CMD node server.js
