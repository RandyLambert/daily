/* #include <iostream> */
/* #include <string> */
/* using namespace std; */
/* const string &manip() */
/* { */
/*     string ret=("sss"); */
/*     auto &rett=ret; */
/*     return rett; */
/* } */
/* int main() */
/* { */
/*     string a=manip(); */
/*     cout<<a; */
/* } */
/* #include <iostream> */
/* #include <string> */
/* using namespace std; */
/* const string &manip() */
/* { */
/*     string ret; */
/*     return ret; */
/* } */
/* int main() */
/* { */
/*     string a=manip(); */
/*     cout<<a; */
/* } */

/* #include <iostream> */

/* #include <string> */

/* using namespace std; */

/* const string &shorterString(const string &s1, const string &s2) */

/* { */

/* return s1.size() <= s2.size() ? s1 : s2; */

/* } */

/* string &shorterString(string &s1, string &s2) */

/* { */

/* auto &r=shorterString(const_cast<const string&>(s1),const_cast<const string &>(s2)); */

/* return const_cast<string&>(r); */

/* } */


/* int main() */

/* { */

/* string a=shorterString("aaa","bbb"); */

/* cout<<a; */

/* } */


#include <iostream>
#include <string>
using namespace std;
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
string &shorterString(string &s1, string &s2)
{
    /* auto &r=shorterString(const_cast<const string&>(s1),const_cast<const string &>(s2)); */
    /* return const_cast<string&>(r); */

    string a = "dassasa\n";
    string &b = a;
    return b;
}
int main()
{
    string a = shorterString("aaa","bbb");
    cout<<a;
}
