#ifndef INIT_H_
#define INIT_H_
#include "HuFumann.h"
#include <bitset>
#include <map>
#include "myString.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


void File_Zip();
void File_Uzip();
void Coding(vector<pair<char,string>> &codeorder,string &tp,Node *root);
void OutToBin(vector<pair<char,string>> &codeorder,map<char,int> &mp,myString &name);
void OutToTxt(string &strline,string &codestream,myString &name);   //构建map，建哈弗曼树，遍历01串输出
void Main_UI();

#endif
