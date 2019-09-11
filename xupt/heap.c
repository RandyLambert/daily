#include<stdio.h>

void swap(int arr[] ,int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int tree[],int n,int i){
    if(i >= n){
        return ;
    }
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int max = i;
    if(c1<n && tree[c1] > tree[max]){
        max = c1;
    }
    if(c2<n && tree[c2] > tree[max]){
        max = c2;
    }
    if(max != i){
        swap(tree,max,i);
        heapify(tree,n,max);
    }
}

void build(int tree[],int n){
    int last_node = n - 1;
    int parent = (last_node - 1)/2;
    int i;
    for(i = parent; i >= 0;i--){
        heapify(tree,n,i);
    }
    
}
int main(){
    int tree[6] = {2,5,3,1,10,4};
    int n = 6;
    build(tree,n);
    int i;
    for(i = 0;i < n;i++){
        printf("%d ",tree[i]);
    }
    return 0;
}
