#include<stdio.h>
#include<stdlib.h>

int aa[100005],bb[100005],nex[100005],su[100005];
int a,b,temp,ddd,sum;
int find(void);
void next(){
    nex[0] = -1;
    int i = -1,j = 0;{
        while(j <= a){
            if(i == -1||bb[i] == bb[i]){
                i++;
                j++;
                nex[j] = i;
            }
            else{
                j = nex[j]; 
            }
        }
    }
}

void kmp(){
    int ax = a;
    int bx = b;
    int i = 0;
    int j = 0;
    next();
    while(ax-b > i){
        while(ax > i&& bx > j){
            if(j == -1 || aa[i] == bb[j]){
                i++;
                j++;
            }
            else{
                j = nex[j];
            }
        }
        if(j == bx){
            sum++;
            su[sum] = i - j + 1;
            i = i - j + 1;
            j = 0;
        }
        else{
            return;
        }
    }
}
int main(){
    scanf("%d%d",&a,&b);
    for(int i = 0;i < a;i ++ ){
        if(i == 0){
            scanf("%d",&ddd);
        }
        else{
            scanf("%d",&temp);
            if(temp < ddd){
                aa[i] = -1;
            }
            else if(temp == ddd){
                aa[i] = 0;
            }
            else{
                aa[i] = 1;
            }
            ddd = temp;
        }
    }
    while(getchar()!='\n');

    for(int i = 0;i < b;i ++ ){
        if(i == 0){
            scanf("%d",&ddd);
        }
        else{
            scanf("%d",&temp);
            if(temp < ddd){
                bb[i] = -1;
            }
            else if(temp == ddd){
                bb[i] = 0;
            }
            else{
                bb[i] = 1;
            }
            ddd = temp;
        }
    }
    kmp();
    /* find(); */

    /* /1* for(int i = 0;i < 10;i++){ *1/ */
    /* /1*     printf("%d ",aa[i]); *1/ */
    /* /1* } *1/ */
    /* /1* printf("\n"); *1/ */
    /* /1* for(int i = 0;i < 10;i++){ *1/ */
    /* /1*     printf("%d ",bb[i]); *1/ */
    /* /1* } *1/ */
    /* for(int i = 0;i < a;i++) */
        /* printf("%d",aa[i]); */
    printf("\n%d\n",sum);
    for(int i = 0; i < sum ;i++){
        printf("%d\n",su[i]+1);
    }

    return 0;
}

/* /1* int find() *1/ */
/* { */
/*      int i,j = 0; */
/*     for(i = 0;i < a;i++) */
/*     { */
/*         if(aa[i] == bb[j]) */
/*         { */
/*             j++; */
/*             if(j == b) */
/*             { */
/*                 su[sum] = i; */
/*                 sum++; */
/*                 j = 0; */
/*             } */
/*         } */
/*         else */
/*         { */
/*             j = 0; */
/*         } */

    /* } */
/* } */
