#include "Init.h"
//初始化
void Init_MySql(){
    using namespace MySql;
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
