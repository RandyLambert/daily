#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void elimDups(vector<string> &words)
{
    //按字典序排序Words，一边查找重复的单词
    words.reserve(5); //只改变capacity，不改变size，只有大小改变了，新位置没有初始化，但是这因为5个装不下，所以没改变
    cout<<words.size()<<endl;
    cout<<"ss"<<words.capacity()<<endl;

    sort(words.begin(),words.end());
    auto endunique = unique(words.begin(),words.end());
    cout<<words.size()<<endl;
    cout<<"ss"<<words.capacity()<<endl;
    words.erase(endunique,words.end());
    cout<<words.size()<<endl;
    cout<<"ss"<<words.capacity()<<endl;
    words.resize(6);//如果现在的大小够存，则不会改变capacity，如果不存，增大capacity和size，没有第二个函数则进行默认构造
    cout<<words.size()<<endl;
    cout<<"ss"<<words.capacity()<<endl;
    words.shrink_to_fit();
    cout<<words.size()<<endl;
    cout<<"ss"<<words.capacity()<<endl;
}

int main()
{
    vector<string> words {"ccc","aaa","qqq","aaa","ddd","fff","qqq","zzz"};
    elimDups(words);

    return 0;
}

