#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
char a[10000010],ma[20000010];
int mp[20000010];
int main(){
    int flag = 1;
    while(~scanf("%s",a)){
        if(a[0] == 'E' && a[1] == 'N' && a[2] == 'D'){
            break;
        }
        else{
            int cnt = 0;
            ma[cnt++] = '$';
            ma[cnt++] = '#';
            int len = strlen(a);
            for(int i = 0;i < len;i++){
                ma[cnt++] = a[i];
                ma[cnt++] = '#';
            }
            ma[cnt] = '0';

            int mx = 0,ld = 0,ans = -1;
            for(int i = 0;i < cnt;i++){
                if(mx > i){
                    mp[i] = min(mx-i,mp[2*ld-i]);
                }
                else{
                    mp[i] = 1;
                }

                while(ma[i-mp[i]]==ma[i+mp[i]]) mp[i]++;

                if(mp[i]+i > mx){
                    mx = mp[i]+ld;
                    ld = i;
                }
                ans = max(ans,mp[i]);
            }
            printf("Case %d: %d\n",flag++,--ans);
        }
        memset(a,0,sizeof(a));
        memset(ma,0,sizeof(ma));
    }

    return 0;
}

