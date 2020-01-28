#include<stdio.h>
int main(){
	char a[20];
	char b[20];
	char buf1[256],buf2[256];
	FILE *fp1,*fp2; 
	printf("qing shu ru wenjian ming");
	gets_s(a,20);
	gets_s(b,20);
	if((fp1 = (fopen(a,"r")) == NULL){
		fprintf("shu chu cuo wu");
	}
	if((fp2 = (fopen(a,"r")) == NULL){
		fprintf("shu chu cuo wu");
	}
	while(feof(fp1) == 0||feof(fp2) == 0){
		if (fgets(buf1, 256, file1) != NULL)
        {
            int length = strlen(buf1);
            fputs(buf1, stdout);
        }
        	if (fgets(buf2, 256, file2) != NULL)
        {
            fputs(buf2, stdout);
        }
	}
	fclose(fp1);
	fclose(fp2);

}