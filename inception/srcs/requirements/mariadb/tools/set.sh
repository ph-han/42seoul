# check if database exists
echo "Create database..."
mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null

while [! -d "/var/lib/mysql/mysql" ]
do
    echo "mysql db installing..."
done

# start mariadb
echo "Create database - start mariadb..."
/usr/bin/mariadbd-safe --nowatch

    # check if mariadb is running
if pgrep -x /usr/bin/mariadbd > /dev/null
then
    # create root user with remote access
    echo "Create database - configure root user..."

    sleep 1

    mysql <<-EOF
			USE mysql;

			# create user root with access from any host
			CREATE USER 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
			GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;

			FLUSH PRIVILEGES;
			EOF
    # add timezone info to db
    echo "Create database - add timezone info..."
    mysql_tzinfo_to_sql /usr/share/zoneinfo | mysql mysql

    mysql -e "CREATE DATABASE IF NOT EXISTS wordpress;"

    echo "Create database - OK"
else
    echo "Create database - FAILED"
fi
