#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char ch[1010][1010];
char ch2[1010][10100];

int main()
{
    int i;
    scanf("%d",&i);
    getchar();
    int cnt = 0;
    while(1) {
        fgets(ch[cnt],1010,stdin);
        if(feof(stdin)){
            break;
        }
        cnt++;
    }

    int duan = 0;
    int cs = 0;
    for(int i = 0;i < cnt;i++){
        int x = 0;

        while(ch[i][x] == ' '){
            x++;
        }
        if(ch[i][x] == '\n'){
            if(strlen(ch2[duan]) != 0){
                duan++;    
                cs=0;
            }
            continue ;
        }

        while(ch[i][x] != '\n'){            
            ch2[duan][cs] = ch[i][x];
            cs++;
            x++;
        }
    }

    int ans = duan - 1;
    /*for(int i = 0;i < duan;i++){
        if(strlen(ch2[i])%10 != 0){
            ans++;
        }
        int xxx = (strlen(ch2[i])/10);
        ans+=xxx;
        printf("%d %s\n",xxx,ch2[i]);
    }*/

    for(int i = 0;i < duan;i++){
        int xx = 0;
        bool ff = false;
        for(int j = 0;j < strlen(ch2[i]);j++){
            if(xx != 9){
                if(ff == false){
                    if(ch2[i][j] != ' '){
                        ff = true;
                        xx++;
                        printf("%c",ch2[i][j]);
                    }
                }else{
                    printf("%c",ch2[i][j]);
                    xx++;
                }
            } else {
                xx = 0;
                ff = false;
                ans++;
                printf("%c\n",ch2[i][j]);
            }
        }
        if(xx != 10)
            ans++;
        printf("\n");
    }

    cout<<ans<<endl;
    
    return 0;
}
