# 아래의 조건대로 이미지를 생성

# 사용할 베이스 이미지
FROM debian:bullseye

# nginx 설치
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install nginx -y

# 이 이미지가 해당 포트를 외부로 공개할 것임
# 컨테이너에서 오픈하는 포트 의미
# docker run -p로 포트를 명시하지 않으면 호스트 포트와 자동으로 연결되지 않음
# expose : 호스트 내부에서만 포트 오픈
# ports : 호스트 포트와 컨테이너 포트 연결
# nginx의 listen 포트와도 맞아야 함
# EXPOSE 80

RUN apt-get install openssl -y

COPY    ./conf/default /etc/nginx/http.d/default.conf
# RUN     mv default /etc/nginx/sites-available/default

RUN     openssl genrsa -out server.key 4096 
RUN     openssl req -new -key server.key -subj "/C=KR/ST=Seoul/O=42Seoul/OU=GON/CN=inception" -out server.csr
RUN     openssl req -x509 -in server.csr -key server.key -out server.crt
RUN     mv server.crt /etc/ssl/certs/
RUN     mv server.csr server.key /etc/ssl/private

# ENTRYPOINT     ["nginx", "-g", "daemon off;"]

EXPOSE 443