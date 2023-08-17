# 베이스 이미지
FROM debian:bullseye

# ENV MYSQL_ROOT_PASSWORD=1234

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y dumb-init dos2unix

RUN apt-get install -y mariadb-server mariadb-client

# 소유자, 그룹을 mysql로 변경
RUN mkdir -p /var/run/mysqld && \
	chown -R mysql:mysql /var/run/mysqld &&\
	chmod 777 /var/run/mysqld

# db, user, 권한 설정
COPY ./tools/setup.sh /setup.sh
# 기본 설정
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

RUN dos2unix /setup.sh

# 3306 포트로 내부에서만 연결 가능
EXPOSE 3306

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

# CMD ["mysqld"]

CMD ["sh", "/setup.sh"]