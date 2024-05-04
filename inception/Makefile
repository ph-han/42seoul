DOCKER_COMPOSE_PATH = /home/phan/inception/srcs/docker-compose.yml
IMAGES_LS = srcs-nginx srcs-wordpress srcs-mariadb
VOLUME_LS = srcs_db_volume srcs_web_volume

all: up

up: $(DOCKER_COMPOSE_PATH)
	mkdir -p $(HOME)/docker/db
	mkdir -p $(HOME)/docker/wordpress
	docker compose -f $(DOCKER_COMPOSE_PATH) up -d

down:
	docker compose -f $(DOCKER_COMPOSE_PATH) down

clean: down
	docker rmi $(IMAGES_LS)
	docker volume rm $(VOLUME_LS)

fclean: clean
	docker system prune -a -f
	rm -rf $(HOME)/docker/db
	rm -rf $(HOME)/docker/wordpress

re: fclean all

.PHONY: all clean fclean bonus re
