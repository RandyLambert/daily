#ifndef TEMPLATE_TOOL_HPP_
#define TEMPLATE_TOOL_HPP_
#include <iostream>
#include <cstring>
#include <cstdlib>
//自定义错误处理函数
void my_err(const char *err_myString, int line)
{
    fprintf(stderr, "line:%d ", line);
    perror(err_myString);
    exit(1);
}

template <typename T>
bool cmp(T a, T b)
{ //排序函数
    return a < b;
}

//交换
template <typename T>
T mySwap(T &a, T &b)
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

//快拍
template <typename T>
void mySort(T &arr, size_t l, size_t r)
{

    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];

    while (i < j)
    {
        do
            j--;
        while (arr[j] > x);
        do
            i++;
        while (arr[i] < x);
        if (i < j)
            mySwap<T>(arr[i], arr[j]);
        else
            mySort<T>(arr, l, j), mySort(arr, j + 1, r);
    }
}

class myString
{
    //frined ostream& operator <<(ostream& out,)
public:
    myString();
    myString(const myString &str);
    myString(const myString &str, size_t pos, size_t len = npos);
    myString(const char *s);
    myString(const char *s, size_t n);
    myString(size_t n, char c);
    ~myString();

    void clear();
    char front() const;
    char *end() const;
    char *begin() const;

    const char *c_str() const;
    size_t length() const;
    size_t size() const;
    char *find(const myString &w) const;
    char *fastfind(const myString &w);

    char &operator[](size_t pos);
    const char &operator[](size_t pos) const;
    myString &operator=(const myString &str);
    myString &operator=(const char *s);
    myString &operator=(char c);
    myString &operator+=(const myString &str);
    myString &operator+=(const char *s);
    myString &operator+=(char c);

    myString &append(const myString &str);
    myString &append(const char *s);

    myString &assign(const myString &str);
    myString &assign(const char *s);

    char &at(size_t pos);
    const char &at(size_t pos) const;

    int compare(const myString &str) const;
    int compare(const char *s) const;

    const char *data() const;
    bool empty() const;

    static const size_t npos = -1;

private:
    size_t ssize;
    union _Bxty {
        char _Buf[16];
        char *_ptr;
    } _Bx;

    void rrsize(size_t x); //扩容
    const char* getnext(const char *w); //kmp
};

inline void myString::rrsize(size_t x)
{
    if (ssize < x)
        _Bx._ptr = (char *)realloc(_Bx._ptr, x * 2);
    ssize = x * 2;
}

inline char &myString::operator[](size_t pos)
{
    if (ssize <= 15)
        return _Bx._Buf[pos];
    else
        return _Bx._ptr[pos];
}

inline const char &myString::operator[](size_t pos) const
{
    if (ssize <= 15)
        return _Bx._Buf[pos];
    else
        return _Bx._ptr[pos];
}

inline const char *myString::c_str() const
{
    if (ssize <= 15)
    {
        const char *tmp = _Bx._Buf;
        return tmp;
    }
    else
    {
        return _Bx._ptr;
    }
}

inline int myString::compare(const myString &str) const
{
    return strcmp(c_str(), str.c_str());
}
int myString::compare(const char *s) const{
    return strcmp(c_str(),s);
}

static inline bool operator == (const myString& lhs, const myString& rhs)
{
	return (lhs.compare(rhs) == 0);
}
 
static inline bool operator == (const char* lhs, const myString& rhs)
{
	return (rhs.compare(lhs) == 0);
}
 
static inline bool operator == (const myString& lhs, const char* rhs)
{
	return (lhs.compare(rhs) == 0);
}
 
static inline bool operator != (const myString& lhs, const myString& rhs)
{
	return (lhs.compare(rhs) != 0);
}
 
static inline bool operator != (const char* lhs, const myString& rhs)
{
	return (rhs.compare(lhs) != 0);
}
 
static inline bool operator != (const myString& lhs, const char* rhs)
{
	return (lhs.compare(rhs) != 0);
}
 
static inline bool operator < (const myString& lhs, const myString& rhs)
{
	return (lhs.compare(rhs) < 0);
}
 
static inline bool operator < (const char* lhs, const myString& rhs)
{
	return (rhs.compare(lhs) >= 0);
}
 
static inline bool operator < (const myString& lhs, const char* rhs)
{
	return (lhs.compare(rhs) < 0);
}
 
static inline bool operator <= (const myString& lhs, const myString& rhs)
{
	return (lhs.compare(rhs) <= 0);
}
 
static inline bool operator <= (const char* lhs, const myString& rhs)
{
	return (rhs.compare(lhs) > 0);
}
 
static inline bool operator <= (const myString& lhs, const char* rhs)
{
	return (lhs.compare(rhs) <= 0);
}
 
static inline bool operator > (const myString& lhs, const myString& rhs)
{
	return (lhs.compare(rhs) > 0);
}
 
static inline bool operator > (const char* lhs, const myString& rhs)
{
	return (rhs.compare(lhs) <= 0);
}
 
static inline bool operator > (const myString& lhs, const char* rhs)
{
	return (lhs.compare(rhs) > 0);
}
 
static inline bool operator >= (const myString& lhs, const myString& rhs)
{
	return (lhs.compare(rhs) >= 0);
}
 
static inline bool operator >= (const char* lhs, const myString& rhs)
{
	return (rhs.compare(lhs) < 0);
}
 
static inline bool operator >= (const myString& lhs, const char* rhs)
{
	return (lhs.compare(rhs) >= 0);
}


myString &myString::operator=(char c)
{
    if (ssize <= 15)
    {
        memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
        strcpy(_Bx._Buf, (char *)&c);
    }
    else
    {
        memset(_Bx._ptr, 0, ssize);
        strcpy(_Bx._ptr, (char *)&c);
    }
    ssize = 1;
    return *this;
}

