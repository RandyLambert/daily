#include<bits/stdc++.h>
using namespace std;

const int max_word = 505;
char token[12];
char in[105];
FILE *fin,*fout;
int cnt = 0,token_num = 0;
int row = 1;
int flag = 0;
char ch;
//关键字 
const char keyWord[13][20] = {"main","if","else","do","while","for","switch",
"case","int","double","float","long","void"};


void init_token(){
	int i;
	for(i = 0;i < 12;i++){
		token[i] = NULL;
	}
}

int judge_token(){
	init_token();
	if(flag == 0){
		ch = getc(fin);
	}
	flag = 1;
	while(ch == ' ' || ch == '\t' || ch == '\n'){
		if(ch == '\n'){
			row++;
		}
		ch=getc(fin);
	}
	token_num = 0;
	if((ch>='a' && ch <= 'z') || (ch >= 'A' &&ch <= 'Z')){
		//可能为标识符或者变量名 
		while((ch>='a' && ch <= 'z') || (ch >= 'A' &&ch <= 'Z') || (ch >= '0' && ch <= '9')){
			token[token_num++] = ch;
			ch = getc(fin);
		}
		token[token_num++] = '\0';
		for(int i = 0;i <13;i++){
			if(strcmp(token,keyWord[i]) == 0){
				//3为关键词 
				return 3;
			}
		}
		//2为标识符 
		return 2;
	}
	//是数字 
	else if(ch >= '0' && ch <= '9'){
		while((ch >= '0'&& ch <= '9') || ch == '.'){
			token[token_num++] = ch;
			ch = getc(fin);
		}
		return 1;
	}
	else{
		token[token_num++] = ch;
		switch(ch){
			case '(': ch = getc(fin); return 16;
			case ')': ch = getc(fin); return 17;
			case '{': ch = getc(fin); return 33;
			case '}': ch = getc(fin); return 34;
			case '+':
				ch = getc(fin);
				if(ch == '+'){
					token[token_num++] = ch;
					ch = getc(fin); 
					return 29;
				}
				else{
					return 18;
				}
			case '-':
				ch = getc(fin);
				if(ch == '-'){
					token[token_num++] = ch;
					ch = getc(fin); 
					return 30;
				}
				else{
					return 19;
				}
			case '*':
				ch = getc(fin);
				if(ch == '/'){
					token[token_num++] = ch;
					ch = getc(fin); 
					return 32;
				}
				else{
					return 20;
				}
			case '/':
				ch = getc(fin);
				if(ch == '*'){
					token[token_num++] = ch;
					ch = getc(fin); 
					return 31;
				}
				else{ 
					return 21;
				}
			//这里要重新编码 
			case '=':
				ch = getc(fin);
				if(ch == '='){
					token[token_num++] = ch;
					ch = getc(fin); 
					return 23;
				}
				else{
					return 22;
				}
			case '>':
				ch = getc(fin);
				if(ch == '='){
					token[token_num++] = ch;
					ch = getc(fin); 
					return 24;
				}
				else{
					return 23;
				}
			case '<':
				ch = getc(fin);
				if(ch == '='){
					token[token_num++] = ch;
					ch = getc(fin); 
					return 26;
				}
				else{
					return 25;
				}
			case ';': ch = getc(fin); return 27;
			case '"': ch = getc(fin); return 28;
			case '!':
				ch = getc(fin);
				if(ch == '='){
					token[token_num++] = ch;
					ch = getc(fin); 
					return 37;
				}
				else{
					return 36;
				}
			case '#': ch = getc(fin); return -2;
			case ',': ch = getc(fin); return 35;
			case EOF: return -1;
			default: ch = getc(fin); return -10;
		}
	}
}

void getWord(){
	int temp;
	while(1){
		temp = judge_token();
		if(temp==-1){
			break;
		}
		switch(temp){
			case -10:
				cout<<"第 "<<row<<" 行出现错误."<<endl;
				break;
			default:
				cout<<"<"<<temp<<","<<token<<">"<<endl;
				break;
		}
	}
}

int main(){
	fin = fopen("compiler.txt","r");
	getWord();
	return 0;
}

