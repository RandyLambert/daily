#include<stdio.h>
#include<string.h>
char c[250];
int flag;
int d,cnt,t = 1;
int l,ll[250];
int main(){
    int i = 0;
    int min,hao;
    scanf("%s",c);
    l = strlen(c);

    for(i = 0;i < l;i++){
        ll[i] = c[i]='0';
    }

    scanf("%d",&d);
    hao = l - d;
    
    while(cnt < hao){
        min = t;
        for(int i = t;i <= d+t;i++){
            if(ll[min]>ll[i]){
                min = i;
            }
        }
        if(ll[min]) flag = 1;
        if(flag )
            printf("%d",ll[min]);
        d = d-(min - t);
        t = min +1;
        cnt++;
    }
    if(!flag) printf("0");
    return 0;
}
