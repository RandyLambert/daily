#include "main.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
    char op;
	char path[90];
	memset(path,0,sizeof(path));
    cout<<"*********************\n";
	cout<<"huffman文件压缩程序\n";
	cout<<"【1】压缩文件\n";
	cout<<"【2】解压文件\n";
	cout<<"【3】退出\n";
    cout<<"*********************\n";

	while(cin>>op)
	{
		if(op!='1'&&op!='2'&&op!='3')
			puts("error,选择错误,请重新选择");
		else
			break;
	}
	if(op=='3'){
		exit(0);
	}


	huffman_init(&huf);
	fflush(stdin);
    puts("输入文件路径： 例如H:\\12.txt");
    fgets(path,sizeof(path),stdin);//读入要翻译的文件的路径
    if(read_file(&huf,path)==0){
        puts("error");
        return 0;
    }
	switch(op)
	{
		case '1':

			stat_frequency(&huf);
			/*for(char i='a';i<='z';i++)
                printf("%c: %d\n",i,huf.freq[i]);*/
			build_huffman(&huf);
			puts("输入生成的压缩文件路径： 例如H:\\12.txt");
			write_code_file(&huf);
			puts("正在写入压缩文件，请稍后...\n");
			puts("写入完成，任意键退出");
			getchar();
			break;
		case '2':
			puts("输入生成的解压文件路径： 例如H:\\12.txt");
			rebuild_huffman(&huf);
			puts("正在解压文件，请稍后...");
			puts("解压完成，任意键退出");
			getchar();
			break;

	}

    return 0;
}
