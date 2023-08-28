#!/bin/sh

openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=GON/CN=yeselee.42.fr" \
	-keyout "/etc/ssl/private/inception.dev.key" \
	-out "/etc/ssl/certs/inception.dev.crt" 2>/dev/null

exec nginx -g 'daemon off;'