#!/bin/sh
service $(service --status-all 2> /dev/null | grep php | sed 's@^[^a-z|^A-Z|^0-9]*@@g') start
service $(service --status-all 2> /dev/null | grep mysql | sed 's@^[^a-z|^A-Z|^0-9]*@@g') start || true
if [ ${AUTOINDEX} = "off" ]
	then
		true
fi
if [ ${AUTOINDEX} = "on" ]
   then
	   sed -i 's@^\([^#]\)*#[^a]*autoindex@\1autoindex@g' /etc/nginx/sites-available/*
fi
