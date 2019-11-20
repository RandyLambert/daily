#include <stdio.h>
#include <malloc.h>

static int s1=0,s2=0,s3=0;    //静态变量 放在静态区
int g1=0,g2=0,g3=0;           //全局变量 放在静态区

int main()
{
    static int s4=0,s5=0,s6=0;           //静态变量
    int a1=0,a2=0,a3=0;             //局部变量 放在栈区
    char c1[] = "aabb";            //局部变量 放在栈区
    const char *c2 = "aabb";             //字符常量 放在静态区
    char *m1 = (char *)malloc(1);  //		 堆区
    char *m2 = (char *)malloc(1);  //		 堆区
    char *m3 = (char *)malloc(1);  //		 堆区
    printf("动态数据区\n");
    printf(" a1 = %p\n a2 = %p\n a3 = %p\n",&a1,&a2,&a3);
    printf(" c1 = %p\n",c1);
    printf(" m1 = %p\n m2 = %p\n m3 = %p\n",&m1,&m2,&m3);

    printf("静态数据区\n");
    printf(" s1 = %p\n s2 = %p\n s3 = %p\n",&s1,&s2,&s3);
    printf(" g1 = %p\n g2 = %p\n g3 = %p\n",&g1,&g2,&g3);
    printf(" s4 = %p\n s5 = %p\n s6 = %p\n",&s4,&s5,&s6);
    printf(" c2 = %p\n",c2);
    return 0;
}
