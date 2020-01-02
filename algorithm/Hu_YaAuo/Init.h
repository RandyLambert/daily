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

#endif
