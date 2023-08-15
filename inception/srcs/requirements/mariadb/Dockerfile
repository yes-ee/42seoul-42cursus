# 베이스 이미지
FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	# apt-get install dumb-init -y
	apt-get install mariadb-server mariadb-client

COPY ./tools/setup.sh /setup.sh

# 3306 포트로 내부에서만 연결 가능
EXPOSE 3306

# ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["sh", "/setup.sh"]