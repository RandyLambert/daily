#include "Init.h"

void Main_UI()
{
    char op;

    while (true)
    {
        cout << "*********************\n";
        cout << "Huffman文件压缩程序\n";
        cout << "【1】压缩文件\n";
        cout << "【2】解压文件\n";
        cout << "【3】退出\n";
        cout << "*********************\n";
        cin >> op;
        if (op != '1' && op != '2' && op != '3')
            cout << "error,选择错误,请重新选择" << endl;
        else if (op == '1')
        {
            File_Zip();
            continue;
        }
        else if (op == '2')
        {
            File_Uzip();
            continue;
        }
        else if (op == '3')
        {
            exit(0);
        }
    }
}

void File_Zip()
{
    map<char, int> mp;
    vector<pair<char, string>> code;
    myString Fil_open;
    cout << "请输入想要压缩的文件路径：";
    cin >> Fil_open;

    fstream ifile(Fil_open.c_str());
    if (!ifile)
    {
        cout << "fail open" << endl;
        exit(0);
    }

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
    ifile.close();

    HuffMan Htree(mp); //构建哈弗曼树
    string ans;
    Coding(code, ans, Htree.root);
    OutToBin(code, mp, Fil_open);
    code.clear();
}

void File_Uzip()
{
    char c, o, p, q;
    bitset<8> a;
    myString name;
    cout << "请输入想要解压的文件路径：";
    cin >> name;
    string strline, codestream; //strline存储二进制文件中的字符及对应权值，codestream存储01串
    fstream ifile(name.c_str(), ios::in | ios::binary);
    if (!ifile)
    {
        cout << "fail open" << endl;
        exit(0);
    }

    while (true) //从二进制文件中获取字符及对应权值
    {
        if (ifile.peek() == EOF)
            break;
        ifile.read(&o, 1);
        if (o == '*')
        {
            ifile.read(&p, 1);
            ifile.read(&q, 1);
            if (p == '@' && q == '#')
                break;
            else
                ifile.seekg(-2, ios::cur);
        }
        strline += o;
    }
    while (true) //读取字符转化为01串
    {
        if (ifile.peek() == EOF)
            break;
        ifile.read(&c, 1);
        a = c; //字符赋值给bitset<8>可直接转化为二进制
        codestream += a.to_string();
    }

    cout << "正在解压文件，请稍后..." << endl;
    OutToTxt(strline, codestream,name);
    cout << "解压完成，任意键退出" << endl;
    getchar();
    return ;
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

void OutToBin(vector<pair<char, string>> &codeorder, map<char, int> &mp, myString &name)
{

    fstream ifile(name.c_str()); //打开待压缩文件
    if (!ifile)
    {
        cout << "fail open" << endl;
        exit(0);
    }
    char c;
    string codestream; //01串
    //逐位读取文件中的字符，根据编码集将其转换为01串存储在codestream中
    while (true)
    {
        if (ifile.peek() == EOF)
            break;
        ifile.read(&c, 1);
        for (auto &iter : codeorder)
        {
            if (c == iter.first)
                codestream += iter.second;
        }
    }
    ifile.close();

    fstream ofile;
    name += ".zipp";
    ofile.open(name.c_str(), ios::out | ios::binary); //打开压缩后文件
    if (!ofile)
    {
        cout << "fail open" << endl;
        exit(0);
    }

    for (auto iter : mp)                              //字符及对应权值存储进二进制文件
    {
        ofile << iter.first << "~" << iter.second << " ";
    }
    ofile << "*@#"; //编码规则结束标记

    while (codestream.size() >= 8) //01串转换为字符并输出
    {
        bitset<8> bits(codestream, 0, 8);
        codestream.erase(0, 8);
        ofile << static_cast<char>(bits.to_ulong());
    }

    if (!codestream.empty()) //结尾长度不够八位，用0补齐，记录剩余的长度将其放在文件末尾，在读取时转换为下标位置还原本来的字符串
    {
        ulong loc = codestream.size();
        bitset<8> bits(codestream, 0, loc);
        ofile << static_cast<char>(bits.to_ulong());
        ofile << static_cast<char>(loc);
    }
    ofile.close();
}

void OutToTxt(string &strline, string &codestream,myString &name) //构建map，建哈弗曼树，遍历01串输出
{
    char a;
    int b;
    ulong t;
    string tmp;
    map<char, int> data;

    name+=".txt";
    fstream ofile(name.c_str(), ios::out); //打开压缩文件

    if (!ofile)
    {
        cout << "fail open" << endl;
        exit(0);
    }

    while (!strline.empty()) //读取其中存储的字符以及出现的频次，由此生成哈弗曼树
    {
        a = strline.at(0);
        strline.erase(0, 2);
        t = strline.find(' ');
        tmp = strline.substr(0, t);
        strline.erase(0, t + 1);
        b = stoi(tmp, nullptr, 10);
        data.insert(pair<char, int>(a, b));
    }
    HuffMan HTree(data); //建树
    Node *p = HTree.root;

    string end = codestream.substr(codestream.size() - 16, 16); //处理末尾不够八位的情况
    bitset<8> loc(end, 8, 16);
    ulong add = loc.to_ulong();
    end = end.substr(8 - add, add);
    codestream.erase(codestream.size() - 16, codestream.size());
    codestream += end;

    for (auto i : codestream) //用01串遍历哈弗曼树
    {
        if (i == '0') //遇0，走左
            p = p->LeftChild;
        if (i == '1') //遇1，走右
            p = p->RightChild;
        if (p->LeftChild == nullptr && p->RightChild == nullptr) //遇叶子节点，提取字符并存储
        {
            ofile << p->key;
            p = HTree.root;
        }
    }
}
