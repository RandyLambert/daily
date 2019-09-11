#include <bits/stdc++.h>
using namespace std;
int ans[2][1000];
int chen[100000],he[100000];
int main(){
    int x,y,z,zz,len;
    scanf("%d",&x);

    while(x--)
    {
        memset(ans,0,sizeof(ans));
        memset(chen,0,sizeof(chen));
        memset(he,0,sizeof(he));
        len = 1,zz = 2;
        int flag = 0;
        scanf("%d%d",&y,&z);
        int cha = z-y;
         for(int i = 0;i<10000;i++){ 
             len = len + zz; 
             zz++; 
             if(len == y){
                break;
             }
             else if(len > y){
                flag = 1;
                break;
             }
         } 
         zz = zz - 1;
         if((z - y)%2!=0){
             flag = 1;
         }
         //int chang = 0;
         for(int i = 1;i < zz;i++){
            chen[i] = i*(i+1);
            he[i] = i + i + 1;
         }
         int len = 0;
         for(int i = 1;i < zz - 1;i++){
             for(int j = i+1;j < zz;j++){
                 if(chen[i]+chen[j]-he[i]-he[j] == cha){
                    ans[0][len] = he[i]/2;
                    ans[1][len] = he[j]/2;
                    len++;
                 }
             }
         }
         if(flag == 1&&len == 0){
             printf("NONE\n");
             continue;
         }
         else{
             for(int i = 0;i < len;i++){
                printf("(%d,%d)",ans[0][i],ans[1][i]);
             }
             putchar('\n');
         }
    }
    return 0;
}

