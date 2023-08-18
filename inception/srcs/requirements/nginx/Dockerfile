# 아래의 조건대로 이미지를 생성

# 사용할 베이스 이미지
FROM debian:bullseye

# RUN : 도커 이미지를 빌드할 때 실행되는 명령어
# dumb-init 설치
RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y dumb-init

# nginx, openssl 설치
RUN apt-get install -y nginx openssl

# 인증에 필요한 키와 인증서 발급
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=inception" -keyout /etc/ssl/private/inception.dev.key -out /etc/ssl/certs/inception.dev.crt

# 이 이미지가 해당 포트를 외부로 공개할 것임
# 컨테이너에서 오픈하는 포트 의미
# docker run -p로 포트를 명시하지 않으면 pwd호스트 포트와 자동으로 연결되지 않음
# expose : 호스트 내부에서만 포트 오픈
# ports : 호스트 포트와 컨테이너 포트 연결
# nginx의 listen 포트와도 맞아야 함

# 443 port 열기
EXPOSE 443

# conf 파일 nginx에 적용
# 443 port로만 접속 가능하게 설정된 conf 파일
COPY ./conf/default.conf /etc/nginx/sites-enabled/default

# nginx 명령어 실행
# -g로 nginx의 글로벌 설정 지정
# daemon off : 컨테이너에서 실행될 때 컨테이너가 백그라운드에서 종료되지 않고 실행

# CMD : 이미지에서 컨테이너를 생성하여 최초로 실행될 때 수행됨
# ENTRYPOINT : 이미지에서 컨테이너를 생성하여 최초로 실행될 때 수행됨
# 차이 - CMD는 docker run 할 때 다른 옵션을 주면 변경 가능, ENTRYPOINT는 무조건 실행
# CMD ["nginx", "-g", "daemon off;"]
# ENTRYPOINT ["nginx", "-g", "daemon off;"]

# dumb-init 먼저 실행
ENTRYPOINT	["/usr/bin/dumb-init", "--"]
# CMD ["echo", "hello"]
CMD ["/usr/sbin/nginx", "-g", "daemon off;"]

# 실행방법
# docker build . -t nginximg
# docker run -it -d -p 80:80 -p 443:443 --name nginx nginximg
# docker exec -it nginx bash