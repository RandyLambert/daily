#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
#include <cstring>
#include <cstdlib>

class myString
{
    friend std::ostream &operator<<(std::ostream &out, myString &str);
    friend std::istream &operator>>(std::istream &in, myString &str);
    friend std::istream& getline(std::istream& in, myString& str, char delim);
    friend std::istream& getline(std::istream& in, myString& str);

public:
    myString();
    myString(const myString &str);
    myString(const myString &str, size_t pos, size_t len);
    myString(const char *s);
    myString(const char *s, size_t n);
    myString(size_t n, char c);
    ~myString();
    void clear() noexcept;

    char& front() ;
    const char& front() const;
    char& back();
    const char& back() const;

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
    const char *data() const;
    bool empty() const;

    class iTerator{
    public:

        iTerator() {
            it = NULL;
            index = 0;
        }

        iTerator(const iTerator &rhs) {
            it = rhs.it;
            index = rhs.index;
        }

        iTerator(const myString *sp) {
            it = sp;
            index = 0;
        }

        iTerator(const myString *sp, int n) {
            it = sp;
            index = n;
        }

        ~iTerator() {
            it = NULL;
        }

        char operator*() {
            return it->at(index);
        }

        iTerator operator++(int) {//注意前缀运算符的&,后缀运算符无&（返回新的迭代器，即++之前的迭代器）
            iTerator copy(*this);
            operator++();
            return copy;
        }

        iTerator& operator++() {
            if (it == NULL) {
                std::cout << "迭代器未初始化！程序退出！\n";
                exit(1);
            }
            index++;
            if (index > it->size())
                it = NULL;
            return *this;
        }

        iTerator operator--(int) {
            iTerator copy(*this);
            operator--();
            return copy;
        }

        iTerator& operator--() {
            if (it == NULL) {
                std::cout << "迭代器未初始化！程序退出！\n";
                exit(1);
            }
            index--;
            if (index > it->size() || index < 0)//越界
                it = NULL;
            return *this;
        }

        bool operator==(const iTerator &rhs) {
            if (it != rhs.it) {
                std::cout << "不同String迭代器！程序退出！==\n";
                exit(1);
            }
            return (it == rhs.it && index == rhs.index);
        }

        bool operator!=(const iTerator &rhs) {
            if (it != rhs.it) {
                std::cout << "不同String迭代器！程序退出！!=\n";
                exit(1);
            }
            return !(*this == rhs);
        }

        bool operator<(const iTerator &rhs) {
            if (it != rhs.it) {
                std::cout << "不同String迭代器！程序退出！<\n";
                exit(1);
            }
            return (index < rhs.index);
        }

        bool operator<=(const iTerator &rhs) {
            if (it != rhs.it) {
                std::cout << "不同String迭代器！程序退出！<=\n";
                exit(1);
            }
            return (index <= rhs.index);
        }

        bool operator>(const iTerator &rhs) {
            if (it != rhs.it) {
                std::cout << "不同String迭代器！程序退出！>\n";
                exit(1);
            }
            return (index > rhs.index);
        }

        bool operator>=(const iTerator &rhs) {
            if (it != rhs.it) {
                std::cout << "不同String迭代器！程序退出！>=\n";
                exit(1);
            }
            return (index >= rhs.index);
        }

        iTerator operator+(const int k) {
            if (it == NULL) {
                std::cout << "迭代器未初始化！程序退出！\n";
                exit(1);
            }
            return iTerator(it, index + k);
        }

        iTerator operator-(const int k) {
            if (it == NULL) {
                std::cout << "迭代器未初始化！程序退出！\n";
                exit(1);
            }
            return iTerator(it, index - k);
        }

        //        friend class String;
    private:
        const myString* it;
        size_t index;
    };

    iTerator begin() const {
        return iTerator(this, 0);
    }

    iTerator end() const {
        return iTerator(this, size());
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
