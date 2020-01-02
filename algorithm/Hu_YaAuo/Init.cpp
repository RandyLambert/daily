#include "Init.h"
extern std::unordered_map<char,int>mp;
extern std::vector<pair<char,string>> code;
enum{MAX_LEN = 1024};

int getBit(std::ifstream &ifile)
{
	static int i = 0;//用来计数返回了几位了
	static unsigned char ch;//接受读取到的信息
	unsigned char bit[8] = {128,64,32,16,8,4,2,1};
	i++;
	if(i == 8)
	{
		ch = ifile.get();
		i = 0;
	}
	return ch&bit[i];
}

void File_Init(){

    std::ifstream ifile;
    cout<<"请输入文件名：";
    /* cin>>; */
    ifile.open("./ya.txt");
    if(!ifile){
        cout<<"fail open"<<endl;
        exit(0);
    }
    ifile.close();

    char tp;
    while(true){
        ifile.read(&tp,1);
        if(ifile.peek() == EOF){
            break;
        }
        mp[tp]+=1;
    }
    HuffMan Htree(mp);  //构建哈弗曼树
    string ans;
    Coding(code,ans,Htree.root);
}


void Coding(vector<pair<char,string>> &codeorder,string &tp,Node *root){
    if(root->LeftChild == nullptr && root-> RightChild == nullptr) //遇到叶子节点
    {
        pair<char,string> t;
        t.first = root->key;
        t.second = tp;
        codeorder.push_back(t);
        tp.pop_back();
        return;
    }
    if(root->LeftChild)  //若左子树，则tmp+='0'
    {
        tp+="0";
        Coding(codeorder,tp,root->LeftChild);
    }if(root->RightChild)  //若右子树，则tmp+='1'
    {
        tp+="1";
        Coding(codeorder,tp,root->RightChild);
    }
    if(tp.length())
    tp.pop_back();//逐层返回的时候一定要删掉最后的一个字符


}
