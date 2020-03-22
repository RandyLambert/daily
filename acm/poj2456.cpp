#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int peng[100];
int n,c,num;

int panduan(int mid){
    int ni = 0;
    num = 1;
    for(int i = 1;i < n;i++){
        if(mid <= peng[i] - peng[ni]){
            num++;
            ni = i;
            }
    }

    if(num == n){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    scanf("%d%d",&n,&c);

    for(int i = 0;i < n;i++){
        scanf("%d",&peng[i]);
    }

    sort(peng,peng+n);

    int star = n;
    int mid;
    int cnt = 0;

    while(cnt <= star){
        mid = (star + cnt)/2;
        
        if(panduan(mid)){
            cnt = mid + 1;
        }
        else{
            star = mid - 1;
        }
    }

    printf("%d",mid);
    return 0;
}
