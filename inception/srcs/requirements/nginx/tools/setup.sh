#!/bin/sh

# check if wordpress exists
while [ ! -d "/var/www/wordpress" ]
do
    echo "wait wordpress downloads...\n"
done

if [ -d "/var/www/wordpress" ]
then
	echo "wordpress download ok! \n"
	chown -R nginx:nginx /var/www/wordpress
	echo "change user:group root->nginx !!"
fi

exec /usr/sbin/nginx -g "daemon off;" 
