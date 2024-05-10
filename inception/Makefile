DOCKER_COMPOSE_PATH = ./srcs/docker-compose.yml
IMAGES_LS = nginx:phan wordpress:phan mariadb:phan
VOLUME_LS = srcs_db_volume srcs_web_volume

all: up

up: $(DOCKER_COMPOSE_PATH)
	mkdir -p /home/phan/data/db
	mkdir -p /home/phan/data/wordpress
	docker compose -f $(DOCKER_COMPOSE_PATH) up -d

down:
	docker compose -f $(DOCKER_COMPOSE_PATH) down

clean: down
	docker rmi $(IMAGES_LS)
	docker volume rm $(VOLUME_LS)

fclean: clean
	docker system prune -a -f
	rm -rf /home/phan/data/db
	rm -rf /home/phan/data/wordpress

re: fclean all

.PHONY: all clean up down flcean up re
