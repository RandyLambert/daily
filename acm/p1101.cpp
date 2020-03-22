#include <iostream>
char h[7] = {'y','i','z','h','o','n','j'};
char c[100][100];
char d[100][100];
int a;
void dfs(int i,int j){
    if(i == a){
        return;
    }
    else{
        for(int x = 0;x < a;x++){
            if(h[i] == c[i][j]){
                d[i][j] = h[i];
                dfs(i,j+1);
            }
            else{
                d[i][j] = '*';
                dfs(i,j+1);
            }
        }
    }
}
int main(){
    scanf("%d",&a);
    for(int i = 0;i < a;i++){
        scanf("%s",c[i]);
    }

    for(int i = 0;i < a;i++)
        dfs(i,0);
    
    for(int i = 0;i < a;i++){
        for(int j = 0;j < a;j++){
            printf("%d",d[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
