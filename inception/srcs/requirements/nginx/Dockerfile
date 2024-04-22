FROM alpine:3.18

LABEL maintainer="phan@student.42seoul.kr"
LABEL version="0.0.1"
LABEL description="my nginx image"

RUN apk update
RUN apk add nginx openssl

COPY ./conf/default.conf /etc/nginx/httpd.d/default.conf
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# RUN openssl req -new -x509 -days 365 -nodes -keyout test.key -out test.crt

ENTRYPOINT [ "/usr/sbin/nginx", "-g", "daemon off;" ]
