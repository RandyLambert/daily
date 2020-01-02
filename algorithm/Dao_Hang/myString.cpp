#include "myString.h"
inline void myString::rrsize(size_t x)
{
    if (ssize < x)
        _Bx._ptr = (char *)realloc(_Bx._ptr, x * 2);
}

std::ostream &operator<<(std::ostream &out, myString &str)
{
    if (str.length() <= 15)
    {
        out << str._Bx._Buf;
    }
    else
    {
        out << str._Bx._ptr;
    }
    return out;
}

std::istream &operator>>(std::istream &in, myString &str)
{
    char *tp = new char[1024];
    in >> tp;
    if (strlen(tp) <= 15)
    {
        strcpy(str._Bx._Buf, tp);
        str.ssize = strlen(tp);
    }
    else
    {
        str.rrsize(strlen(tp));
        strcpy(str._Bx._ptr, tp);
    }
    delete[] tp;
    return in;
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
    if (pos >= ssize)
        return '\0';
    else if (ssize <= 15)
        return _Bx._Buf[pos];
    else
        return _Bx._ptr[pos];
}

inline const char *myString::c_str() const
{
    if (ssize <= 15)
    {
        return _Bx._Buf;
    }
    else
    {
        return _Bx._ptr;
    }
}

int myString::compare(const myString &str) const
{
    return strcmp(c_str(), str.c_str());
}
int myString::compare(const char *s) const
{
    return strcmp(c_str(), s);
}

bool operator==(const myString &lhs, const myString &rhs)
{
    return (lhs.compare(rhs) == 0);
}

bool operator==(const char *lhs, const myString &rhs)
{
    return (rhs.compare(lhs) == 0);
}

bool operator==(const myString &lhs, const char *rhs)
{
    return (lhs.compare(rhs) == 0);
}

bool operator!=(const myString &lhs, const myString &rhs)
{
    return (lhs.compare(rhs) != 0);
}

bool operator!=(const char *lhs, const myString &rhs)
{
    return (rhs.compare(lhs) != 0);
}

bool operator!=(const myString &lhs, const char *rhs)
{
    return (lhs.compare(rhs) != 0);
}

bool operator<(const myString &lhs, const myString &rhs)
{
    return (lhs.compare(rhs) < 0);
}

bool operator<(const char *lhs, const myString &rhs)
{
    return (rhs.compare(lhs) >= 0);
}

bool operator<(const myString &lhs, const char *rhs)
{
    return (lhs.compare(rhs) < 0);
}

bool operator<=(const myString &lhs, const myString &rhs)
{
    return (lhs.compare(rhs) <= 0);
}

bool operator<=(const char *lhs, const myString &rhs)
{
    return (rhs.compare(lhs) > 0);
}

bool operator<=(const myString &lhs, const char *rhs)
{
    return (lhs.compare(rhs) <= 0);
}

bool operator>(const myString &lhs, const myString &rhs)
{
    return (lhs.compare(rhs) > 0);
}

bool operator>(const char *lhs, const myString &rhs)
{
    return (rhs.compare(lhs) <= 0);
}

bool operator>(const myString &lhs, const char *rhs)
{
    return (lhs.compare(rhs) > 0);
}

bool operator>=(const myString &lhs, const myString &rhs)
{
    return (lhs.compare(rhs) >= 0);
}

bool operator>=(const char *lhs, const myString &rhs)
{
    return (rhs.compare(lhs) < 0);
}

bool operator>=(const myString &lhs, const char *rhs)
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
        memset(_Bx._ptr, 0, 2 * strlen(s));
        strcpy(_Bx._ptr, s);
    }
    ssize = strlen(s);
    return *this;
}

myString &myString::operator=(const myString &str)
{
    if (ssize <= 15)
    {
        if (str.ssize <= 15)
        {
            memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
            strcpy(_Bx._Buf, str.c_str());
        }
        else
        {
            rrsize(str.ssize);
            strcpy(_Bx._ptr, str.c_str());
        }
    }
    else
    {
        if (str.ssize <= 15)
        {
            delete[] _Bx._ptr;
            memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
            strcpy(_Bx._Buf, str.c_str());
        }
        else
        {
            rrsize(str.ssize);
            memset(_Bx._ptr, 0, ssize);
            strcpy(_Bx._ptr, str.c_str());
        }
    }
    ssize = str.size();
    return *this;
}

