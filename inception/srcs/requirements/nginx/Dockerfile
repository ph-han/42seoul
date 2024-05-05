FROM alpine:3.18

LABEL maintainer="phan@student.42seoul.kr"
LABEL version="0.0.1"
LABEL description="my nginx image"

RUN apk update
RUN apk add dumb-init nginx openssl tzdata

# RUN cp /usr/share/zoneinfo/$TZ /etc/localtime
# RUN echo $TZ > /etc/timezone

COPY ./conf/wordpress.conf /etc/nginx/http.d/default.conf
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# openssl tls1.3 적용
RUN mkdir -p /etc/nginx/ssl
WORKDIR /etc/nginx/ssl
RUN openssl req \
	-newkey rsa:2048 -nodes -keyout cert.key \
	-x509 -days 365 -out cert.crt \
	-subj "/C=KR/ST=Seoul/L=Gangnam/O=42/OU=phan/CN=phan.42.fr"

COPY ./tools/setup.sh /tmp/setup.sh
RUN chmod +x /tmp/setup.sh

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "/tmp/setup.sh" ]
