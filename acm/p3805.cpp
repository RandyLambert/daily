#include <bits/stdc++.h>
using namespace std;
char a[11000000+100],b[11000000*2+200];
int mp[11000000*2+200];
int main(){
    scanf("%s",a);
    int len = strlen(a),cnt = 1;
    b[0] = '$';
    b[cnt++]='#';
    
    for(int i = 0;i < len;i++){
        b[cnt++] = a[i];
        b[cnt++] = '#';
    }
    b[cnt] = '0';

    int mx = 0,id = 0;
    for(int i = 0;i < cnt;i++){
        if(mx > i){
            mp[i] = min(mp[2*id-i],mx-i);
        }
        else{
            mp[i] = 1;
        }
        while(b[i+mp[i]] == b[i-mp[i]])
            mp[i]++;
        if(i+mp[i]>mx){
            mx = i+ mp[i];
            id = i;
        }
    }

    printf("%d\n",*max_element(mp+1,mp+cnt)-1);
    return 0;
}