myString &myString::operator+=(const char *s)
{
    size_t len = strlen(s);
    if (len + ssize <= 15)
    {
        strcat(_Bx._Buf, s);
        ssize = strlen(_Bx._Buf);
    }
    else
    {
        if (ssize <= 15)
        {
            ssize += len;
            char *tp = new char[ssize * 2];
            strcpy(tp, _Bx._Buf);
            strcat(tp, s);
            _Bx._ptr = tp;
        }
        else
        {
            ssize += len;
            char *tp = new char[ssize * 2];
            strcpy(tp, _Bx._ptr);
            strcat(tp, s);
            delete[] _Bx._ptr;
            _Bx._ptr = tp;
        }
    }
    return *this;
}

myString &myString::operator+=(char c)
{
    if (1 + ssize <= 15)
    {
        strcat(_Bx._Buf, (char *)&c);
        ssize++;
    }
    else
    {
        if (ssize <= 15)
        {
            ssize += 1;
            char *tp = new char[ssize * 2];
            strcpy(tp, _Bx._Buf);
            strcat(tp, (char *)&c);
            _Bx._ptr = tp;
        }
        else
        {
            ssize += 1;
            char *tp = new char[ssize * 2];
            strcpy(tp, _Bx._ptr);
            strcat(tp, (char *)&c);
            delete[] _Bx._ptr;
            _Bx._ptr = tp;
        }
    }
    return *this;
}

myString &myString::operator+=(const myString &str)
{
    std::cout << str.length() + ssize << std::endl;
    if (str.length() + ssize <= 15)
    {
        strcat(_Bx._Buf, str.c_str());
        ssize = strlen(_Bx._Buf);
    }
    else
    {
        if (ssize <= 15)
        {
            ssize += str.ssize;
            char *tp = new char[ssize * 2];
            strcpy(tp, _Bx._Buf);
            strcat(tp, str.c_str());
            _Bx._ptr = tp;
        }
        else
        {
            ssize += str.ssize;
            char *tp = new char[ssize * 2];
            strcpy(tp, _Bx._ptr);
            strcat(tp, str.c_str());
            delete[] _Bx._ptr;
            _Bx._ptr = tp;
        }
    }
    return *this;
}

myString operator+(const myString &lhs, const myString &rhs)
{
    myString str(lhs);
    str += rhs;
    return str;
}

myString operator+(const myString &lhs, const char *rhs)
{
    myString str(lhs);
    str += rhs;
    return str;
}

myString operator+(const char *lhs, const myString &rhs)
{
    myString str(lhs);
    str += rhs;
    return str;
}

myString operator+(const myString &lhs, char rhs)
{
    myString str(lhs);
    str += rhs;
    return str;
}

myString operator+(char lhs, const myString &rhs)
{
    myString str(&lhs);
    str += rhs;
    return str;
}

myString::myString()
{
    ssize = 0;
    memset(&_Bx, 0, sizeof(_Bx));
}

myString::myString(const myString &str)
{
    ssize = 0;
    memset(&_Bx, 0, sizeof(_Bx));
    if (str.ssize <= 15)
    {
        strcpy(_Bx._Buf, str.c_str());
    }
    else
    {
        rrsize(str.length());
        strcpy(_Bx._ptr, str.c_str());
    }
    ssize = str.length();
}

myString::myString(const char *s)
{
    ssize = 0;
    memset(&_Bx, 0, sizeof(_Bx));
    size_t tp = strlen(s);
    if (tp <= 15)
    {
        strcpy(_Bx._Buf, s);
        _Bx._Buf[tp] = '\0';
    }
    else
    {
        rrsize(tp);
        strcpy(_Bx._ptr, s);
        _Bx._ptr[tp] = '\0';
    }
    ssize = tp;
}

myString::myString(size_t n, char c)
{
    ssize = 0;
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
            _Bx._ptr[i] = c;
    }
    ssize = n;
}

