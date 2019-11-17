#include <bits/stdc++.h>
using namespace std;
void tes(int a){
    cout<<a<<endl;
}
int main(){
    int a[] = {1,3312,34324,23,5435,435,43,6543,6,3456543,432,5,32,423,4,213,4,324,23,4,324,32,4,32,4,23,423,4,32,4,23,42,34,32,324};
    int b[1000] = {1,23,21,432,543,321};
    int c[10000];
    srand(time(NULL));
    //打乱函数，前面写一个种子
    random_shuffle(a,a+20);
    for_each(a,a+20,tes);
    sort(a,a+20);
    sort(b,a+20);
    //merge能把两个有序的合并成一个有序的,前提是两个都得是有序的
    merge(a,a+20,b,b+20,c);
    for_each(c,c+40,tes);
    //能将首尾对调
    reverse(c,c+40);
    for_each(c,c+40,tes);
    return 0;
}
