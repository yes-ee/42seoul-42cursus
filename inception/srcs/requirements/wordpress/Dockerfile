FROM debian:bullseye

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y dumb-init curl mariadb-client php7.4-fpm php-mysql

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin && \
    ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp-cli

RUN mkdir -p /var/www/html/wordpress /run/php && \
    usermod -G www-data -a www-data && \
    chown -R www-data:www-data /var/www/

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY ./tools/setting.sh /setting.sh

RUN chmod +x setting.sh

WORKDIR /var/www/html/wordpress

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["sh", "/setting.sh"]
