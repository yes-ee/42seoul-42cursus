#!/bin/sh

if [ ! -d "/var/lib/mysql/$DB_NAME" ]; then
  mysql_install_db --datadir=/var/lib/mysql >/dev/null
  mysqld --bootstrap << EOF
use mysql;
flush privileges;
create database $DB_NAME;
create user '$DB_USER'@'%' identified by '$DB_PASSWORD';
grant all privileges on $DB_NAME.* to '$DB_USER'@'%';
flush privileges;
EOF
fi

exec mysqld --datadir=/var/lib/mysql --bind-address=0.0.0.0