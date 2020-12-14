#!/bin/sh

set -e

if [ "$1" = "nginx" ]
then
	/docker-entrypoint.d/php-start.sh
fi

exec "$@"
