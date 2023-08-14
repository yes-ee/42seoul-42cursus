# 컨테이너 리스트 보기
docker ps

# 해당 컨테이너 아이디를 가진 컨테이너의 bash 쉘을 실행
# -it : 터미널 입력을 위한 옵션
docker exec -it 0ba436eccbc5 /bin/bash

# mariadb 라는 서비스명을 가진 컨테이너의 bash 쉘을 실행 -> mariadb 컨테이너에 원하는 명령 전달 가능
# docker-compose.yml 파일이 존재하는 곳에서만 실행 가능
docker-compose exec mariadb /bin/bash

# 컨테이너 포트와 호스트 포트 개념 정리
# -p 80:3306
# 호스트의 80 포트와 컨테이너의 3306 포트를 연결
# -> 외부에서 호스트의 80 포트에 접속 -> 80포트는 컨테이너의 3306 포트와 연결되어 있음 -> 80 포트에 접속 == 컨테이너의 3306 포트에 접속
# https://blog.naver.com/alice_k106/220278762795

