# 아래의 조건대로 이미지를 생성

# 사용할 베이스 이미지
FROM debian:bullseye

# nginx 설치
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install nginx -y

# 이 이미지가 해당 포트를 외부로 공개할 것임
# 컨테이너에서 오픈하는 포트 의미
# docker run -p로 포트를 명시하지 않으면 pwd호스트 포트와 자동으로 연결되지 않음
# expose : 호스트 내부에서만 포트 오픈
# ports : 호스트 포트와 컨테이너 포트 연결
# nginx의 listen 포트와도 맞아야 함
# EXPOSE 80

# 셀프 ssl 인증서 발급 위한 openssl 설치
RUN apt-get install openssl -y

COPY ./conf/default.conf /etc/nginx/http.d/default.conf

# 인증에 필요한 키와 인증서 발급
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=inception" \
-keyout inception.dev.key \
-out inception.dev.crt 

# RUN     openssl genrsa -out server.key 4096 
# RUN     openssl req -new -key server.key -subj "/C=KR/ST=Seoul/O=42Seoul/OU=GON/CN=inception" -out server.csr
# RUN     openssl req -x509 -in server.csr -key server.key -out server.crt
# RUN     mv server.crt /etc/ssl/certs/
# RUN     mv server.csr server.key /etc/ssl/private

# 443 port 열기
EXPOSE 443

# nginx 명령어 실행
# -g로 nginx의 글로벌 설정 지정
# daemon off : 컨테이너에서 실행될 때 컨테이너가 백그라운드에서 종료되지 않고 실행
ENTRYPOINT     ["nginx", "-g", "daemon off;"]
