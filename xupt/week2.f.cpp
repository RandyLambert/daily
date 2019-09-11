#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;
map<int,int>q;
char text[15]; 
int main(){
    q['A'] = 'V';
    q['B'] = 'W';
    q['C'] = 'X';
    q['D'] = 'Y';
    q['E'] = 'Z';
    q['F'] = 'A';
    q['G'] = 'B';
    q['H'] = 'C';
    q['I'] = 'D';
    q['J'] = 'E';
    q['K'] = 'F';
    q['L'] = 'G';
    q['M'] = 'H';
    q['N'] = 'I';
    q['O'] = 'J';
    q['P'] = 'K';
    q['Q'] = 'L';
    q['R'] = 'M';
    q['S'] = 'N';
    q['T'] = 'O';
    q['U'] = 'P';
    q['V'] = 'Q';
    q['W'] = 'R';
    q['X'] = 'S';
    q['Y'] = 'T';
    q['Z'] = 'U';
    q[' '] = ' ';
    q[','] = ',';
    memset(text,0,sizeof(text));
    while(scanf("%s",text)){
        if(!(text[0] == 'S'&&text[1] == 'T'&&text[2] == 'A'&&text[3] == 'R'&&text[4] == 'T')){
            break;
        }
        getchar();
        char c = 2;
        memset(text,0,sizeof(text));
        while(scanf("%c",&c)&&c!='\n'){
            if(q[c] == 0){
                printf("%c",c);
            }
            else
                printf("%c",q[c]);
        }
        putchar('\n');
        scanf("%s",text);
    }

    return 0;
}

