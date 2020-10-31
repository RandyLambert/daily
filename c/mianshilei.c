//2.请解释下列代码，并谈谈自己理解
#include <stdio.h>
int main(int argc, char *argv[])
{
	double q = 9.96;
	float b = q;
	if((float)q == b)
		printf("Xiyou");
	if(q != b)
		printf("LinuxGroup\n");
	return 0;
}
