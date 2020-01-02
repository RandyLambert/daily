#ifndef INIT_H_
#define INIT_H_
#include "Template_Tool.hpp"
#include "HuFumann.h"
#include <bitset>
#include <unordered_map>
#include "myString.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


enum{MAX_LEN = 1024};



int getBit(std::ifstream &ifile);
void File_Init();
void Coding(vector<pair<char,string>> &codeorder,string &tp,Node *root);
void OutToBinFile(vector<pair<char,string>> *codeorder,unordered_map<char,int> &mp);
void OutToTxt(string *strline,string *codestream);   //构建map，建哈弗曼树，遍历01串输出
void input();
void Main_UI();


#endif
