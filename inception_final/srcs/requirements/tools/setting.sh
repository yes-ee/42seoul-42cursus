#!/bin/bash

if [ ! -d /home/yeselee/data/wordpress ]; then
    mkdir -p /home/yeselee/data/wordpress
fi

if [ ! -d /home/yeselee/data/mariadb ]; then
    mkdir -p /home/yeselee/data/mariadb
fi

echo "127.0.0.1 yeselee.42.fr" | sudo tee -a /etc/hosts