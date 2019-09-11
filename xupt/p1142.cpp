#include <iostream>
using namespace std;
struct node{
    int x,y;
}a[1000];
//int b[1000];
int n;
int main(){
    int mx = 0,ans = 2;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    for(int i = 0;i < n - 1;i++){
        for(int j = i+1;j < n;j++){
            node temp;
            temp.x = a[i].x-a[j].x;
            temp.y = a[i].y-a[j].y;
            for(int k = 0;k < n;k++){
                if(k!=i&&k!=j){
                    node temp2;
                    temp2.x = a[k].x-a[i].x;
                    temp2.y = a[k].y-a[i].y;
                    if(temp2.x*temp.y==temp2.y*temp.x)
                        ans++;
                }
            }
            mx = max(mx,ans);
            ans=2;
        }
    }
    printf("%d\n",mx);
    return 0;
}
