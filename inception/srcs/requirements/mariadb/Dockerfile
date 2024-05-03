FROM alpine:3.18

LABEL maintainer="phan@student.42seoul.kr"
LABEL version="0.0.1"
LABEL description="my mariadb image"

RUN apk update
RUN apk add mariadb mariadb-client --no-cache

# RUN cp /usr/share/zoneinfo/$TZ /etc/localtime
# RUN echo $TZ > /etc/timezone

COPY ./tools/set.sh /tmp/set.sh
COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

RUN chmod +x /tmp/set.sh
# RUN sh /tmp/set.sh

ENTRYPOINT [ "/tmp/set.sh" ]
# ETRYPOINT [ "/usr/bin/mysqld_safe", "--user=root" ]
