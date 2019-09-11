#include <bits/stdc++.h>
using namespace std;
int nex[200005];
char fff[200005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&nex[i]);
    }

    int x = 0,y = n-1,step = 0,temp = 0;
    while(1){
        if(nex[x] <= nex[y] && temp <= nex[x]){
                temp = nex[x];
                x++;
                fff[step] = 'L';
                step++;
                if(x > y){
                    break;
                }
        }
        else if(nex[y] <= nex[x] && temp <= nex[y]){
                temp = nex[y];
                y--;
                fff[step] = 'R';
                step++;
                if(x > y){
                    break;
                }
        }
        else if(nex[x] <= nex[y]){
            if(temp <= nex[y]){
                temp = nex[y];
                y--;
                fff[step] = 'R';
                step++;
                if(x > y){
                    break;
                }
            }
            else{
                break;
            }

        }
        else if(nex[x] >= nex[y]){
            if(temp <= nex[x]){
                temp = nex[x];
                x++;
                fff[step] = 'L';
                step++;    
                if(x > y){
                    break;
                }
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    /* printf("%d %d %d\n",temp,x,y); */
    printf("%d\n",step);
    for(int i = 0;i < step;i++){
        printf("%c",fff[i]);
    }
    putchar('\n');
    return 0;
}
