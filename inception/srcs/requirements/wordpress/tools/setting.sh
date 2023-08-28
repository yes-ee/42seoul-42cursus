#!/bin/sh

while ! mysqladmin -h$DB_HOST -u$DB_USER -p$DB_PASSWORD ping >/dev/null 2>&1; do
  sleep 5
done

wp-cli core download --allow-root
wp-cli config create --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PASSWORD --dbhost=$DB_HOST --allow-root
wp-cli core install --url=$DOMAIN_NAME/wordpress --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
wp-cli user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=subscriber --allow-root
wp-cli theme install astra --allow-root --activate

exec /usr/sbin/php-fpm7.4 -F