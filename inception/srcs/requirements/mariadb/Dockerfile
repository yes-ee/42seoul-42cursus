# 베이스 이미지
FROM debian:bullseye

# ENV MYSQL_ROOT_PASSWORD=1234

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y dumb-init

RUN apt-get install mariadb-server

COPY ./tools/setup.sh /setup.sh

# 3306 포트로 내부에서만 연결 가능
EXPOSE 3306

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["mariadb"]

# CMD ["sh", "/setup.sh"]