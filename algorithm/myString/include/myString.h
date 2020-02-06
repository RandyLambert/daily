#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "../iTerator.hpp"
class myString
{
    friend std::ostream &operator<<(std::ostream &out, myString &str);
    friend std::istream &operator>>(std::istream &in, myString &str);
    friend std::istream &getline(std::istream &in, myString &str, char delim);
    friend std::istream &getline(std::istream &in, myString &str);

public:
    myString();
    myString(const myString &str);
    myString(const myString &str, size_t pos, size_t len);
    myString(const char *s);
    myString(const char *s, size_t n);
    myString(size_t n, char c);
    ~myString();
    void clear() noexcept;

    char &front() { return at(0); }
    const char &front() const { return at(0); }
    char &back() { return at(ssize - 1); }
    const char &back() const { return at(ssize - 1); }

    const char *c_str() const;
    size_t length() const noexcept;
    size_t size() const noexcept;
    const char *find(const myString &w) const;
    const char *fastfind(const myString &w);

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
    void swap(myString &str);
    void push_back(char c) { *this += c; }
    const char *data() const;
    bool empty() const;
    iTerator<myString> begin() const
    {
        return iTerator<myString>(this, 0);
    }

    iTerator<myString> end() const
    {
        return iTerator<myString>(this,size());
    }

private:
    enum
    {
        BUF_LEN = 16
    };

    size_t ssize;
    union _Bxty {
        char _Buf[BUF_LEN];
        char *_ptr;
    } _Bx;

    void rrsize(size_t x);              //扩容
    const char *getnext(const char *w); //kmp
};

bool operator==(const myString &lhs, const myString &rhs);
bool operator==(const char *lhs, const myString &rhs);
bool operator==(const myString &lhs, const char *rhs);
bool operator!=(const myString &lhs, const myString &rhs);
bool operator!=(const char *lhs, const myString &rhs);
bool operator!=(const myString &lhs, const char *rhs);
bool operator<(const myString &lhs, const myString &rhs);
bool operator<(const char *lhs, const myString &rhs);
bool operator<(const myString &lhs, const char *rhs);
bool operator<=(const myString &lhs, const myString &rhs);
bool operator<=(const char *lhs, const myString &rhs);
bool operator<=(const myString &lhs, const char *rhs);
bool operator>(const myString &lhs, const myString &rhs);
bool operator>(const char *lhs, const myString &rhs);
bool operator>(const myString &lhs, const char *rhs);
bool operator>=(const myString &lhs, const myString &rhs);
bool operator>=(const char *lhs, const myString &rhs);
bool operator>=(const myString &lhs, const char *rhs);
myString operator+(const myString &lhs, const myString &rhs);
myString operator+(const myString &lhs, const char *rhs);
myString operator+(const char *lhs, const myString &rhs);
myString operator+(const myString &lhs, char rhs);
myString operator+(char lhs, const myString &rhs);

#endif