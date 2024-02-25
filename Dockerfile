FROM alpine:latest

RUN apk update && apk add --no-cache \
    gcc \
    make \
    git \
    binutils \
    musl-dev

WORKDIR /mnt

CMD ["/bin/sh"]
