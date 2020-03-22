#include <bits/stdc++.h>
using namespace std;
int main(){
    double s,a,b;
    cin>>s>>a>>b;
    double ans = (a+b)*s/(b+3*a);
    double cnt = ans/b+(s-ans)/a;
    printf("%.6lf",cnt);

    return 0;
}
