#ifndef INIT_H_
#define INIT_H_
#include "Template_Tool.hpp"
#include <iostream>
#include <mysql/mysql.h>

namespace MySql{
MYSQL mysql;
MYSQL_RES *res_ptr = NULL;
MYSQL_ROW sqlrow;
MYSQL_FIELD *fd;
int res, i, j;
}

namespace User_Data{
int16_t MAX_CHAR;
typedef struct info_user 
{
    char username[MAX_CHAR];
    int uid;
    char password[20];
    int  statu;//don't foget to change is to 0 when the server begin
    int  socket_id;
    char sex[3];
    char mibao[100];
}info_user;


typedef struct infouser_node
{
    info_user data;
    struct infouser_node *next;
    struct infouser_node *prev;
}infouser_node_t,* infouser_list_t;


typedef struct login{
    char username[MAX_CHAR];
    char password[MAX_CHAR];
}login_data;

}
void Init_MySql();


#endif
