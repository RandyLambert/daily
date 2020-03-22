#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1E-8;
const double pi = acos(-1.0);

int sgn(double x){
    if(fabs(x) < eps)return 0;
    if(x < 0)return - 1;
    else return 1;
}

struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x = _x;
        y = _y;
    }
    bool operator == (Point b)const{
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    Point operator -(const Point &b)const{
        return Point(x - b.x,y - b.y);
    }
    Point operator +(const Point &b)const{
        return Point(x+b.x,y+b.y);
    }
    double operator ^(const Point &b)const{
        return x*b.y - y*b.x;
    }

    //点积
    double operator *(const Point &b)const{
        return x*b.x + y*b.y;
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void output(){
        printf("%.2f %.2f\n",x,y);
    }
};

struct Line{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e){
        s = _s;
        e = _e;
    }
    bool operator ==(Line v){
        return (s == v.s)&&(e == v.e);
    }
    //根据一个点和倾斜角 angle 确定直线,0<=angle<pi
    Line(Point p,double angle){
        s = p;
        if(sgn(angle - pi/2) == 0){
            e = (s + Point(0,1));
        }
        else{
            e = (s + Point(1,tan(angle)));
        }
    }
    //ax+by+c=0
    Line(double a,double b,double c){
        if(sgn(a) == 0){
            s = Point(0, - c/b);
            e = Point(1, - c/b);
        }
        else if(sgn(b) == 0){
            s = Point( - c/a,0);
            e = Point( - c/a,1);
        }
        else{
            s = Point(0, - c/b);
            e = Point(1,( - c - a)/b);
        }
    }

    bool parallel(Line v){
        return sgn((e - s)^(v.e - v.s)) == 0;
    }
    int relation(Point p){
        int c = sgn((p - s)^(e - s));
        if(c < 0)return 1;
        else if(c > 0)return 2;
        else return 3;
    }

    int linecrossseg(Line v){
        int d1 = sgn((e - s)^(v.s - s));
        int d2 = sgn((e - s)^(v.e - s));
        if((d1^d2)== - 2) return 2;
        return (d1==0||d2==0);
    }

    int linecrossline(Line v){
        if((*this).parallel(v))
            return v.relation(s)==3;
        return 2;
    }

    Point crosspoint(Line v){
        double a1 = (v.e - v.s)^(s - v.s);
        double a2 = (v.e - v.s)^(e - v.s);
        return Point((s.x*a2 - e.x*a1)/(a2 - a1),(s.y*a2 - e.y*a1)/(a2 - a1));
    }
    int segcrossseg(Line v){
        int d1 = sgn((e - s)^(v.s - s));
        int d2 = sgn((e - s)^(v.e - s));
        int d3 = sgn((v.e - v.s)^(s - v.s));
        int d4 = sgn((v.e - v.s)^(e - v.s));
        if( (d1^d2)== - 2 && (d3^d4)== - 2 )return 2;
        return (d1==0 && sgn((v.s - s)*(v.s - e))<=0) ||
            (d2==0 && sgn((v.e - s)*(v.e - e))<=0) ||
            (d3==0 && sgn((s - v.s)*(s - v.e))<=0) ||
            (d4==0 && sgn((e - v.s)*(e - v.e))<=0);
    }
};

//判断点在线段上
//判断点在线段上
bool OnSeg(Point P,Line L)
{
    return
    sgn((L.s-P)^(L.e-P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

//判断点在凸多边形内
//点形成一个凸包，而且按逆时针排序（如果是顺时针把里面的<0改为>0）
//点的编号:0~n-1
//返回值：
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inConvexPoly(Point a,Point p[],int n)
{
    for(int i = 0;i < n;i++)
    {
        if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0)return -1;
        else if(OnSeg(a,Line(p[i],p[(i+1)%n])))return 0;
    }
    return 1;
}
int main(){
    int t;
    double x1,y1,x2,y2;
    scanf("%d",&t);
    while(t--){
        int xx,yy;
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        xx = x1;
        yy = y1;
        Line line = Line(Point(x1,y1),Point(x2,y2));
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        if(x1 > x2)swap(x1,x2);
        if(y1 > y2)swap(y1,y2);
        Point p[10];
        p[0] = Point(x1,y1);
        p[1] = Point(x2,y1);
        p[2] = Point(x2,y2);
        p[3] = Point(x1,y2);

        Line a = Line(p[0],p[1]);
        Line b = Line(p[0],p[3]);
        Line c = Line(p[1],p[2]);
        Line d = Line(p[2],p[3]);

        if(line.segcrossseg(a) || line.segcrossseg(b) || line.segcrossseg(c) || line.segcrossseg(d)){
            printf("T\n");
        }
        else{
            if(inConvexPoly(line.s,p,4) >= 0 || inConvexPoly(line.e,p,4) >= 0){
                printf("T\n");
            }
            else{
                printf("F\n");
            }
        }
    }
    return 0;
}
