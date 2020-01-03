#include "Init.h"
//初始化
void my_err(char const *err_myString, int line)
{
    fprintf(stderr, "line:%d ", line);
    perror(err_myString);
    exit(1);
}

my_MySql::my_MySql()
{
    res_ptr = nullptr;
    sqlrow = 0;
    fd = nullptr;
    res = 0, i = 0, j = 0;

    if (NULL == mysql_init(&mysql))
    {
        std::cout << mysql_error(&mysql) << std::endl;
        my_err("mysql_init", __LINE__);
    }

    //初始化一个句柄;
    //初始化数据库
    if (mysql_library_init(0, NULL, NULL) != 0)
    {
        std::cout << mysql_error(&mysql) << std::endl;
        my_err("mysql_library_init", __LINE__);
    }

    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "123456", "TU_Alog", 0, NULL, 0) == NULL)
    {
        std::cout << mysql_error(&mysql) << std::endl;
        my_err("mysql_real_connect", __LINE__);
    }
    //连接数据库的重要一步：
    //设置中文字符集
    if (mysql_set_character_set(&mysql, "utf8") < 0)
    {
        std::cout << mysql_error(&mysql) << std::endl;
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
    sprintf(buffer, "delete from Tu_data where (u = %d and v = %d and w = %d)", data.u, data.v, data.w);
    res = mysql_query(&mysql, buffer); //查询语句
    if (res)
    {
        printf("SELECT error:%s\n", mysql_error(&mysql));
    }
    else
    {
        std::cout << "删除成功\n";
    }
}

void my_MySql::Delete_Dian(const myString &Dian)
{
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "delete from Map where name = '%s'", Dian.c_str());
    std::cout << buffer << std::endl;
    res = mysql_query(&mysql, buffer); //查询语句 
    if (res)
    {
        printf("SELECT error:%s\n", mysql_error(&mysql));
    }
    else
    {
        std::cout << "删除成功\n";
    }
}

bool my_MySql::Insert_Lu(const lu_data &data)
{
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "insert into Tu_data values(NULL,%d,%d,%d)", data.u, data.v, data.w);
    std::cout << buffer << std::endl;
    res = mysql_query(&mysql, buffer); //查询语句 
    if (res)
    {
        printf("SELECT error:%s\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        std::cout << "插入成功\n";
        return true;
    }
}

void my_MySql::Init_Dijk(Dijkstra *OneDijk)
{
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "select * from Tu_data");
    mysql_free_result(res_ptr);                                   //释放空间
    res = mysql_query(&mysql, buffer);                            //查询语句
    res_ptr = mysql_store_result(&mysql);                         //取出结果集  mysql_store_result()立即检索所有的行，
    printf("%lu Rows\n", (unsigned long)mysql_num_rows(res_ptr)); //返回所有的行
    j = mysql_num_fields(res_ptr);                                //获取 列数
    int u, v, w;
    while ((sqlrow = mysql_fetch_row(res_ptr)))
    { //依次取出记录
        for (i = 1; i < j; i++)
        {
            printf("%s\t", sqlrow[i]); //输出
            if (i == 1)
            {
                u = atoi(sqlrow[i]);
            }
            else if (i == 2)
            {
                v = atoi(sqlrow[i]);
            }
            else if (i == 3)
            {
                w = atoi(sqlrow[i]);
            }
        }
        OneDijk->Addedge_Dijk(u, v, w);
        OneDijk->Addedge_Dijk(v, u, w);
        cout<<buffer<<endl;
    }

    if (mysql_errno(&mysql))
    {
        fprintf(stderr, "Retrive error:%s\n", mysql_error(&mysql));
    }

    mysql_free_result(res_ptr); //释放空间
}

void my_MySql::Init_Krus(Kruskal *OneKrus)
{
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "select * from Tu_data");
    mysql_free_result(res_ptr);                                   //释放空间
    res = mysql_query(&mysql, buffer);                            //查询语句
    res_ptr = mysql_store_result(&mysql);                         //取出结果集  mysql_store_result()立即检索所有的行，
    printf("%lu Rows\n", (unsigned long)mysql_num_rows(res_ptr)); //返回所有的行
    j = mysql_num_fields(res_ptr);                                //获取 列数
    int u, v, w;
    while ((sqlrow = mysql_fetch_row(res_ptr)))
    { //依次取出记录
        for (i = 1; i < j; i++)
        {
            printf("%s\t", sqlrow[i]); //输出
            if (i == 1)
            {
                u = atoi(sqlrow[i]);
            }
            else if (i == 2)
            {
                v = atoi(sqlrow[i]);
            }
            else if (i == 3)
            {
                w = atoi(sqlrow[i]);
            }
        }
        OneKrus->Addedge_Krus(u, v, w);
        OneKrus->Addedge_Krus(v, u, w);
    }

    if (mysql_errno(&mysql))
    {
        fprintf(stderr, "Retrive error:%s\n", mysql_error(&mysql));
    }

    mysql_free_result(res_ptr); //释放空间
}
/*
void my_MySql::Init_Map(std::unordered_map<int, myString>&mp)
{
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "select * from Map");
    mysql_free_result(res_ptr);                                   //释放空间
    res = mysql_query(&mysql, buffer);                            //查询语句
    res_ptr = mysql_store_result(&mysql);                         //取出结果集  mysql_store_result()立即检索所有的行，
    printf("%lu Rows\n", (unsigned long)mysql_num_rows(res_ptr)); //返回所有的行
    j = mysql_num_fields(res_ptr);                                //获取 列数
    myString y;
    while ((sqlrow = mysql_fetch_row(res_ptr)))
    { //依次取出记录
        int x;
        for (i = 0; i < j; i++)
        {

            printf("%s\t", sqlrow[i]); //输出
            if (i == 0)
            {
                x = atoi(sqlrow[i]);
                maxxdin = std::max(x,maxxdin);
            }
            else if (i == 1)
            {
                y = sqlrow[i];
            }
        }
        mp[x] = y;
        cout<<endl;
        cout<<mp.size()<<endl;
    }

    if (mysql_errno(&mysql))
    {
        fprintf(stderr, "Retrive error:%s\n", mysql_error(&mysql));
    }

    mysql_free_result(res_ptr); //释放空
}*/
bool my_MySql::Insert_Dian(const myString &data)
{
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "insert into Map values(NULL,'%s')", data.c_str());
    std::cout << buffer << std::endl;
    res = mysql_query(&mysql, buffer); //查询语句 
    if (res)
    {
        printf("SELECT error:%s\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        std::cout << "插入成功\n";
        return true;
    }
}

bool my_MySql::Query_User(info_user &login_data)
{
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "select uid from User where name = '%s' and password = '%s'", login_data.username, login_data.password);
    std::cout << buffer;
    res = mysql_query(&mysql, buffer); //查询语句

    if (res)
    {
        printf("SELECT error:%s\n", mysql_error(&mysql));
    }
    else
    {
        res_ptr = mysql_store_result(&mysql); //取出结果集  mysql_store_result()立即检索所有的行，
        if (mysql_num_rows(res_ptr) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool my_MySql::Insert_User(info_user &login_data)
{
    if(Query_User(login_data) == false){
        return false;
    }
    else{
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "insert into User values(NULL,'%s','%s','%s','%s')", login_data.username, login_data.sex, login_data.password, login_data.mibao);
        std::cout << buffer;
        res = mysql_query(&mysql, buffer); //查询语句 
        if (res)
        {
            printf("SELECT error:%s\n", mysql_error(&mysql));
            return false;
        }
        else
        {
            std::cout << "插入成功" << std::endl;
            return true;
        }
    }
   
}
 