#ifndef TEMPLATE_TOOL_HPP_
#define TEMPLATE_TOOL_HPP_
#include <iostream>

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
template<typename T>
T mySwap(T &a ,T &b){
    T temp = std::move(a);
    a = std::move(b);
    b =  std::move(temp);
}

//快拍
template<typename T>
void mySort(T &arr,size_t l,size_t r){

    if(l >= r) return ;
    int i = l - 1,j = r + 1,x = arr[l + r>>1];

    while(i < j){
        do j--; while(arr[j] > x);
        do i++; while(arr[i] < x);
        if(i < j) mySwap<T>(arr[i],arr[j]);
        else mySort<T>(arr,l,j) , mySort(arr,j+1,r);
    }
}

class myString {
public:
	myString();
	myString(const myString& str);
	myString(const myString& str, size_t pos, size_t len = npos);
	myString(const char* s);
	myString(const char* s, size_t n);
	myString(size_t n, char c);
	~myString();

	const char* c_str() const;
	size_t length() const;
	size_t size() const;

	char& operator [] (size_t pos);
	const char& operator [] (size_t pos) const;
	myString& operator = (const myString& str);
	myString& operator = (const char* s);
	myString& operator = (char c);
	myString& operator += (const myString& str);
	myString& operator += (const char* s);
	myString& operator += (char c);

	myString& append(const myString& str);
	myString& append(const char* s);

	myString& assign(const myString& str);
	myString& assign(const char* s);

	char& at(size_t pos);
	const char& at(size_t pos) const;

	void clear();

	int compare(const myString& str) const;
	int compare(const char* s) const;

	const char* data() const;
	bool empty() const;

	static const size_t npos = -1;
	size_t _size;

private:
    /* int8_t BUF_SIZE = 16; */
    
    union _Bxty
    {
        char _Buf[16];
        char* _ptr;
    } _Bx;
}; 

#endif
