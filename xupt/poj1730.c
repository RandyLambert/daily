#include<stdio.h>
#include<math.h>
int main(){
	int a = 1;
	int b,mx = 0;
	while(scanf("%d",&a)&&a!=0){
		if(a > 0){
			for(int i = 32;i >= 1;i--){
				b = (int)(pow((double)a,1.0/i) + 0.1);//此处加0..1
				if(a == (int)(pow((double)b,(double)i)+0.1)){//此处加0.1
					mx = i;	
					break;
				}	
			}
			printf("%d\n",mx);
		}
		else{
			a = -a;
			for(int i = 31;i >= 1 ;i-=2){
				b = (int)(pow((double)a,1.0/i) + 0.1);//同上
				if(a == (int)(pow((double)b,(double)i)+0.1)){
					mx = i;
					break;	
				}	
			}
			printf("%d\n",mx);
		}
		mx  = 0;	
	}
	return 0;
}

