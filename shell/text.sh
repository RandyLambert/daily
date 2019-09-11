#!/bin/bash
#测试位置参数和其他特殊参数
#使用方法：/target.sh 参数1  参数2
 
IFS=#
echo shell script name is : $0
echo the count of parameters: $#
echo first param=$1
echo second param=$2
echo '$*='$*      #显示所有的位置参数串
echo '"$*"="$*"'
echo '$@='$@
echo '"$@"='"$@"
echo '$$='$$      #显示当前进程号
echo $!


