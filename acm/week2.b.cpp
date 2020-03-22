#include <stdio.h>
#include <string.h>
#include <math.h>
int ci[12];
char zuo[8],you[8],qing[8],temp[8];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int flag = 0,len = 0;
        memset(ci,0,sizeof(ci));
        memset(zuo,0,sizeof(zuo));
        memset(you,0,sizeof(you));
        memset(qing,0,sizeof(qing));
        char ans = 0;
        for(int j = 0;j < 3;j++){
            scanf("%s%s%s",zuo,you,qing);
            getchar();
            len = strlen(zuo);
            if(qing[0] == 'e'){
                for(int i = 0;i < len;i++){
                    ci[zuo[i]-'A'] = 10;
                    ci[you[i]-'A'] = 10;
                }
            }
            else if(qing[0] == 'u'){
                for(int i = 0;i < len;i++){
                    if(ci[zuo[i]-'A']!=10)
                        ++ci[zuo[i]-'A'];
                    if(ci[you[i]-'A']!=10)
                        --ci[you[i]-'A'];

                }
            }
            else if(qing[0] == 'd'){
                for(int i = 0;i < len;i++){
                    if(ci[zuo[i]-'A']!=10)
                        --ci[zuo[i]-'A'];
                    if(ci[you[i]-'A']!=10)
                        ++ci[you[i]-'A'];
                }
            }
            int mx = 0;
            for(int i = 0;i < 12;i++){
                if(ci[i] == 10)
                    continue;
                if(mx<=abs(ci[i]))
                {
                    mx = abs(ci[i]);
                    flag = i;
                }
            }
        }
        if(ci[flag] > 0)
            printf("%c is the counterfeit coin and it is heavy.\n",flag + 'A');
        else
            printf("%c is the counterfeit coin and it is light.\n",flag + 'A');
    }
    return 0;
}
