#include <bits/stdc++.h>

using namespace std;
int a[100005],n;
void quicksort(int left,int right){
    if(left >= right)
        return ;
    int i = left;
    int temp = a[left];
    int j = right;
    while(i<j){
        while(temp <= a[j] && j > i){
            j--;
        }

        while(temp >= a[i] && j > i){
            i++;
        }
	if(i < j)
           swap(a[i],a[j]);
    }

    a[left] = a[i];
    a[i] = temp;    
    quicksort(left,i-1);
    quicksort(i+1,right);
}

void quicksort1(int left,int right){
    if(left >= right){
        return ;
    }
    
    int i = left - 1;
    int j = right + 1;
    int temp = a[left];

    while(i < j){
        do i++; while(a[i] < temp);
        do j--; while(a[j] > temp);
        if(i < j) swap(a[i],a[j]);
    }

    quicksort1(left,i);
    quicksort1(i+1,right);

}
int main(){
    freopen("P1177_1.in","r",stdin);
    int i;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    quicksort1(1,n);
    //sort(a+1,a+1+n);
    //quicksort(1,n);
    for(i = 1;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
