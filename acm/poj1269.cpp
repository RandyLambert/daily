#include <stdio.h>
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
    Point operator - (const Point &b)const{
        return Point(x - b.x,y - b.y);
    }
    Point operator +(const Point &b)const{
        return Point(x+b.x,y+b.y);
    }
    double operator ^(const Point &b)const{
        return x*b.y - y*b.x;
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void output(){
        printf("POINT %.2f %.2f\n",x,y);
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
};

int main(){
    int t;
    scanf("%d",&t);
    printf("INTERSECTING LINES OUTPUT\n");
    while(t--){
        Point a,b,c,d;
        a.input(),b.input();
        c.input(),d.input();
        Line e(a,b);
        Line f(c,d);
        int x = e.linecrossline(f);

        if(x==0){
            printf("NONE\n");
        }
        else if(x==1){
            printf("LINE\n");

        }
        else{
            Point g = e.crosspoint(f);
            g.output();
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}

