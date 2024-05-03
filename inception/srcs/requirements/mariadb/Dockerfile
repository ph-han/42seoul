FROM alpine:3.18

LABEL maintainer="phan@student.42seoul.kr"
LABEL version="0.0.1"
LABEL description="my mariadb image"

RUN apk update
RUN apk add mariadb mariadb-client --no-cache

# RUN cp /usr/share/zoneinfo/$TZ /etc/localtime
# RUN echo $TZ > /etc/timezone

# 초기 SQL 스크립트 복사
COPY ./tools/set.sh /tmp/set.sh
COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY ./conf/init.sql /docker-entrypoint-initdb.d/

# 컨테이너 시작 시 초기화 스크립트 실행
# RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql
RUN sleep 1
RUN chmod +x /tmp/set.sh
RUN sh /tmp/set.sh

# ENTRYPOINT [ "/bin/sh" ]
ENTRYPOINT [ "/usr/bin/mysqld_safe", "--user=root" ]
