#!/bin/sh

if [ ! -d "/run/mysqld" ]; then
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
else
	echo "already exist"
fi

if [ ! -d "/var/lib/mysql/mysql" ]; then
	echo "Create database..."
	mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null
 #   echo "mysql db installing..."
# done

# start mariadb
#	echo "Create database - start mariadb..."
# /usr/bin/mariadbd-safe --nowatch

    # check if mariadb is running
# if pgrep -x /usr/bin/mariadbd > /dev/null
#then
    # create root user with remote access
    echo "Create database - configure root user..."

 #   sleep 1

    mysqld --user=mysql --bootstrap <<-EOF
			USE mysql;
			
			FLUSH PRIVILEGES;
			DELETE FROM mysql.user WHERE user='';
			
			CREATE DATABASE IF NOT EXISTS wordpress;
			CREATE USER IF NOT EXISTS 'phan'@'%' IDENTIFIED BY '1234';
			GRANT ALL PRIVILEGES ON wordpress.* TO 'phan'@'%';

			# create user root with access from any host
			CREATE USER 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
			GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;

			FLUSH PRIVILEGES;
			EOF

    echo "Create database - OK"
else
	echo "already exist database"
fi
echo "maria on."

mysqld_safe --user=mysql

#else
#    echo "Create database - FAILED"
#fi
