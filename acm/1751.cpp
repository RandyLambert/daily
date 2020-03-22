#include <iostream>
#include <stdio.h>

using namespace std;
int n,hua,deng,deng2,num;
char dai;
int a[100] = {1};
void dfs(int step){
    for(int i = a[step - 1];i <= deng2;i++){
        
        a[step] = i;
        deng2 = deng2 - i;

        if(deng2 == 0){
            num++;
        }
        else{
           dfs(step + 1);
        }
        deng2 =deng2 +i;
    }

}
int main(){
    scanf("%d",&n);
    for(int i = 0;i <2 *  n;i++){
        scanf("%c",&dai);
        /* getchar(); */
        if(dai == '*')
            deng++;
        else if(dai == '@')
            hua++;
    }
    /* printf("%d",hua); */
    if(deng <= hua){
        deng2 = deng;
        dfs(1);
    }
    else{
        deng2 = hua + 1; 
        dfs(1);
    }
    printf("%d",num);
    return 0;
}
