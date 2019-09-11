#include <bits/stdc++.h>
using namespace std;

char str1[10001],str2[10001];
int main(){
    int p1,p2,p3,flag = 1;
    scanf("%d%d%d",&p1,&p2,&p3);
    scanf("%s",str1);
    
    str2[0] = str1[0];
    int b = strlen(str1);
    for(int j = 1;j < b;j++){
        str2[flag] = str1[j];
        flag++;
        if(str1[j] == '-'){
            if('0'<=str1[j-1] && str1[j+1]<='9'){
                if(str1[j-1] + 1 == str1[j+1]){
                    flag--;
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1!=3 && p3 == 1){
                    flag--;
                    for(int k = 1;k < str1[j+1]-str1[j-1];k++){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = str1[j-1] + k;
                            flag++;
                        }
                    }
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1!=3 && p3 == 2){
                    flag--;
                    for(int k = str1[j+1]-str1[j-1]-1;k > 0 ;k--){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = str1[j-1] + k;
                            flag++;
                        }
                    }
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1 == 3){
                    flag--;
                    for(int k = 1;k < str1[j+1] - str1[j-1];k++){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = '*';
                            flag++;
                        }
                    }
                }
            }
            else if('a'<=str1[j-1] && str1[j+1] <= 'z'){
                if(str1[j-1] + 1 == str1[j+1]){
                    flag--;
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1== 1){
                    flag--;
                    for(int k = 1;k < str1[j+1]-str1[j-1];k++){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = str1[j-1] + k;
                            flag++;
                        }
                    }
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1== 3){
                    flag--;
                    for(int k = 1;k < str1[j+1] - str1[j-1];k++){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = '*';
                            flag++;
                        }
                    }
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1 == 1 && p3 == 2){
                    flag--;
                    for(int k = str1[j+1]-str1[j-1]-1;k > 0 ;k--){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = str1[j-1] + k;
                            flag++;
                        }
                    }
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1 == 1 && p3 != 2){
                    flag--;
                    for(int k = 1;k < str1[j+1]-str1[j-1];k++){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = str1[j-1] + k;
                            flag++;
                        }
                    }
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1 == 2 && p3 != 2){
                    flag--;
                    for(int k = 1;k < str1[j+1]-str1[j-1];k++){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = str1[j-1] + k -32;
                            flag++;
                        }
                    }
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1 == 2 && p3 == 2){
                    flag--;
                    for(int k = str1[j+1]-str1[j-1]-1;k > 0 ;k--){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = str1[j-1] + k - 32;
                            flag++;
                        }
                    }
                }
                else if(str1[j-1] + 1 < str1[j+1] && p1 == 3 ){
                    flag--;
                    for(int k = 1;k < str1[j+1]-str1[j-1];k++){
                        for(int x = 1;x <= p2;x++){
                            str2[flag] = str1[j-1] + k - 32;
                            flag++;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0;i < flag;i++){
        printf("%c",str2[i]);
    }
    return 0;
}
