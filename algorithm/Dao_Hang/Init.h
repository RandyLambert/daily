#ifndef INIT_H_
#define INIT_H_
#include <iostream>
#include <mysql/mysql.h>
#include <cstring>
#include "Template_Tool.hpp"
#include "Tu_Alog.h"
#include "myString.h"
#include <unordered_map>

//自定义错误处理函数
void my_err(const char *err_myString, int line);

namespace User_Data
{
enum
{
    MAX_CHAR = 50,
    MAX_MIB = 100,
    MAX_BUF = 250
};
typedef struct info_user
{
    char username[MAX_CHAR];
    int uid;
    char password[MAX_BUF];
    int quan; //用户权限
    char sex[3];
    char mibao[MAX_MIB];
} info_user;

typedef struct lu_data
{
    int u, v, w;
} lu_data;

} 

using namespace User_Data;

class my_MySql
{
private:
    MYSQL mysql;
    MYSQL_RES *res_ptr;
    MYSQL_ROW sqlrow;
    MYSQL_FIELD *fd;
    int res, i, j;
    char buffer[MAX_BUF];
    my_MySql();
    my_MySql(const my_MySql &c){}
    ~my_MySql();
    static my_MySql * my_mysql;

public:
    static my_MySql * getInstance(){ return my_mysql;}
    void Insert_User(const info_user& login_data);
    bool Query_User(info_user& login_data);
    void Insert_Dian(const myString &Dian);
    void Delete_Dian(const myString &Dian);
    void Insert_Lu(const lu_data &data);
    void Delete_Lu(const lu_data &data);
    void Init_Dijk(Dijkstra *OneDijk);
    void Init_Krus(Kruskal *OneKrus);
    void Init_Map(std::unordered_map<int, myString> mp);
};


#endif
