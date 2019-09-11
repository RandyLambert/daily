#include <bits/stdc++.h>
using namespace std;
int aa[120010];
int bb[20];
inline int erfen(int x){
    int l = 0;
    int r = 16;
    while(l<=r){
        int mid = (l+r)/2;
        if(bb[mid]>x){
             r = mid-1; 
        }
        if(bb[mid]<x){
            l = mid+1;
        }
        else if(bb[mid] == x){
            return 1;
        }
    }
    return 0;

}
int main(){
    int n,sum = 0;
    
    scanf("%d",&n);
    for(int i = 0;i <= 16;i++){
         bb[i] = 2<<i;
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&aa[i]);
    }
    if(n==1){
        printf("1\n");
        exit(0);
    }
    int flag = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j){
                continue;
            }
            else{
                if(erfen(aa[i]+aa[j]))
                    flag = 1;
            }
        }
        if(flag == 0){
            sum++;
        }
        flag = 0;
    }
    printf("%d\n",sum);
    return 0;
}
