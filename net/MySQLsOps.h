#ifndef SSXERVER_NET_MYSQLSOPS_H
#define SSXERVER_NET_MYSQLSOPS_H
#include <string>
#include <vector>
#include "CJsonObject.hpp"
namespace ssxrver
{
namespace net
{
namespace SQLs
{
using std::string;
using std::vector;
vector<string> sqlRegister(const CJsonObject& cjson);
vector<string> sqlLogin(const CJsonObject& cjson);
vector<string> sqlSelectAll(const CJsonObject& cjson);
vector<string> sqlInsertAll(const CJsonObject& cjson);

}
}
}

#endif
