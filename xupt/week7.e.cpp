#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}a[4];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        int flag = 0;
        for(int i = 0;i < 4;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(int i = 0;i < 4;i++){
            for(int j = i+1;j < 4;j++){
                for(int k = j+1;k < 4;k++){
                    if(a[i].x == a[j].y){
                        if(a[i].x == a[k].x||a[i].x == a[k].y){
                            flag = 1;
                        }
                        if(a[i].y+a[j].x == a[k].x || a[i].y+a[j].x == a[k].y){
                            flag = 1;
                        }
                    }
                    if(a[i].x == a[j].x){
                        if(a[i].x == a[k].x||a[i].x==a[k].y){
                            flag = 1;
                        }
                        if(a[i].y+a[j].y == a[k].x || a[i].y+a[j].y == a[k].y){
                            flag = 1;
                        }
                    }
                    if(a[i].y == a[j].x){
                        if(a[i].y == a[k].x||a[i].y==a[k].y){
                            flag = 1;;
                        }
                        if(a[i].x+a[j].y == a[k].x || a[i].x+a[j].y == a[k].y){
                            flag = 1;
                        }
                    }
                    if(a[i].y == a[j].y){
                        if(a[i].y == a[k].x||a[i].y==a[k].y){
                            flag = 1;;
                        }
                        if(a[i].x+a[j].x == a[k].x || a[i].x+a[j].x == a[k].y){
                            flag = 1;
                        }
                    }
                    if(a[i].x == a[k].y){
                        if(a[i].x == a[j].x||a[i].x == a[j].y){
                            flag = 1;
                        }
                        if(a[i].y+a[k].x == a[j].x || a[i].y+a[k].x == a[j].y){
                            flag = 1;
                        }
                    }
                    if(a[i].x == a[k].x){
                        if(a[i].x == a[j].x||a[i].x==a[j].y){
                            flag = 1;
                        }
                        if(a[i].y+a[k].y == a[j].x || a[i].y+a[k].y == a[j].y){
                            flag = 1;
                        }
                    }
                    if(a[i].y == a[k].x){
                        if(a[i].y == a[j].x||a[i].y==a[j].y){
                            flag = 1;;
                        }
                        if(a[i].x+a[k].y == a[j].x || a[i].x+a[k].y == a[j].y){
                            flag = 1;
                        }
                    }
                    if(a[i].y == a[k].y){
                        if(a[i].y == a[j].x||a[i].y==a[j].y){
                            flag = 1;;
                        }
                        if(a[i].x+a[k].x == a[j].x || a[i].x+a[k].x == a[j].y){
                            flag = 1;
                        }
                    }
                    if(a[k].x == a[j].y){
                        if(a[k].x == a[i].x||a[k].x == a[i].y){
                            flag = 1;
                        }
                        if(a[k].y+a[j].x == a[i].x || a[k].y+a[j].x == a[i].y){
                            flag = 1;
                        }
                    }
                    if(a[k].x == a[j].x){
                        if(a[k].x == a[i].x||a[k].x==a[i].y){
                            flag = 1;
                        }
                        if(a[k].y+a[j].y == a[i].x || a[k].y+a[j].y == a[i].y){
                            flag = 1;
                        }
                    }
                    if(a[k].y == a[j].x){
                        if(a[k].y == a[i].x||a[k].y==a[i].y){
                            flag = 1;;
                        }
                        if(a[k].x+a[j].y == a[i].x || a[k].x+a[j].y == a[i].y){
                            flag = 1;
                        }
                    }
                    if(a[k].y == a[j].y){
                        if(a[k].y == a[i].x||a[k].y==a[i].y){
                            flag = 1;;
                        }
                        if(a[k].x+a[j].x == a[i].x || a[k].x+a[j].x == a[i].y){
                            flag = 1;
                        }
                    }
                }
            }
        }
        if(flag == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
