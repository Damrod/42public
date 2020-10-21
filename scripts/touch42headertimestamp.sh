#!/bin/bash
for file in $@
do
    touch -t $(grep "Updated" $file | sed 's@/*   Updated: \([0-9]*\)/\([0-9]*\)/\([0-9]*\) \([0-9]*\):\([0-9]*\):\([0-9]*\).*$@\1\2\3\4\5.\6@g'|sed 's@[/*|# ]@@g') $file
done
