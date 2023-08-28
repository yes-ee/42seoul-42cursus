FROM debian:bullseye

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y dumb-init mariadb-server mariadb-client vim

RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod 777 /var/run/mysqld

COPY ./tools/setting.sh /setting.sh

RUN chmod +x setting.sh

RUN rm -f /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["sh", "/setting.sh"]