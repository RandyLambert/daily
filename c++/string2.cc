
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string> 
using namespace std;
#define ERROR_LEXICAL_CAST     1 
 
int main()
{
    using boost::lexical_cast;
 
    int         a = 0;
    double        b = 0.0;
    std::string s = ""; 
    int            e = 0;    
    string x = "1";
    int c = std::stoi(x);
    cout<<c<<endl;
    try
    { 
        // ----- 字符串 --> 数值 
        a = lexical_cast<int>("123");
        b = lexical_cast<double>("123.12");
 
        // ----- 数值 --> 字符串
        s = lexical_cast<std::string>(123456.7); 
 
        // ----- 异常处理演示
        //e = lexical_cast<int>("abc")
    }
    catch(boost::bad_lexical_cast& e)
    {
        // bad lexical cast: source type value could not be interpreted as target
        std::cout << e.what() << std::endl;
        return ERROR_LEXICAL_CAST;
    } 
    
    std::cout << a << std::endl;    // 输出：123 
    std::cout << b << std::endl;    // 输出：123.12 
    std::cout << s << std::endl;     // 输出：123456.7 
 
    return 0;
}