myString::myString(const char *s, size_t n)
{
    ssize = 0;
    memset(&_Bx, 0, sizeof(_Bx));
    if (strlen(s) <= n)
    {
        ssize = strlen(s);
        if (n <= 15)
        {
            strcpy(_Bx._Buf, s);
        }
        else
        {
            rrsize(n);
            strcpy(_Bx._ptr, s);
        }
    }
    else
    {
        if (n <= 15)
        {
            strncpy(_Bx._Buf, s, n);
        }
        else
        {
            rrsize(n);
            strncpy(_Bx._ptr, s, n);
        }
        ssize = n;
    }
}

myString::myString(const myString &str, size_t pos, size_t len)
{
    ssize = 0;
    memset(&_Bx, 0, sizeof(_Bx));
    if (pos > str.ssize)
    {
        ssize = 0;
    }
    else
    {
        if (pos + len > str.ssize)
            ssize = str.ssize - pos;
        else
            ssize = len;

        if (ssize <= 15)
        {
            for (size_t i = 0; i < ssize; i++)
            {
                const char *p = str.c_str() + pos;
                _Bx._Buf[i] = p[i];
            }
            _Bx._Buf[ssize] = '\0';
        }
        else
        {
            rrsize(len + 1);
            const char *p = str.c_str() + pos;
            for (size_t i = 0; i < ssize; i++)
            {
                _Bx._ptr[i] = p[i];
            }
            _Bx._ptr[ssize] = '\0';
        }
    }
}

myString::~myString()
{
    if (ssize > 15 && _Bx._ptr != nullptr)
    {
        delete[] _Bx._ptr;
    }
}

inline  size_t myString::length() const noexcept
{
    return ssize;
}

inline  size_t myString::size() const noexcept
{
    return ssize;
}

inline void myString::clear() noexcept
{
    if (ssize <= 15)
    {
        _Bx._Buf[0] = '\0';
    }
    else
    {
        delete[] _Bx._ptr;
        _Bx._Buf[0] = '\0';
    }
    ssize = 0;
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
            return _Bx._ptr[0];
        }
    }
}

char myString::back() const
{
    if (ssize == 0)
        return '\0';
    else
    {
        if (ssize <= 15)
        {
            return _Bx._Buf[ssize - 1];
        }
        else
        {
            return _Bx._ptr[ssize - 1];
        }
    }
}

myString &myString::append(const myString &str)
{
    *this += str;
    return *this;
}
myString &myString::append(const char *s)
{
    *this += s;
    return *this;
}

inline myString &myString::assign(const myString &str)
{
    *this = str;
    return *this;
}
inline myString &myString::assign(const char *s)
{
    *this = s;
    return *this;
}

inline const char *myString::data() const
{
    if (ssize <= 15)
    {
        return _Bx._Buf;
    }
    else
    {
        return _Bx._ptr;
    }
}

inline char &myString::at(size_t pos)
{
    if (pos <= 15)
        return _Bx._Buf[pos];
    else
    {
        return _Bx._ptr[pos];
    }
}

inline const char &myString::at(size_t pos) const
{
    if (pos <= 15)
        return _Bx._Buf[pos];
    else
    {
        return _Bx._ptr[pos];
    }
}

const char *myString::getnext(const char *w)
{
    int wlen = strlen(w);

    char *next1 = new char[wlen + 1];
    int j = 0, k = -1;
    next1[0] = -1;

    while (j < wlen)
    {
        if (k == -1 || w[k] == w[j])
        {
            ++k;
            ++j;
            next1[j] = k;
        }
        else
        {
            k = next1[k];
        }
    }
    return next1;
}

const char *myString::fastfind(const myString &w)
{

    int tlen = w.ssize;
    const char *next1 = getnext(w.c_str());

    int i = 0, j = 0;
    while (j < tlen)
    {
        if (i == -1 || w[i] == at(j))
        {
            i++;
            j++;
        }
        else
        {
            i = next1[i];
        }
    }
    if (next1 != NULL)
    {
        delete[] next1;
    }

    if (j == tlen)
    {
        return (char *)&at(i - j);
    }
    else
    {
        return NULL;
    }
}

const char *myString::find(const myString &w) const
{
    return strstr(c_str(), w.c_str());
}

void myString::swap(myString &str)
{
    myString temp = std::move(*this);
    *this = std::move(str);
    str = std::move(temp);
    //mySwap(*this, str);
}
