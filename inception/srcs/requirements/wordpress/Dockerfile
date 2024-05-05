FROM alpine:3.18

LABEL maintainer="phan@student.42seoul.kr"
LABEL version="0.0.1"
LABEL description="my mariadb image"


RUN echo "http://dl-cdn.alpinelinux.org/alpine/v3.13/community" >> /etc/apk/repositories
RUN apk update

RUN apk add dumb-init fcgi curl php7 \
        php7-fpm \
        php7-opcache \
        php7-gd \
        php7-mysqli \
        php7-zlib \
        php7-curl \
        php7-json \
        php7-phar \
        php7-mbstring \
        php7-xml \
        php7-simplexml
RUN curl -o /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x /usr/local/bin/wp


COPY ./conf/php-fpm.conf /etc/php7/php-fpm.conf
COPY ./conf/www.conf /etc/php7/php-fpm.d/www.conf
COPY ./tools/setup.sh /tmp/
RUN chmod +x /tmp/setup.sh

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "/tmp/setup.sh" ]
# ENTRYPOINT [ "/bin/sh" ]





