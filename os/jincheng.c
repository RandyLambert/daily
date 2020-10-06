#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int i;
    for(int i = 0;i < 2;i++){
        fork();
        printf("- ");
    }
    wait(NULL);
    wait(NULL);

    return 0;
}
