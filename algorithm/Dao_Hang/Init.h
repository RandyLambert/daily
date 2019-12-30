#ifndef INIT_H_
#define INIT_H_
#include "Template_Tool.hpp"
#include <iostream>
#include <mysql/mysql.h>
#include <cstring>
namespace User_Data
{
enum
{
    MAX_CHAR = 50,
    MAX_MI = 100
};
struct info_user
{
    char username[MAX_CHAR];
    int uid;
    char password[MAX_CHAR];
    int quan; //用户权限
    char sex[3];
    char mibao[MAX_MI];
} info_user;

struct login
{
    char username[MAX_CHAR];
    char password[MAX_CHAR];
} login_data;

struct dian_data{

};

} // namespace User_Data
class my_MySql
{
    //using namespace User_Data;
private:
    MYSQL mysql;
    MYSQL_RES *res_ptr;
    MYSQL_ROW sqlrow;
    MYSQL_FIELD *fd;
    int res, i, j;
    my_MySql();
    ~my_MySql();

public:
    void Insert_User(struct info_user info_user);
    void Insert_Dian();
    void Delete_Dian();
};

#endif
