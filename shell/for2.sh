#!/bin/bash
# cd /root/sh/
ls *.sh > ls.log

for i in $(cat ls.log)
do
    echo 'hhhh'
done

rm -rf ls.log
