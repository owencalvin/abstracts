FROM node AS build
COPY . .
run npm i
run npm run build

FROM node AS runtime
COPY --from=build ./*.js .
CMD npm run start
