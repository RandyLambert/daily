#ifndef HUFUMAMM_H_
#define HUFUMAMM_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
typedef struct node
{
    char key = '\0'; //字符
    int weight = 0;  //权值（出现频次）
    struct node *LeftChild = nullptr;
    struct node *RightChild = nullptr;
    bool operator<(struct node *a)
    {
        return this->weight < a->weight;
    }
} Node;

class HuffMan
{
public:
    Node *root;
    explicit HuffMan(std::unordered_map<char, int> d); //传入一个map，其中存储了所有的字符及其出现的频次
    void Node_Copy(Node *a, Node *b);

    void PreOrder(Node *root); //先序遍历
};

#endif
