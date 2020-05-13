#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include "MySQLsOps.h"
#include "MySQL.h"
using namespace ssxrver;
using namespace ssxrver::net;
using std::vector;
vector<string> SQLs::sqlRegister(const CJsonObject& cjson)
{
    vector<string> query;
    char tmp[1024];
    memset(tmp,0,sizeof tmp);
    sprintf(tmp,"INSERT INTO user VALUES(NULL,%s,%s,%s,%s,%s,%s)",cjson("userName").c_str(),cjson("passWord").c_str(),cjson("sex").c_str(),cjson("phoneNumber").c_str(),cjson("mibao").c_str(),cjson("power").c_str());
    query.push_back(tmp);
    std::cout<<"sqlRegister";
    return query;
}


vector<string> SQLs::sqlInsertAll(const CJsonObject& cjson)
{
    vector<string> query;
    string tmp("INSERT INTO "+cjson("insertObj"));
    tmp+=" VALUES(NULL,";
    cjson.AddemptySubArray("indd");
    for(int i = 0;i < cjson["insert"].GetArraySize();i++)
    {

    }

    sprintf(tmp,"INSERT INTO Studio VALUES(NULL,%s,%s,%s,%s,%s,%s)",cjson("userName").c_str(),cjson("passWord").c_str(),cjson("sex").c_str(),cjson("phoneNumber").c_str(),cjson("mibao").c_str(),cjson("power").c_str());
    query.push_back(tmp);
    std::cout<<"sqlRegister";
    return query;
    
}

vector<string> SQLs::sqlLogin(const CJsonObject& cjson)
{
    vector<string> query;
    char tmp[1024];
    memset(tmp,0,sizeof tmp);
    sprintf(tmp,"SELECT * FROM user WHERE uid = %s AND passWord = %s",cjson("uid").c_str(),cjson("passWord").c_str());
    query.push_back(tmp);
    std::cout<<"sqlLogin";
    return query;
}

vector<string> SQLs::sqlSelectAll(const CJsonObject& cjson)
{
    vector<string> query;
    char tmp[1024];
    memset(tmp,0,sizeof tmp);
    sprintf(tmp,"SELECT column_name FROM information_schema.columns WHERE table_schema='ttms' AND table_name='%s'",cjson("data").c_str());
    query.push_back(tmp);
    sprintf(tmp,"SELECT * FROM %s",cjson("data").c_str());
    query.push_back(tmp);
    std::cout<<"sqlselectall";
    return query;
}


