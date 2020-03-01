#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>

template <typename T>
class iTerator
{
public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;

    iTerator():it(nullptr),index(0) {}
    iTerator(const value_type *sp):it(sp),index(0) {}
    iTerator(const iTerator<value_type> &rhs):it(rhs.it),index(rhs.index){}
    iTerator(const value_type *sp, int n):it(sp),index(n) {}
    ~iTerator() { it = NULL; }

    char operator*(){return *(it->data() + index);}

    iTerator<value_type> operator++(int)
    {
        iTerator<value_type> copy(*this);
        operator++();
        return copy;
    }

    iTerator<value_type> &operator++()
    {
        try
        {
            if (it == NULL)
            {
                throw "迭代器未初始化";
            }
            else
            {
                index++;
                if (index > it->size())
                    it = NULL;
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
        return *this;
    }

    iTerator<value_type> operator--(int)
    {
        iTerator<value_type> copy(*this);
        operator--();
        return copy;
    }

    iTerator<value_type> &operator--()
    {
        try
        {
            if (it == NULL)
            {
                throw "迭代器未初始化";
            }
            else
            {
                index--;
                if (index > it->size() || index < 0) //越界
                    it = NULL;
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
        return *this;
    }

    bool operator==(const iTerator<value_type> &rhs)
    {
        try
        {
            if (it != rhs.it)
            {
                throw "迭代器不同，==无法比较";
            }
            else
            {
                return (it == rhs.it && index == rhs.index);
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
    }

    bool operator!=(const iTerator<value_type> &rhs)
    {
        try
        {
            if (it != rhs.it)
            {
                throw "迭代器不同，!=无法比较";
            }
            else
            {
                return !(*this == rhs);
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
    }

    bool operator<(const iTerator<value_type> &rhs)
    {
        try
        {
            if (it != rhs.it)
            {
                throw "迭代器不同，<无法比较";
            }
            else
            {
                return (index < rhs.index);
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
    }

    bool operator<=(const iTerator<value_type> &rhs)
    {
        try
        {
            if (it != rhs.it)
            {
                throw "迭代器不同，<=无法比较";
            }
            else
            {
                return (index <= rhs.index);
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
    }

    bool operator>(const iTerator<value_type> &rhs)
    {
        try
        {
            if (it != rhs.it)
            {
                throw "迭代器不同，>无法比较";
            }
            else
            {
                return (index > rhs.index);
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
    }

    bool operator>=(const iTerator<value_type> &rhs)
    {
        try
        {
            if (it != rhs.it)
            {
                throw "迭代器不同，>=无法比较";
            }
            else
            {
                return (index >= rhs.index);
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
    }

    iTerator<value_type> operator+(const int k)
    {
        try
        {
            if (it == NULL)
            {
                throw "迭代器未初始化";
            }
            else
            {
                return iTerator<value_type>(it, index + k);
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
    }

    iTerator<value_type> operator-(const int k)
    {
        try
        {
            if (it == NULL)
            {
                throw  "迭代器未初始化";
            }
            else
            {
                return iTerator<value_type>(it, index - k);
            }
        }
        catch (const char * tp)
        {
            std::cerr << tp << std::endl;
        }
    }

private:
    const value_type *it;
    int index;
};

#endif
