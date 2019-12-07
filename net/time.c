#include "unp.h"
int main(){
    Time_Get();
    char ans[MAXLEN];
    Read_Time(ans);
    printf("%s\n",ans);
    
    return 0;
}

