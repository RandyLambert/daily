#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main(){
    double a,b,r,d;
    int n;
    cin>>n;
    while(n--){
        cin>>a>>b>>r>>d;
        /* if(d>90){ */
        /*     d = d/2; */
        /* } */
            double sanduan = r+a;
            double ans = sqrt(sanduan*sanduan + b*b);
            
            if(d*PI/180.0 - acos((a+r)/ans) > 0){
                printf("%.12lf\n",ans-r);
            }
            else{
                double sanchang = sanduan/cos(d/180*PI);
                double sanzhong = sanduan*tan(d/180*PI);
                double xiaochang = b - sanzhong;
                double xiaozhong = xiaochang*sin(d/180*PI);
                /* printf("%lf %lf %lf\n",sanzhong,tan(45*PI/180),r); */
                ans = xiaozhong + sanchang - r;
                printf("%.12lf\n",ans);

            }
    }

    return 0;
}
