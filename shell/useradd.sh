#!/bin/bash

read -t 30 -p "input name: " name
read -t 30 -p "inout num: " num
read -t 30 -p "input password: " pass

if [ ! -z "$name" -a ! -z "$num" -a ! -z "$pass" ]
then
    y=$(echo $num | sed 's/^[0-9]*$'//g)
    if [ -z "$y" ]
    then
        for(( i=1;i<=$num;i=i+1 ))
        do
            useradd $name$: &>/dev/null
            echo $pass | passwd --stdin "$name$:" &>/dev/null
        done
    fi
fi
