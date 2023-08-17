#!/bin/bash

echo hello;

if [ ! -c /var/www/html/index.php ]; then
echo new wordpress;
# 워드프레스 설치, 한국어버전 
wp core download --allow-root --locale=ko_KR
# mariadb에 연결할 데이터베이스 이름, 유저명, 유저패스워드, 호스트=연결할 컨테이너 명
wp config create --allow-root --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PWD --dbhost=$DB_HOST
# 워드프레스 설치
wp core install --allow-root --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL
# 유저 계정 생성
# author : 본인 글만 관리 가능
wp user create --allow-root $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=author
fi

php-fpm7.4 -F