#include "MySQL.h"
#include "MySQLsOps.h"
#include "CJsonObject.hpp"
#include <iostream>
using namespace ssxrver;
using namespace ssxrver::net;
using namespace std;


MySQL::~MySQL()
{
    mysql_close(&mysql_);
    mysql_library_end();
    cout<<"mysql close"<<endl;
}

int MySQL::queryTableColName(const string& tableName,CJsonObject &result)
{
    string s = "SELECT column_name FROM information_schema.columns WHERE table_schema='ttms' AND table_name='" + tableName +"';";
    result.AddEmptySubArray("tableColName");
    if(mysql_query(&mysql_,s.c_str()) != 0){
        cout <<"queryTableColName "<< mysql_error(&mysql_)<<endl;
        return -1;
    }

    if(!(res_ = mysql_use_result(&mysql_)))
    {
        return -1;
    }

    int count = mysql_num_fields(res_);
    while((sqlrow_ = mysql_fetch_row(res_)))
    {
        for(int j = 0;j < count;j++)
        {
            result["tableColName"].Add(sqlrow_[j]);
        }
    }
    mysql_free_result(res_);
    cout <<"queryColName success"<<endl;
    return 1;
}

int MySQL::queryNoResult(const string& s)
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

int MySQL::queryHasResult(const std::pair<string,string>&s,CJsonObject& result)
{
    CJsonObject columName;
    result.AddEmptySubArray("data");
    queryTableColName(s.first,columName);

    if(mysql_query(&mysql_,s.second.c_str()) != 0){
        cout <<"queryHasResult "<< mysql_error(&mysql_)<<endl;
        return -1;
    }

    if(!(res_ = mysql_use_result(&mysql_)))
    {
        return -1;
    }

    int count = mysql_num_fields(res_);
    CJsonObject temp;
    while((sqlrow_ = mysql_fetch_row(res_)))
    {
        temp.Clear();
        for(int j = 0;j < count;j++)
        {
            temp.Add(columName["tableColName"](j),sqlrow_[j]);
        }
        result["data"].Add(temp);
    }
    mysql_free_result(res_);
    cout <<"queryHasResult success"<<endl;
    return 1;
}

MySQL::MySQL(const string& addr,const string& user,const string& password,const string& dataBaseName,unsigned int port,const char* unixSocket,unsigned long clientFlag)
    : res_(NULL),
      sqlrow_(0)
{
    res_ = nullptr;
    sqlrow_ = 0;
    res_ = 0;
    if(NULL == mysql_init(&mysql_))
    {
        cout << mysql_error(&mysql_)<<endl;
        /* LOG_FATAT<<; */
    }

    //初始化一个句柄;
    //初始化数据库
    if(mysql_library_init(0,NULL,NULL) != 0)
    {
        cout << mysql_error(&mysql_) << endl;
        /* LOG_FATAT<<; */
    }

    if(mysql_real_connect(&mysql_,addr.c_str(),user.c_str(),password.c_str(),dataBaseName.c_str(),port,unixSocket,clientFlag)==NULL)
    {
        cout<< mysql_error(&mysql_)<< endl;
        /* LOG_FATAT<<; */
    }

    //连接数据库重要的一步:
    //设置中文字符集
    if(mysql_set_character_set(&mysql_,"utf8") < 0)
    {
        cout<< mysql_error(&mysql_)<< endl;
        /* LOG_FATAT<<; */
    }
        /* LOG_DEBUE<<; */
}


int MySQL::sqlInsert(const CJsonObject& cjson)
{
    string queryStr("INSERT INTO "+cjson("tableName") +"(");
    string keyStr;
    string valueStrs("VALUES");
    bool flag = false;
    CJsonObject& cjsonRef = const_cast<CJsonObject&>(cjson);
    for(int i = 0;i < cjsonRef["data"].GetArraySize();i++)
    {
        if(flag == false)
        {
            flag = true;
            valueStrs+="(";
            while(cjsonRef["data"][i].GetKey(keyStr))
            {
                queryStr+=keyStr+",";
                valueStrs+=cjsonRef["data"](keyStr)+",";
            }
            queryStr.back() = ')';
            valueStrs.back() = ')';
            queryStr+=valueStrs+",";
        }
        else
        {
            valueStrs.clear();
            valueStrs+="(";
            while(cjsonRef["data"][i].GetKey(keyStr))
            {
                valueStrs+=cjsonRef["data"](keyStr)+",";
            }
            valueStrs.back() = ')';
            queryStr+=valueStrs+",";
        }

    }
    queryStr.back() = ';';
    std::cout<<"sqlInsert"<<std::endl;
    return queryNoResult(queryStr);
}

int MySQL::sqlSelectWhere(const CJsonObject& cjson,CJsonObject &result)
{
    std::pair<string,string> query;
    query.first = cjson("tableName");

    string queryStr("SELECT ");
    string keyStr;
    CJsonObject& cjsonRef = const_cast<CJsonObject&>(cjson);
    for(int i = 0;i < cjsonRef["what"].GetArraySize();i++)
    {
        queryStr+=cjsonRef["what"](i)+',';
    }
    
    queryStr.back() = ' ';
    queryStr+="FROM " + cjson("tableName") + " WHERE ";
    
    int i = 0;
    while(cjsonRef["data"].GetKey(keyStr))
    {
        queryStr+=keyStr+cjsonRef["op"](i);
        if(i == 0)
        {
            queryStr+=cjsonRef["data"](keyStr);
            i++;
        }
        else
        {
            queryStr+= " AND " + cjsonRef["data"](keyStr);
            i++;
        }
    }
    queryStr += ';';
    query.second = queryStr;

    std::cout<<"sqlSelectWhere"<<std::endl;
    return queryHasResult(query,result);
}

int MySQL::sqlDeleteWhere(const CJsonObject& cjson)
{

    string queryStr("DELETE FROM "+cjson("tableName")+" WHERE ");
    string keyStr;
    CJsonObject& cjsonRef = const_cast<CJsonObject&>(cjson);
    int i = 0;
    while(cjsonRef["data"].GetKey(keyStr))
    {
        queryStr+=keyStr+cjsonRef["op"](i);
        if(i == 0)
        {
            queryStr+=cjsonRef["data"](keyStr);
            i++;
        }
        else
        {
            queryStr+= " AND " + cjsonRef["data"](keyStr);
            i++;
        }
    }
    queryStr += ';';

    std::cout<<"sqlDeleteWhere"<<std::endl;
    return queryNoResult(queryStr);

}

int MySQL::sqlUpdateWhere(const CJsonObject& cjson)
{
    string queryStr("UPDATE "+cjson("tableName")+" SET ");
    string keyStr;
    CJsonObject& cjsonRef = const_cast<CJsonObject&>(cjson);
    while(cjsonRef["set"].GetKey(keyStr))
    {
        queryStr+=keyStr+"=";
        queryStr+=cjsonRef["set"](keyStr)+",";
    }
    queryStr.back() = ' ';
    int i = 0;
    while(cjsonRef["data"].GetKey(keyStr))
    {
        queryStr+=keyStr+cjsonRef["op"](i);
        if(i == 0)
        {
            queryStr+=cjsonRef["data"](keyStr);
            i++;
        }
        else
        {
            queryStr+= " AND " + cjsonRef["data"](keyStr);
            i++;
        }
    }
    queryStr += ';';

    std::cout<<"sqlUpdateWhere"<<std::endl;
    return queryNoResult(queryStr);

}
