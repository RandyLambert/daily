#!/bin/bash
set -x;
g++ mysqltest.cpp MySQL.cpp MySQLsOps.cpp CJsonObject.cpp CJsonObject.hpp cJSON.c -pthread -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -o mysqltest

