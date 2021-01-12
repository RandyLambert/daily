#include <stdio.h>
#include <stdlib.h>

/* 题１ */
/* 在下段程序中，我们可以通过１打印出a的地址如0x7ffd737c6db4,
我们再用scanf去将这个地址填入unsigned long的c中，
我们就可以通过c去修改a的值，你知道其中的原理吗？
 */
void func() {

  int a = 1;
  unsigned long c;
  char s[2020];
  printf("%p\n", &a); // 1
  printf("我们想要修改的地址：");
  scanf("%lx", &c); // 0x7ffd737c6db4
  printf("我们想要修改的值：");
  scanf("%d", (int *)c);
  printf("a=%d\n", a);
}

/* 题2 */
/* 如下程序，根据打印结果，你有什么思考？ */
typedef struct a_cute_struct {
  int a[3];
  char *aa;
  long long *aaa;
} a_cute_struct;
void func2() {
  a_cute_struct acs;
  acs.a[0] = 0x20201121; // 0x20201121
  acs.a[1] = 0x554E494c; // UINL
  acs.a[2] = 0x58;       // X

  acs.aa = (char *)&acs.a[1];
  acs.aaa = (long long *)&acs.a;
  printf("%s\n", acs.aa);
  printf("%llx\n", *acs.aaa);
}

/* 题3 */
/*
 １.你知道如何在linux如何用一条命令查看某个目录下所有文件名含有“.c“文件的数量(不包括子目录下的文件)并把这个数字输出在文件里？
*/

int main(int argc, char *argv[]) { func2(); }
