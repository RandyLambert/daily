#ifndef SSXERVER_NET_MYSQLSOPS_H
#define SSXERVER_NET_MYSQLSOPS_H
#include <string>
namespace ssxrver
{
namespace net
{
using std::string;
int sqlRegister(const string& str);
int sqlLogin(const string& str);

}
}

#endif
