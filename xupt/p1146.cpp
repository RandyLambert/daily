 #include <iostream> 
/* int a[2] = {1,0}; */
/* int b[4] = {0}; */
/* void dfs(int c){ */
/*     if(c==3){ */
/*         for(int i = 0;i < 4;i++){ */
/*             printf("%d",b[i]); */
/*         } */
/*         putchar('\n'); */
/*         return; */
/*     } */
/*     else{ */
/*         for(int i = 0;i < 2;i++){ */
/*             b[c] = a[i]; */
/*             dfs(c+1); */
/*             b[c] = 0; */
/*         } */
/*     } */
/* } */
/* int main(){ */
/*     int a; */
/*     scanf("%d",&a); */
/*     dfs(1); */
/*     return 0; */
/* } */
bool a[100];
int n;
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j){
                a[i] = a[i];
            }
            else{
                if(a[j] == 0){
                    a[j] = 1;
                }
                else{
                    a[j] = 0;
                }
            }
        }
        for(int k = 0;k < n;k++){
            printf("%d",a[k]);
        }
        putchar('\n');
    }
}
