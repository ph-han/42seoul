#!/bin/sh

if [ ! -f /var/www/wordpress/index.php ]; then
	cd /var/www/wordpress
	wp core download  --locale=ko_KR
	echo "Download ok"
	wp config create  --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PASSWORD --dbhost=$WORDPRESS_DB_HOST
	wp db create
	wp core install --url=phan.42.fr --title="Phan's Website" --admin_user=phan --admin_password=phan --admin_email=phan@wp-cli.org
	wp user create hyuim hyuim@example.com --role=author --user_pass=1234

	chown -R nobody:nobody /var/www/wordpress 
else
	echo "Wordpress is already download."
fi


exec /usr/sbin/php-fpm7 -F
