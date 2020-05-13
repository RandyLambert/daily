#ifndef SSXERVER_NET_MYSQL_H
#define SSXERVER_NET_MYSQL_H
#include "noncopyable.h"
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <mysql/mysql.h>
namespace ssxrver
{
namespace net
{

using std::string;
class CJsonObject;
class MySQL : noncopyable
{
    typedef std::function<std::vector<string> (const CJsonObject&)> sqlCallBack;
public:
    MySQL();
    ~MySQL();
    bool mysqlInit(const string& addr="127.0.0.1",const string& user="root",const string& password="123456",const string& dataBaseName="ttms",unsigned int port = 0,const char* unixSocket=NULL,unsigned long clientFlag = 0);
    int returnMin()
    {
        return MIN;
    }
    int returnMid()
    {
        return MID;
    }
    int returnMax()
    {
        return MAX;
    }

    int useNoResultMap(int x,const CJsonObject& query)
    {
        return queryNoResult(sqlMap[x](query));
    }

    int useHasResultMap(int x,const CJsonObject& query,CJsonObject& reback)
    {
        
        return queryHasResult(sqlMap[x](query),reback);
    }

private:

    enum
    {
        MIN,
        LOGIN,
        INSERTALL,
        MID,
        SELECTALL,
        QUERYSEAT,
        MAX
    };
    int queryNoResult(const std::vector<string>& s);
    int queryHasResult(const std::vector<string>& s,CJsonObject &result);
    std::map<int,sqlCallBack> sqlMap;
    MYSQL mysql_;
    MYSQL_RES *res_;
    MYSQL_ROW sqlrow_;
};

}
}
#endif

