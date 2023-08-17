# 베이스 이미지
FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y dumb-init

RUN apt-get install -y mariadb-client curl php7.4-fpm php-mysql

# wp-cli 설치, 명령줄에서 사용하기 위해 권한 변경
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin && \
	ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php

COPY ./conf/www.conf /etc/php-fpm.d/www.conf
COPY ./tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

RUN mkdir -p /var/www/html/wordpress && \
	chown -R www-data:www-data /var/www/

# 3306, 9000 포트로 내부에서만 연결 가능
EXPOSE 3306 9000

WORKDIR /var/www/html/wordpress

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["sh", "/setup.sh"]

# CMD ["mysqld"]

# CMD ["sh", "/setup.sh"]