#ifndef SSXERVER_NET_MYSQL_H
#define SSXERVER_NET_MYSQL_H
#include "noncopyable.h"
#include <string>
#include <mysql/mysql.h>
namespace ssxerver
{
namespace net
{

using std::string;
class MySQLop : noncopyable
{
public:
    MySQLop();
    ~MySQLop();
    int queryNoResult(const string& s);
    string queryHasResult(const string& s);
    bool mysqlInit(const string& addr="127.0.0.1",const string& user="root",const string& password="123456",const string& dataBaseName="ttms",unsigned int port = 0,const char* unixSocket=NULL,unsigned long clientFlag = 0);

private:
    MYSQL mysql_;
    MYSQL_RES *res_;
    MYSQL_ROW sqlrow_;
};

}
}
#endif

