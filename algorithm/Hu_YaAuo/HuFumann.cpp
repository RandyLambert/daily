#include "HuFumann.h"

HuffMan:: HuffMan(std::unordered_map<char,int> d)  //传入一个map，其中存储了所有的字符及其出现的频次
    {
        std::vector<Node *> weight_order;
        // 遍历map，将其中的字符以及权值存储到各个叶子节点（node）中，将这些节点放在一个vector里面
        for(auto iter : d)
        {
            auto tmp = new Node;
            tmp -> key = iter.first;
            tmp -> weight = iter.second;
            weight_order.push_back(tmp);
        }
        // 根据先前的思想，我们至少应该同时获取两个节点的信息才能构建哈弗曼树，那么假如传入只有一个节点，就要进行特殊化处理
        if(weight_order.size() == 1)
        {
            auto tmp = new Node;
            auto t = new Node;
            tmp -> weight = weight_order[0] -> weight;
            Node_Copy(t,weight_order[0]);
            weight_order.erase(weight_order.begin());
            tmp -> LeftChild = t;
            tmp -> RightChild = nullptr;
            weight_order.push_back(tmp);
        }
        
        //正常情况下，节点数大于等于2，此时则需要不断地排序，建树，删除旧的两个节点，加入一个新的节点，直到最终vector中仅剩余一个节点（根节点）
        while(weight_order.size() != 1)
        {
            sort(weight_order.begin(),weight_order.end());  //排序

            
            auto tmp = new Node;
            tmp -> weight = weight_order[0] -> weight + weight_order[1] -> weight;
            auto carbon1 = new Node;
            auto carbon2 = new Node;
            Node_Copy(carbon1,weight_order[0]);
            Node_Copy(carbon2,weight_order[1]);
            tmp -> LeftChild = carbon1;  //建树
            tmp -> RightChild = carbon2;
            weight_order.erase(weight_order.begin(),weight_order.begin()+2); //删点
            weight_order.push_back(tmp);  //加点
        }
        
        this -> root = weight_order[0]; //最终让vector中的节点作为哈弗曼树的根节点
    }

     void HuffMan::Node_Copy(Node *a,Node *b)
    {
        a->key=b->key;
        a->weight=b->weight;
        a->LeftChild=b->LeftChild;
        a->RightChild=b->RightChild;
    }

    void HuffMan::PreOrder(Node *root)  //先序遍历
   {
       if(root == nullptr)
       {
           return;
       }
       cout << root -> key << " " << root -> weight << endl;
       PreOrder(root -> LeftChild);
       PreOrder(root -> RightChild);
    }
