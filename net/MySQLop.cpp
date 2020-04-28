#include "MySQLop.h"
#include <iostream>
using namespace ssxerver;
using namespace ssxerver::net;
using namespace std;

MySQLop::MySQLop():res_(NULL),sqlrow_(0)
{
}

MySQLop::~MySQLop()
{
    mysql_close(&mysql_);
    mysql_library_end();
    cout<<"mysql close"<<endl;
}

int MySQLop::queryNoResult(const string& s)
{
    if(mysql_query(&mysql_,s.c_str()) != 0){
        cout <<"queryNoResult "<< mysql_error(&mysql_)<<endl;
        return -1;
    }
    else
    {
        cout <<"queryNoResult success"<<endl;
        return static_cast<int>(mysql_affected_rows(&mysql_));
    }
}

string MySQLop::queryHasResult(const string& s)
{
    string result;
    if(mysql_query(&mysql_,s.c_str()) != 0){
        cout <<"queryHasResult "<< mysql_error(&mysql_)<<endl;
        return result;
    }

    if(!(res_ = mysql_use_result(&mysql_)))
    {
        return result;
    }

    int count = mysql_num_fields(res_);
    while((sqlrow_ = mysql_fetch_row(res_)))
    {
        for(int j = 0;j < count;j++)
        {
            result+=sqlrow_[j];
            result+="\r\t";
        }
        result+="\r\t";
    }
    mysql_free_result(res_);
    cout <<"queryHasResult success"<<endl;
    return result;
}

bool MySQLop::mysqlInit(const string& addr,const string& user,const string& password,const string& dataBaseName,unsigned int port,const char* unixSocket,unsigned long clientFlag)
{
    res_ = nullptr;
    sqlrow_ = 0;
    res_ = 0;
    if(NULL == mysql_init(&mysql_))
    {
        cout << mysql_error(&mysql_)<<endl;
        return false;
    }

    //初始化一个句柄;
    //初始化数据库
    if(mysql_library_init(0,NULL,NULL) != 0)
    {
        cout << mysql_error(&mysql_) << endl;
        return false;
    }

    if(mysql_real_connect(&mysql_,addr.c_str(),user.c_str(),password.c_str(),dataBaseName.c_str(),port,unixSocket,clientFlag)==NULL)
    {
        cout<< mysql_error(&mysql_)<< endl;
        return false;
    }

    //连接数据库重要的一步:
    //设置中文字符集
    if(mysql_set_character_set(&mysql_,"utf8") < 0)
    {
        cout<< mysql_error(&mysql_)<< endl;
        return false;
    }

    return true;
}
