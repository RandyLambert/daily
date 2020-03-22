#include<stdio.h>
#include<math.h>
int xx[20],yy[20],zz[20];
int main(){
    int a;
    int x,y;
    scanf("%d",&a);
    while(a--){
        scanf("%d%d",&x,&y);
        int i = 1,j = 1,k,flag = 0;
        while(x){
            if(x%2 == 0){
                xx[i] = 0;
                x = x/2;
                i++;
            }
            else if(x%2 == 1){
                xx[i] = 1;
                x = x/2;
                i++;
                
            }
        }
        
        while(y){
            if(y%2 == 0){
                yy[j] = 0;
                y = y/2;
                j++;
            }
            else if(y%2 == 1){
                yy[j] = 1;
                y = y/2;
                j++;
            }
        }

        for(k = j-1;k>=1;k--){
            if(yy[k] == 0 )
                flag = 1;
        }

        if(flag == 0){
            for(int h = 1;h <= i-1;h++){
                zz[h] = xx[h]|yy[h];
            }
        }
        else{
            yy[j-1] = 0;

            for(int h = 1;h<=j-2;h++){
                yy[h] = 1;
            }

            for(int h = 1;h <= i-1;h++){
                zz[h] = xx[h]|yy[h];
            }
        }



        for( k = i-1;k>=1;k--){
            printf("%d",zz[k]);
        }

        int sum = 0;

        /* for(k = 1;k <= i-1;k++){ */
        /*     sum=sum*2+zz[k]; */
        /*     printf("%d",sum); */
        /* } */
            
        
    }

    return 0;
}
