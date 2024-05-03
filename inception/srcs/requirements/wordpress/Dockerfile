FROM alpine:3.18

LABEL maintainer="phan@student.42seoul.kr"
LABEL version="0.0.1"
LABEL description="my mariadb image"

RUN apk update
RUN apk add tzdata \
		php82 php82-fpm php82-opcache fcgi php82-cgi php82-pdo_mysql php82-mysqli --no-cache

# RUN cp /usr/share/zoneinfo/$TZ /etc/localtime
# RUN echo $TZ > /etc/timezone

WORKDIR /var/www
RUN wget https://wordpress.org/latest.tar.gz && \
tar -xvf latest.tar.gz wordpress && \
rm latest.tar.gz

COPY ./conf/php-fpm.conf /etc/php82/php-fpm.conf
COPY ./conf/wp-config.php /var/www/wordpress/wp-config-sample.php
RUN mv /var/www/wordpress/wp-config-sample.php /var/www/wordpress/wp-config.php

ENTRYPOINT [ "/usr/sbin/php-fpm82", "-F" ]





