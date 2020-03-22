#include <bits/stdc++.h>

using namespace std;
int main(){
    int f,t,j,mx = 0,mix = 0;
    int a[7] = {0,1,2,0,2,1,0};
    scanf("%d%d%d",&f,&t,&j);
    
    for(int i = 0;i < 7;i++){
        int f1 = f;
        int t1 = t;
        int j1 = j;
        while(1){
            if(a[i] == 0){
                if(f1>=1 ){
                    f1--;
                    mx++;
                }
                else
                    break;
            }
            else if(a[i] == 1){
                if(t1>=1){
                    mx++;
                    t1--;
                }
                else
                    break;
            }
            else if(a[i] == 2){
                if(j1 >= 1){
                    j1--;
                    mx++;
                }
                else
                    break;
            }
            i = (i+1)%7;
        }
        mix = max(mx,mix);
    }

    printf("%d",mix);
    return 0;
}
