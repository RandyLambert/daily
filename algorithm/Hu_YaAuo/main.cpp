#include "main.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
    
	Main_UI();

    
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
