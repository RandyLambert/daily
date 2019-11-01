#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0); 
const double eps = 1e-8;
int sgn(double x){
    if(fabs(x) < eps)return 0;
    if(x < 0) return -1;
    else return 1;
}
int main(){

    double d  = 1,r = 2,a = 1,b = 2;

    while(d<360){
             double sanduan = r+a;
            double sanchang = sanduan/cos(d/180*PI);
            double sanzhong = sanduan*tan(d/180*PI);
            double xiaochang = b - sanzhong;
            double xiaozhong = xiaochang*sin(d/180*PI);
            /* printf("%lf %lf %lf\n",sanzhong,tan(45*PI/180),r); */
            double ans = xiaozhong + sanchang - r;
            ans = sqrt(sanduan*sanduan + b*b)-r;
            printf("%.12lf\n",ans);

            if(!sgn(ans-1.605551275464)){
                /* printf("找到了，%lf\n",d); */
            }
            
            d+=1;
    }

    return 0;
}

