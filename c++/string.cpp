#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    const char* c_str()
    {
        return _str;
    }

    String(const char* str = "")
    :_str(new char[strlen(str)+1])
    {
        strcpy(_str,str);
    }
    /* String(const String&s):_str(NULL) */
    /* { */
    /*     String temp(s._str); */
    /*     swap(_str,temp._str); */
    /* } */

    ~String()
    {
        if(_str!=NULL)
        {
            delete []_str;
        }
    }

    /*String& operator = (const String&s)
    {
        if(this != &s)
        {
            String temp(s._str);
            swap(temp._str,_str);
            return *this;
        }
    }*/

    String& operator=(String &s){
        /* swap(_str,s._str); */
        strcpy(_str,s._str);
        return *this;
    }
private:
    char*_str;

};
int main(){
    
    String a("asdsd");

    String b = a;
    const char *p = b.c_str();
    const char *q = a.c_str();
    cout<<p<<endl;
    cout<<q<<endl;

    return 0;
}

