#include "Init.h"

int getBit(std::ifstream &ifile)
{
    static int i = 0;        //用来计数返回了几位了
    static unsigned char ch; //接受读取到的信息
    unsigned char bit[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    i++;
    if (i == 8)
    {
        ch = ifile.get();
        i = 0;
    }
    return ch & bit[i];
}

void Main_UI()
{
    char op;
    char path[90];
    memset(path, 0, sizeof(path));
    cout << "*********************\n";
    cout << "Huffman文件压缩程序\n";
    cout << "【1】压缩文件\n";
    cout << "【2】解压文件\n";
    cout << "【3】退出\n";
    cout << "*********************\n";

    while (cin >> op)
    {
        if (op != '1' && op != '2' && op != '3')
            puts("error,选择错误,请重新选择");
        else if (op == '1')
        {
            File_Init();
            break;
        }
        else if (op == '3')
        {
            exit(0);
        }
    }
}

void File_Init()
{
    unordered_map<char,int>mp;
    vector<pair<char,string>> code;

    std::ifstream ifile;
    cout << "请输入文件路径：";
    myString Fil_open;
    cin >> Fil_open;
    ifile.open(Fil_open.c_str());
    if (!ifile)
    {
        cout << "fail open" << endl;
        exit(0);
    }

    ifile.close();

    char tp;
    while (true)
    {
        ifile.read(&tp, 1);
        if (ifile.peek() == EOF)
        {
            break;
        }
        mp[tp] += 1;
    }
    HuffMan Htree(mp); //构建哈弗曼树
    string ans;
    Coding(code, ans, Htree.root);
    OutToBinFile(code,mp);
    code.clear();
}


void Coding(vector<pair<char, string>> &codeorder, string &tp, Node *root)
{
    if (root->LeftChild == nullptr && root->RightChild == nullptr) //遇到叶子节点
    {
        pair<char, string> t;
        t.first = root->key;
        t.second = tp;
        codeorder.push_back(t);
        tp.pop_back();
        return;
    }
    if (root->LeftChild) //若左子树，则tmp+='0'
    {
        tp += "0";
        Coding(codeorder, tp, root->LeftChild);
    }
    if (root->RightChild) //若右子树，则tmp+='1'
    {
        tp += "1";
        Coding(codeorder, tp, root->RightChild);
    }
    if (tp.length())
        tp.pop_back(); //逐层返回的时候一定要删掉最后的一个字符
}


void OutToBinFile(vector<pair<char, string>> &codeorder, unordered_map<char, int> &mp)
{
    ifstream infile("./ya.txt"); //打开待压缩文件
    if (!infile)
    {
        cout << "fail open" << endl;
        exit(0);
    }
    char c;
    string codestream; //01串
    //逐位读取文件中的字符，根据编码集将其转换为01串存储在codestream中
    while (true)
    {
        if (infile.peek() == EOF)
            break;
        infile.read(&c, 1);
        for (auto iter : *codeorder)
        {
            if (c == iter.first)
                codestream += iter.second;
        }
    }
    infile.close();
    fstream outfile;
    outfile.open("./ya.txt", ios::out | ios::binary); //打开压缩后文件
    for (auto iter : mp)                              //字符及对应权值存储进二进制文件
    {
        outfile << iter.first << "~" << iter.second << " ";
    }
    outfile << "*@#";              //编码规则结束标记
    while (codestream.size() >= 8) //01串转换为字符并输出
    {
        /* bitset<8> bits(codestream,0,8); */
        codestream.erase(0, 8);
        /* outfile << static_cast<char>(bits.to_ulong()); */
    }
    if (!codestream.empty()) //结尾长度不够八位，用0补齐，记录剩余的长度将其放在文件末尾，在读取时转换为下标位置还原本来的字符串
    {
        ulong loc = codestream.size();
        /* bitset<8> bits(codestream,0,loc); */
        /* outfile << static_cast<char>(bits.to_ulong()); */
        outfile << static_cast<char>(loc);
    }
    outfile.close();
}



void OutToTxt(string *strline, string *codestream) //构建map，建哈弗曼树，遍历01串输出
{
    char a;
    int b;
    ulong t;
    string tmp;
    unordered_map<char, int> data_b;
    fstream outfile_t("yo.txt", ios::out); //打开压缩文件

    while (!strline->empty()) //读取其中存储的字符以及出现的频次，由此生成哈弗曼树
    {
        a = strline->at(0);
        strline->erase(0, 2);
        t = strline->find(' ');
        tmp = strline->substr(0, t);
        strline->erase(0, t + 1);
        b = stoi(tmp, nullptr, 10);
        data_b.insert(pair<char, int>(a, b));
    }
    HuffMan HTree(data_b); //建树
    Node *p = HTree.root;

    string end = codestream->substr(codestream->size() - 16, 16); //处理末尾不够八位的情况
    bitset<8> loc(end, 8, 16);
    ulong add = loc.to_ulong();
    end = end.substr(8 - add, add);
    codestream->erase(codestream->size() - 16, codestream->size());
    *codestream += end;

    for (auto i : *codestream) //用01串遍历哈弗曼树
    {
        if (i == '0') //遇0，走左
            p = p->LeftChild;
        if (i == '1') //遇1，走右
            p = p->RightChild;
        if (p->LeftChild == nullptr && p->RightChild == nullptr) //遇叶子节点，提取字符并存储
        {
            outfile_t << p->key;
            p = HTree.root;
        }
    }
}
