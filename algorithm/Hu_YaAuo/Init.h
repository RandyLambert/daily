#ifndef INIT_H_
#define INIT_H_
#include "Template_Tool.hpp"
#include "HuFumann.h"
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void File_Init();
void Coding(vector<pair<char,string>> &codeorder,string &tp,Node *root);

void OutToBinFile(vector<pair<char,string>> *codeorder,unordered_map<char,int> &mp)
{
    ifstream infile("./ya.txt"); //打开待压缩文件
    if(!infile)
    {
        cout << "fail open" << endl;
        exit(0);
    }
    char c;
    string codestream;  //01串
    //逐位读取文件中的字符，根据编码集将其转换为01串存储在codestream中
    while(true)
    {
        if(infile.peek() == EOF)
            break;
        infile.read(&c,1);
        for(auto iter : *codeorder)
        {
            if(c == iter.first)
               codestream += iter.second;
        }
    }
    infile.close();
    fstream outfile;
    outfile.open("./ya.txt",ios::out | ios::binary);  //打开压缩后文件
    for(auto iter : mp)  //字符及对应权值存储进二进制文件
    {
        outfile << iter.first << "~" << iter.second << " ";
    }
    outfile << "*@#";  //编码规则结束标记
    while(codestream.size() >= 8)   //01串转换为字符并输出
    {
        /* bitset<8> bits(codestream,0,8); */
        codestream.erase(0,8);
        /* outfile << static_cast<char>(bits.to_ulong()); */
    }
    if(!codestream.empty())   //结尾长度不够八位，用0补齐，记录剩余的长度将其放在文件末尾，在读取时转换为下标位置还原本来的字符串
    {
        ulong loc = codestream.size();
        /* bitset<8> bits(codestream,0,loc); */
        /* outfile << static_cast<char>(bits.to_ulong()); */
        outfile << static_cast<char>(loc);
    }
    outfile.close();
}

void input();
#endif
