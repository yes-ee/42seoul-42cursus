all:
	docker-compose -f ./srcs/docker-compose.yml up -d

# container, networks 삭제
down: 
	docker-compose -f ./srcs/docker-compose.yml down

clean: down
	docker system prune -a

# --build : 변경된 이미지 다시 빌드
re: clean
	docker-compose -f ./srcs/docker-compose.yml up -d --build