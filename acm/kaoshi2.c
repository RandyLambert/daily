#include <stdio.h>
#include <time.h>
#define ElemType char
#define NodeNum 5
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
 
void CreateTree(BiTree &root)
{
	int i=1, flag;
	BiTree node, pre, p;
	srand((unsigned)time(NULL));
	while(i++ <= NodeNum)
	{
		node = new BiTNode;		
		node->lchild = NULL;
		node->rchild = NULL;
		if(NULL == root)
		{
			root = node;
		}
		else
		{
			p = pre = root;
			printf("(向左向右?)请输入:");
			while(NULL != p)
			{
                scanf("%d",flag);
				pre = p;
				if(0 == flag)
				{
					p = p->lchild;
				}
				else
				{
					p = p->rchild;
				}
			}
			printf("选择插入方向:");
			scanf("%d",&flag);
			if(0 == flag)
			{
				pre->lchild = node;
			}
			else
			{
				pre->rchild = node;
			}
		}
	}
}
long LeafCount(BiTree root)//计算二叉树中叶子结点数目的递归算法
{
	if(NULL == root)
	{
		return 0;//树为空时返回 0
	}
	else if(NULL == root->lchild && NULL == root->rchild)
	{
		return 1;//只有一个结点的树返回 1
	}
	else
	{//返回左右子树的叶子结点之和
		return LeafCount(root->lchild) + LeafCount(root->rchild);
	}
}
int main()
{
	BiTree root = NULL;
	CreateTree(root);
 
	long count = LeafCount(root);
    printf("%ld",count);
 

}
