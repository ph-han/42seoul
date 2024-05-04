FROM alpine:3.18

LABEL maintainer="phan@student.42seoul.kr"
LABEL version="0.0.1"
LABEL description="my mariadb image"

RUN apk update
RUN apk add mariadb mariadb-client --no-cache

COPY ./tools/setup.sh /tmp/
COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

RUN chmod +x /tmp/setup.sh
ENTRYPOINT [ "/tmp/setup.sh" ]
