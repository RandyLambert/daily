#include "Init.h"
//初始化
my_MySql::my_MySql()
{

    res_ptr = nullptr;
    sqlrow = 0;
    fd = nullptr;
    res = 0, i = 0, j = 0;
    if (NULL == mysql_init(&mysql))
    {
        my_err("mysql_init", __LINE__);
    }

    //初始化一个句柄;
    //初始化数据库
    if (mysql_library_init(0, NULL, NULL) != 0)
    {
        my_err("mysql_library_init", __LINE__);
    }

    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "123456", "Tu_Alog", 0, NULL, 0) == NULL)
    {
        my_err("mysql_real_connect", __LINE__);
    }
    //连接数据库的重要一步：
    //设置中文字符集
    if (mysql_set_character_set(&mysql, "utf8") < 0)
    {
        my_err("mysql_set_character_set", __LINE__);
    }
}

my_MySql::~my_MySql()
{
    if (fd != nullptr)
    {
        delete fd;
    }

    if (res_ptr != nullptr)
    {
        delete res_ptr;
    }
}

void my_MySql::Delete_Lu(const lu_data &data)
{

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "delete from 朋友 where (u = %d and v = %d and w = %d) or (suid = v and u = %d and w = %d)", data.u, data.v, data.w, data.v, data.u, data.w);
    res = mysql_query(&mysql, buffer); //查询语句
    if (res)
    {
        printf("SELECT error:%s\n", mysql_error(&mysql));
    }
}

void my_MySql::Delete_Dian(const myString &Dian)
{
}

void my_MySql::Insert_Lu(const lu_data &data)
{
}

void my_MySql::Queue_Tu(Dijkstra &OneDijk)
{
}

void my_MySql::Insert_Dian(const myString &data)
{
    memset(buffer, 0, sizeof(buffer));
    //printf("%s\n", pack->data.mes);
    sprintf(buffer, "insert from 大 where (u = %d and v = %d and w = %d) or (suid = v and u = %d and w = %d)", data.u, data.v, data.w, data.v, data.u, data.w);
    printf("%s\n", buffer);
    res = mysql_query(&mysql, buffer); //查询语句
    if (res)
    {
        printf("SELECT error:%s\n", mysql_error(&mysql));
    }
    else
    {
        int fd = -1;
        res_ptr = mysql_store_result(&mysql); //取出结果集  mysql_store_result()立即检索所有的行，
        while ((sqlrow = mysql_fetch_row(res_ptr)))
        { //依次取出记录
            printf("%s\t", sqlrow[0]);
            fd = atoi(sqlrow[0]); //输出
            printf("\n");
        }
    }
}

void my_MySql::Insert_User()
{

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "select uid from 用户数据 where `name` = '%s'", );
    printf("%s\n", buffer);
    res = mysql_query(&mysql, buffer); //查询语句
    if (res)
    {
        printf("SELECT error:%s\n", mysql_error(&mysql));
    }
    else
    {
        int fd = -1;
        res_ptr = mysql_store_result(&mysql); //取出结果集  mysql_store_result()立即检索所有的行，
        while ((sqlrow = mysql_fetch_row(res_ptr)))
        { //依次取出记录
            printf("%s\t", sqlrow[0]);
            fd = atoi(sqlrow[0]); //输出
            printf("\n");
        }
    }
}