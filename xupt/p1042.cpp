#include <cstdio>

using namespace std;

int ww11[100001],ll11[100001],ww21[100001],ll21[100001];
int main(){
    char a;
    int w11 = 0,w21 = 0,l11 = 0,l21 = 0,i = 0,j = 0;
    while(scanf("%c",&a)&&a!='E'){
        if(a == 'W'){
            w11++;
            w21++;
            if(w11 >= 11 && l11 <= w11-2){
                ww11[i] = w11;
                ll11[i] = l11;
                w11 = 0;
                l11 = 0;
                i++;
            }
            if(w21 >= 21 && l21 <= w21-2){
                ww21[j] = w21;
                ll21[j] = l21;
                w21 = 0;
                l21 = 0;
                j++;
            }
        }
        if(a == 'L'){
            l11++;
            l21++;
            if(l11 >= 11 && w11 <= l11-2){
                ww11[i] = w11;
                ll11[i] = l11;
                w11 = 0;
                l11 = 0;
                i++;
            }
            if(l21 == 21 && w21 <= l21-2){
                ww21[j] = w21;
                ll21[j] = l21;
                w21 = 0;
                l21 = 0;
                j++;
            }
        }
    }
    for(int ii = 0;ii < i;ii++){
        printf("%d:%d\n",ww11[ii],ll11[ii]);
    }
    printf("%d:%d\n",w11,l11);
    putchar('\n');
    for(int ii = 0;ii < j;ii++){
        printf("%d:%d\n",ww21[ii],ll21[ii]);
    }
    printf("%d:%d",w21,l21);
    return 0;
}
