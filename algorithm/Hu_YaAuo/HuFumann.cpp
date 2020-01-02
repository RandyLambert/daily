#include "HuFumann.h"
using std::cout;
using std::cin;

int zi,du1,du2;
std::string ans1 = "";
struct ertree
{
public:
	char data;
	ertree *left;
	ertree *right;

	ertree(){
		left = NULL;
		right = NULL;
	}

	~ertree(){
		if(left!=NULL){
			delete left;
		}
		if(right!=NULL){
			delete right;
		}
	}
};

void createtree(ertree *&T)
{
	T = new ertree;
	char temp;
	cin>>temp;
	if(temp == '#')
	{
		T = NULL;
	}
	else{
		T->data = temp;
		createtree(T->left);
		createtree(T->right);
	}
}

void prebianli(ertree *&T){
	cout<<T->data;

	if(T->left!=NULL){
		prebianli(T->left);
	}
	//else cout<<'#';

	if(T->right!=NULL){
		prebianli(T->right);
	}
	//else cout<<'#';
}

void midbianli(ertree *&T){

	int flag = 0,tempdu = 0;
	if(T->left!=NULL){
		midbianli(T->left);
	}
	else flag++;

	cout<<T->data;

	if(T->right!=NULL){
		midbianli(T->right);
	}
	else flag++;

	if(flag==2){
		ans1.push_back(T->data);
		zi++;
		char c = T->data;

		//ans+=T->data;
	}
	else if(flag==1){
		du1++;
	}
	else if(flag==0){
		du2++;
	}
}

void backbianli(ertree *&T){

	if(T->left!=NULL){
		backbianli(T->left);
	}
	//else cout<<'#';

	if(T->right!=NULL){
		backbianli(T->right);
	}
	//else cout<<'#';

	cout<<T->data;
}

void cengbianli(ertree *&T){

	queue<ertree *>q;
	q.push(T);
	while(!q.empty()){
		ertree * temp = q.front();
		q.pop();

		if(temp->left !=NULL){
			q.push(temp->left);
		}
		if(temp->right != NULL){
			q.push(temp->right);
		}

		cout<<temp->data;
	}
}

