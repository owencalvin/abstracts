FROM alpine AS build
RUN \
  apk add --no-cache \
  g++ \
  make
# 1st . is host, 2nd on the cointainer
COPY . .
RUN make

FROM alpine AS runtime
RUN apk add --no-cache libstdc++
# Copy the compiled app using make to the current container
COPY --from=build app app
CMD ./app
