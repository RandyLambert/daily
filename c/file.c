#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp = fopen("../c++/xx","ae");
    
    char buffer[1024] = "dasdsadasdasdsadsadsadasdsadasdasdas";
    fwrite(buffer,1,40,fp);
    fclose(fp);
    
    return 0;
}

