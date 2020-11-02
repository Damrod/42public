FROM debian:buster
#for phpmyadmin admin username: root passwd:${DB_PASS} \
#for phpmyadmin wordpress username: wordpress passwd:${WP_PASS} \
#for wordpress username: aollero- password:123 (hardcoded in wp-config-sample.php)
# to build: docker build --tag ft_server:1.0 .
# to run in dettached mode: docker container run --rm -d -p 443:443 --name ft_server ft_server:1.0
# to look inside the container: docker exec -it ft_server bash
ENV DB_PASS=123
ENV WP_PASS=123
ENV TEMPDIR=tmp.123
# to turn autoindex on: docker container run --rm -d -p 443:443 --name ft_server -e AUTOINDEX=on ft_server:1.0
# to check that autoindex is on go to https://phpmyadmin.localhost:443/vendor/ and see the listing
# to check that autoindex is off go to https://phpmyadmin.localhost:443/vendor/ and do not see the listing
ENV AUTOINDEX=off
ADD https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz \
	https://wordpress.org/latest.tar.gz /tmp/${TEMPDIR}/
COPY srcs/sites-available /etc/nginx/sites-available
COPY srcs/wordpress.sql /tmp/${TEMPDIR}/
# Add user, install packages
RUN set -eux \
	&& addgroup --system --gid 101 www-data \
	&& adduser --system --disabled-login --ingroup www-data --no-create-home \
	--disabled-password --gecos "www-data user" --uid 101 www-data ;\
	apt-get update \
	&& apt-get install -y nginx gnupg php-fpm mariadb-server php-mysql \
	openssl gosu php7.3-mbstring \
	&& apt-get purge -y --auto-remove
# Extract wordpress and phpmyadmin .tar files
RUN set -eux \
	&& tar -C /var/www/html/ -xf /tmp/${TEMPDIR}/phpMyAdmin-5.0.2-english.tar.gz \
	&& tar -C /var/www/html/ -xf /tmp/${TEMPDIR}/latest.tar.gz \
	&& mv /var/www/html/phpMyAdmin-5.0.2-english /var/www/html/phpmyadmin/ \
	&& mkdir /var/www/html/phpmyadmin/tmp \
	&& chown -R www-data:www-data /var/www/html/phpmyadmin/tmp/ \
	&& rm /var/www/html/wordpress/wp-config-sample.php
# configure nginx
RUN set -eux \
	&& cd /etc/nginx/sites-enabled/ \
	&& ln -s ../sites-available/wordpress.conf . \
	&& ln -s ../sites-available/phpmyadmin.conf . \
	&& rm default ; \
	ln -sf /dev/stdout /var/log/nginx/access.log \
	&& ln -sf /dev/stderr /var/log/nginx/error.log \
	&& mkdir /docker-entrypoint.d
COPY srcs/wp-config.php /var/www/html/wordpress/
# create certificates for ssl
RUN set -eux \
	&& openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj \
	'/C=ES/ST=28/L=Madrid/O=42/CN=aollero-' \
	-keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt
#secure mysql installation and inject wordpress database from host
RUN set -eux \
	&& service mysql start && mysqladmin -u root password "${DB_PASS}" ; \
	mysql -u root -p"${DB_PASS}" -e \
	"UPDATE mysql.user SET Password=PASSWORD('${DB_PASS}') WHERE User='root'"; \
	mysql -u root -p"${DB_PASS}" -e \
	"DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1')"; \
	mysql -u root -p"${DB_PASS}" -e \
	"DROP DATABASE IF EXISTS test"; \
	mysql -u root -p"${DB_PASS}" -e \
	"DELETE FROM mysql.user WHERE User=''"; \
	mysql -u root -p"${DB_PASS}" -e \
	"DELETE FROM mysql.db WHERE Db='test' OR Db='test\_%'"; \
	mysql -u root -p"${DB_PASS}" -e "CREATE DATABASE wordpress"; \
	mysql -u root -p"${DB_PASS}" -e \
	"GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost' IDENTIFIED BY \"${WP_PASS}\""; \
	mysql -u root -p"${DB_PASS}" < /tmp/${TEMPDIR}/wordpress.sql ; \
	mysql -u root -p"${DB_PASS}" -e "FLUSH PRIVILEGES" ; \
	rm -rf /tmp/${TEMPDIR}
COPY srcs/docker-entrypoint.sh /docker-entrypoint.sh
COPY srcs/docker-entrypoint.d/ /docker-entrypoint.d/
ENTRYPOINT ["/docker-entrypoint.sh"]
EXPOSE 80 443
STOPSIGNAL SIGTERM
CMD ["nginx","-g","daemon off;"]
