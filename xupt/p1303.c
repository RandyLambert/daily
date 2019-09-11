#include<stdio.h>
#include<string.h>
int a[2002],b[2002];
int add[4005];
char a1[2002],b1[2002];
int main(){
    scanf("%s%s",a1,b1);
    int al = strlen(a1);
    int bl = strlen(b1);
    if(a1[0] != '0'&&b1[0] != '0'){
        int max = al+bl;

        for(int i = al - 1;i >= 0;i--){
            a[i] = a1[al-1-i] - '0';
        }
        
        for(int i = bl - 1;i >= 0;i--){
            b[i] = b1[bl-1-i] - '0';
        }
        
        for(int i = 0;i < al;i++){
            for(int j = 0;j < bl;j++){
                add[i+j] = a[i]*b[j] + add[i+j];
                if(add[i+j]>=10){
                    add[i+j+1] = add[i+j]/10 + add[i+j+1];
                    add[i+j] = add[i+j]%10;
                }
            }
        }

        while(add[max]==0){
            max--;
        }

        for(int i = max;i >= 0;i--){
            printf("%d",add[i]);
        }
    }
    else{
        printf("%d",0);
    }

    return 0;
}
