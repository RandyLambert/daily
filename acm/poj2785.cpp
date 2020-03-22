#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int n,a[4005],b[4005],c[4005],d[4005],sum1[16000005],sum2[16000005],len;

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
        sum1[len] = a[i] + b[j];
        sum2[len] = -c[i] - d[j];
        len++;
        }
    }
    
   sort(sum1,sum1+len);

   int i = 0,mid;
   int j = len-1;

   while(i <= j){
        mid = (i + j)/2;

   }

    return 0;
}
