all: up

up:
	@sh ./srcs/requirements/tools/setting.sh
	@echo volume, hosts setted!
	docker-compose -f ./srcs/docker-compose.yml up -d --build

down:
	docker-compose -f ./srcs/docker-compose.yml down --volumes

clean:
	sudo docker-compose -f srcs/docker-compose.yml down -v --rmi all --remove-orphans

fclean: clean
	sudo rm -rf /home/yeselee/data
	sudo docker system prune --volumes --all --force

re:
	@make fclean
	@make all

.PHONY: all build down clean fclean re
