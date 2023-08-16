# /bin/bash

echo hello;

# 해당 디렉토리가 존재하지 않는 경우
if [ ! -d /var/lib/mysql/${DB_NAME} ]; then

	# 초기화
	# 사용자와 데이터 디렉토리 지정
	mysql_install_db --datadir=/var/lib/mysql

	service mariadb start

	# 데이터베이스 생성
	mysql -uroot -e "CREATE DATABASE $DB_NAME;"
	
	mysql -uroot -e "USE $DB_NAME;"
	
	# 해당 데이터베이스를 이용할 유저 생성(%는 모든 외부 ip에서 접근 가능)
	mysql -uroot -e "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PWD';"
	
	# 유저에게 권한 부여 (해당 디비의 모든 테이블에 대한 권한 부여함)
	mysql -uroot -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO $DB_USER@'%';"

	mysql -uroot -e "FLUSH PRIVILEGES;"

	service mariadb stop

else
	echo "MariaDB setted"

fi

mysqld --skip-networking 