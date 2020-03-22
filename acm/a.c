#include<stdio.h>
void quick(double a[],int left,int right){
    int i = left;
    int j = right;
    int mid = (i+j)/2;
    int t;
    while( i <= j ){
        while(a[i]<a[mid]){
            i++;
        }
        while(a[j]>a[mid]){
            j--;
        }
        if(i<=j){
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if(i<right)
        quick(a,i,right);
    if(j>left)
        quick(a,left,j);
}
int a;
int b[100],c[100];
double d[100];
int main(){
    int i;
    scanf("%d",&a);
    for(i = 0;i < a;i++){
        scanf("%d%d",&b[i],&c[i]);
        d[i] = (double)b[i]/c[i];
    }
    quick(d,0,a);

    return 0;
}
