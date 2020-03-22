#include<stdio.h>
#include<string.h>
void panduan(int a){
    if(a==0)
        printf("=\n");
    else if(a>0)
        printf(">\n");
    else if(a<0)
        printf("<\n");

}
int main() {
	char a[25], b[25];
	scanf("%s",a);
    scanf("%s",b);
    int i;
	for (i = 0; (a[i] != '\0') && (b[i] != '\0'); i++)
		if (a[i] == b[i]) {
			continue;
		}
        else{
			break;
		}
 
	panduan(a[i] - b[i]);
	return 0;
}

