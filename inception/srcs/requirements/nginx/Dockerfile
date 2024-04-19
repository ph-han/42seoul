FROM alpine:3.18

LABEL maintainer="phan@student.42seoul.kr"
LABEL version="0.0.1"
LABEL description="my nginx image"

RUN apk update
RUN apk add nginx openssl

ENTRYPOINT [ "/usr/sbin/nginx", "-g", "daemon off;" ]
