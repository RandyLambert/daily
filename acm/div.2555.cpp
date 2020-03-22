#include <bits/stdc++.h>

using namespace std;

int bb[10];
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int nn = n;
    for(int i = 1;i < 10;i++){
        scanf("%d",&bb[i]);
    }
    for(int i = 1;i < n;i++){
        if(m/((int)pow(10,nn-1)) < bb[m/((int)pow(10,nn-1))]){
            printf("%d",bb[m/((int)pow(10,nn-1))]);
            nn--;
            m = m%((int)pow(10,nn-1));
            printf("%d  ",m%10);
        }
        else{
            printf("%d ",m/((int)pow(10,nn-1)));
            nn--;
            m = m%((int)pow(10,nn-1));
        }
    }
    return 0;
}
