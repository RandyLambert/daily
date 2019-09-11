#include<stdio.h>
int a[100000];
int ci,n,m,sum;

inline int judge(int mid){
    for(int i = 0;i < n;i++){
        if(sum + a[i] <= mid)
            sum = sum + a[i];
        else{
            ci++;
            sum = a[i];
        }
    }

    return ci >= m;
}    

int main(){
    int rig = 0,lef = 0,mid;
    scanf("%d%d",&n,&m);

    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
        lef = lef<a[i]?a[i]:lef;
        rig = rig + a[i];
    }

    while(lef<=rig){
        mid = (lef + rig)/2;
        sum = 0,ci = 0;
        if(judge(mid))
            lef = mid + 1;
        else
            rig = mid - 1;
    }

    printf("%d",lef);

    return 0;
}
