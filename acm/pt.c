#include <stdio.h>
int main(){
        int n,i,b,a[10],c = 0,d[10];
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(b=0;b<n-1;b++){
            for(i=b+1;i<n;i++){
                if(a[b]==a[i]){
                        a[i]=0;
                    }
            }
    }
        for(i=0;i<n;i++){
              if(a[i]!=0){
                 d[c]=a[i];
               c++;
			}
        }
        for(i=0;i<c;i++){ 
                printf("%d",d[i]);
               if(i!=c-1)
                printf(" "); 
                }
        
}

