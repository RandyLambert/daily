#include <bits/stdc++.h>
using namespace std;
char haab[19][8]{
"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};
char tzo1kin[20][10]{
"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",  "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};
int n;

int find(char *tt){
    for(int i = 0;i < 19;i++){
        if(strcmp(haab[i],tt)==0){
            return i;
        }
    }
}
int main(){
    int ri,nian,zong;
    char tt[8];
    int ri3,ri2,nian2;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&ri);
        getchar();
        scanf("%s",tt);
        scanf("%d",&nian);
        int gonyue = find(tt);
        memset(tt,0,sizeof(tt));
        zong = nian*365 + ri + 1 + gonyue*20;
        nian2 = zong/260;
        ri2 = zong%260%13+1;
        ri3 = zong%260%20;
        
        printf("%d %s %d\n",ri2,tzo1kin[ri3],nian2);

    }
    return 0;
}
