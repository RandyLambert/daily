#include <iostream>
#include <algorithm>
using namespace std;
struct Point{
    int x,y;
    Point(){}    //构造函数
    Point(int xx,int yy){
        x = xx;
        y = yy;
    }
    Point operator - (const Point a)const{
        return Point(x-a.x,y-a.y);
    }
    double operator ^(const Point &b)const{
        return x*b.y - y*b.x;    
    }

}p[11000],ch[11000];    //元序列和凸包序列

bool cmp(Point a,Point b){     //点排序
    if(a.x == b.x)  return a.y < b.y;
    return a.x < b.x; 
}

double det (Point a, Point b) {    //返回叉乘的摸  亦可以用重载*的方法
    return a.x * b.y - a.y * b.x;
}

int ConvexHull ( Point * p,int n, Point * ch ){    //构造凸包
    sort(p,p+n,cmp); 
    int m=0;
    for (int i=0;i<n;i++){
        while (m >1&& det(ch[m -1] - ch[m -2] ,    //回溯
                          p[i]-ch[m -2]) <=0) m --;
        ch[m++]= p[i];
    }
    int k=m;
    for (int i=n-2;i >=0;i--){
        while (m>k && det(ch[m -1] - ch[m -2] ,
                          p[i]-ch[m -2]) <=0) m --;
        ch[m++]= p[i];
    }
    if(n > 1)
        m--;

    return m;
}

int main(){
    int n,m,ans;
    double area = 0;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>p[i].x>>p[i].y;
    }
    m = ConvexHull(p,n,ch);
    for(int i= 2;i < m;i++){
        area += (ch[i]-ch[0])^(ch[i-1]-ch[0]);
    }
    area/=2;
    if(area <= 0)
        area = -area;
    ans = area/50;
    cout<<ans<<"\n";

    return 0;
}
