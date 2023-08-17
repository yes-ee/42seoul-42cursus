# 베이스 이미지
FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y dumb-init

# RUN apt-get install -y mariadb-server mariadb-client

# 3306 포트로 내부에서만 연결 가능
EXPOSE 3306, 9000

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

# CMD ["mysqld"]

# CMD ["sh", "/setup.sh"]