myString &myString::operator=(const char *s)
{
    if (strlen(s) <= 15)
    {
        memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
        strcpy(_Bx._Buf, s);
    }
    else
    {
        rrsize(strlen(s));
        memset(_Bx._ptr, 0, ssize);
        strcpy(_Bx._ptr, s);
    }
    ssize = size();
    return *this;
}

myString &myString::operator=(const myString &str)
{
    if (ssize <= 15)
    {
        memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
        strcpy(_Bx._Buf, str.c_str());
    }
    else
    {
        rrsize(str.length());
        memset(_Bx._ptr, 0, ssize);
        strcpy(_Bx._ptr, str.c_str());
    }
    ssize = str.size();
    return *this;
}

myString &myString::operator+=(const char *s){
    if(strlen(s)+ssize <= 15){
        strcat(_Bx._Buf,s);
        ssize = strlen(_Bx._Buf);
    }
    else{
        ssize += strlen(s);
        rrsize(ssize);
        strcat(_Bx._ptr,s);
    }
    return *this;
}

myString &myString::operator+=(char c)
{
    if(1+ssize <= 15){
        strcat(_Bx._Buf,(char*)&c);
        ssize++;
    }
    else{
        ssize++;
        rrsize(ssize);
        strcat(_Bx._ptr,(char*)&c);
    }
    return *this;
    
}
myString &myString::operator+=(const myString &str)
{
    if(str.length()+ssize <= 15){
        strcat(_Bx._Buf,str.c_str());
        ssize = strlen(_Bx._Buf);
    }
    else{
        ssize += str.length();
        rrsize(ssize);
        strcat(_Bx._ptr,str.c_str());
    }
    return *this;
}

static inline myString operator+(const myString& lhs, const myString& rhs)
{
	myString str(lhs);
	str += rhs;
	return str;
}
 
static inline myString operator+(const myString& lhs, const char* rhs)
{
	myString str(lhs);
	str += rhs;
	return str;
}
 
static inline myString operator+(const char* lhs, const myString& rhs)
{
	myString str(lhs);
	str += rhs;
	return str;
}
 
static inline myString operator + (const myString& lhs, char rhs)
{
	myString str(lhs);
	str += rhs;
	return str;
}
 
static inline myString operator + (char lhs, const myString& rhs)
{
	myString str(&lhs);
	str += rhs;
	return str;
}

inline myString::myString()
{
    memset(&_Bx, 0, sizeof(_Bx));
}

inline myString::myString(const myString &str)
{
    memset(&_Bx, 0, sizeof(_Bx));
    if (str.length() <= 15)
    {
        strcpy(_Bx._Buf, str.c_str());
    }
    else
    {
        rrsize(str.length());
    }
    ssize = str.length();
}

myString::myString(const char *s)
{
    memset(&_Bx, 0, sizeof(_Bx));
    ssize_t tp = strlen(s);
    if (tp <= 15)
    {
        strcpy(_Bx._Buf, s);
    }
    else
    {
        rrsize(tp);
        strcpy(_Bx._ptr, s);
    }
    ssize = tp;
}

myString::myString(size_t n, char c)
{
    memset(&_Bx, 0, sizeof(_Bx));
    if (n <= 15)
    {
        for (size_t i = 0; i < n; i++)
            _Bx._Buf[i] = c;
    }
    else
    {
        rrsize(n);
        for (size_t i = 0; i < n; i++)
            _Bx._Buf[i] = c;
    }
    ssize = n;
}

inline myString::~myString()
{
    if (ssize > 15 && _Bx._ptr != nullptr)
    {
        delete[] _Bx._ptr;
    }
}

inline size_t myString::length() const
{
    return ssize;
}

inline size_t myString::size() const
{
    return ssize;
}

inline void myString::clear()
{
    if (ssize < 15)
    {
        memset(&_Bx._Buf, 0, sizeof(_Bxty));
    }
    else
    {
        memset(_Bx._ptr, 0, ssize);
    }
}

inline bool myString::empty() const
{
    if (ssize == 0)
    {
        return true;
    }
    else
        return false;
}

char myString::front() const
{
    if (ssize == 0)
        return '\0';
    else
    {
        if (ssize <= 15)
        {
            return _Bx._Buf[0];
        }
        else
        {
            return *_Bx._ptr;
        }
    }
}


myString &myString::append(const myString &str){

}
myString &myString::append(const char *s){

}

myString &myString::assign(const myString &str){

}
myString &myString::assign(const char *s){

}


const char * myString::data() const{

}

inline char &myString::at(size_t pos){
    if(pos <= 15)
        return _Bx._Buf[pos];
    else
    {
        return _Bx._ptr[pos];
    }
}

inline const char &myString::at(size_t pos) const{
    if(pos <= 15)
        return _Bx._Buf[pos];
    else
    {
        return _Bx._ptr[pos];
    }
}

const char * myString::getnext(const char *w){
 int wlen = strlen(w);

 char *next1 = new char[strlen(w)]; 
 int j = 0,k = -1;
 next1[0] = -1;
 
 while(j < wlen){
     if(k == -1 || w[k] == w[j]){
         ++k;
         ++j;
         next1[j] = k;
     }
     else{
         k = next1[k];
     }
 }
 return next1;
}

char * myString::fastfind(const myString &w){

 int tlen = ssize;
 const char *next1 = getnext(w.c_str());

 int i = 0,j = 0;
 while(j < tlen){
     if(i == -1 || w[i] == at(j)){
         i++;
         j++;
     }
     else{
         i = next1[i];
     }
 }
 if(next1!=NULL){
     delete  []next1;
 }
}

#endif
