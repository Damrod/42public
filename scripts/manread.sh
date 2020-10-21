#!/bin/sh
cat $@ | /usr/bin/tbl | /usr/bin/groff -Wall -mtty-char -Tascii -mandoc -c | (/usr/bin/less -is || true)
