#include <bits/stdc++.h>
using namespace std;
char a1[200000+10],a2[200000+10];
int ans1[200000+10],ans4[200000+10];
int main(){
    int n,cnt1 = 0,cnt2 = 0;    
    cin>>n;
    cin>>a1>>a2;
    for(int i = 0;i < n;i++){
        if(a1[i] != a2[i]){
            if(a1[i] == 'a'){
                ans1[cnt1] = i+1;
                cnt1++;
            }
            else{
                ans4[cnt2] = i+1;
                cnt2++;   
            }
        }
    }

    if((cnt1%2==0 && cnt2%2==1) || (cnt1%2==1 && cnt2%2==0))
    {
        printf("-1\n");
    }
    else if(cnt1%2 == 1 && cnt2%2== 1)
    {
        printf("%d\n",(cnt1+cnt2)/2+1);
        printf("%d %d\n%d %d\n",ans1[0],ans1[0],ans1[0],ans4[0]);
        for(int i = 1;i < cnt1;i+=2){
            printf("%d %d\n",ans1[i],ans1[i+1]);
        }
        for(int i = 1;i < cnt2;i+=2){
            printf("%d %d\n",ans4[i],ans4[i+1]);
        }
    }
    else
    {
        printf("%d\n",(cnt1+cnt2)/2);
        for(int i = 0;i < cnt1;i+=2){
            printf("%d %d\n",ans1[i],ans1[i+1]);
        }
        for(int i = 0;i < cnt2;i+=2){
            printf("%d %d\n",ans4[i],ans4[i+1]);
        }
    }
    return 0;
}

