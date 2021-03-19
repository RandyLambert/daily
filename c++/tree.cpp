#include <iostream>

using namespace std;

typedef struct BitNode {			//创建二叉树的结构体;
	char data;
	BitNode *lchild, *rchild;
	BitNode(char ch)				//添加创建新结点的构造函数;
	{
		lchild = NULL;
		rchild = NULL;
		data = ch;
	}

}*Tree, Node;

void CreateTree(Tree &p)			//先序遍历创建二叉树;
{
	char ch;
	cin >> ch;						//输入字符;
	if (ch == '#')					//判断字符是否为结束当前结点的创建;
		p = NULL;
	else {
		p = new Node(ch);			//调用构造函数创建一个新结点，并且数据域赋值为ch;
		CreateTree(p->lchild);		//创建左结点;
		CreateTree(p->rchild);		//创建右结点;
	}
}

int Depth(Tree &p)					//递归法检查二叉树的深度;
{
	int l, r;
	if (p == NULL)					//判断当前结点是否为当前子树的尾部;
		return 0;
	else {							//如果不是尾部;
		l = Depth(p->lchild);		
		r = Depth(p->rchild);
		return l > r ? l + 1 : r + 1;	//比较当前结点的左右子树的深度，并返回较大值+1;
	}
}

int main()
{
	int dh;							//声明深度变量;
	Tree p=NULL;					//创建二叉树的根节点;
	CreateTree(p);					//调用创建二叉树的函数;
	dh = Depth(p);					//调用检查二叉树深度的函数，并且返回值赋值给dh;
	cout << "sss：" << dh;	//输出树的深度;
	return 0;
}
