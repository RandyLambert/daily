#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos( - 1.0);
const int maxp = 1010;
//Compares a double to zero
int sgn(double x){
    if(fabs(x) < eps)return 0;
    if(x < 0)return - 1;
    else return 1;
}
//square of a double
inline double sqr(double x){return x*x;}
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x = _x;
        y = _y;
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void output(){
        printf("%.2f␣%.2f\n",x,y);
    }
    bool operator == (Point b)const{
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator < (Point b)const{
        return sgn(x - b.x)== 0?sgn(y - b.y)<0:x<b.x;
    }
    Point operator - (const Point &b)const{
        return Point(x - b.x,y - b.y);
    }
    //叉积
    double operator ^(const Point &b)const{
        return x*b.y - y*b.x;
    }
    //点积
    double operator *(const Point &b)const{
        return x*b.x + y*b.y;
    }
    //返回长度
    double len(){
        return hypot(x,y);//库函数
    }
    //返回长度的平方
    double len2(){
        return x*x + y*y;
    }
    //返回两点的距离
    double distance(Point p){
        return hypot(x - p.x,y - p.y);
    }
    Point operator +(const Point &b)const{
        return Point(x+b.x,y+b.y);
    }
    Point operator *(const double &k)const{
        return Point(x*k,y*k);
    }
    Point operator /(const double &k)const{
        return Point(x/k,y/k);
    }
    //计算 pa 和 pb 的夹角
    //就是求这个点看 a,b 所成的夹角
    //测试 LightOJ1203
    double rad(Point a,Point b){
        Point p = *this;
        return fabs(atan2( fabs((a - p)^(b - p)),(a - p)*(b - p) ));
    }
    //化为长度为 r 的向量
    Point trunc(double r){
        double l = len();
        if(!sgn(l))return *this;
        r /= l;
        return Point(x*r,y*r);
    }
    //逆时针旋转 90 度
    Point rotleft(){
        return Point( - y,x);
    }
    //顺时针旋转 90 度
    Point rotright(){
        return Point(y, - x);
    }
    //绕着 p 点逆时针旋转 angle
    Point rotate(Point p,double angle){
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
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
    void input(){
        s.input();
        e.input();
    }
    void adjust(){
        if(e < s)swap(s,e);
    }
    //求线段长度
    double length(){
        return s.distance(e);
    }
    //返回直线倾斜角 0<=angle<pi
    double angle(){
        double k = atan2(e.y - s.y,e.x - s.x);
        if(sgn(k) < 0)k += pi;
        if(sgn(k - pi) == 0)k-=pi;
        return k;
    }
    //点和直线关系
    //1 在左侧
    //2 在右侧
    //3 在直线上
    int relation(Point p){
        int c = sgn((p - s)^(e - s));
        if(c < 0)return 1;
        else if(c > 0)return 2;
        else return 3;
    }
    // 点在线段上的判断
    bool pointonseg(Point p){
        return sgn((p - s)^(e - s)) == 0 && sgn((p - s)*(p - e)) <= 0;
    }
    //两向量平行 (对应直线平行或重合)
    bool parallel(Line v){
        return sgn((e - s)^(v.e - v.s)) == 0;
    }
    //两线段相交判断
    //2 规范相交
    //1 非规范相交
    //0 不相交
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
    //直线和线段相交判断
    //-*this line -v seg
    //2 规范相交
    //1 非规范相交
    //0 不相交
    int linecrossseg(Line v){
        int d1 = sgn((e - s)^(v.s - s));
        int d2 = sgn((e - s)^(v.e - s));
        if((d1^d2)== - 2) return 2;
        return (d1==0||d2==0);
    }
    //两直线关系
    //0 平行
    //1 重合
    //2 相交
    int linecrossline(Line v){
        if((*this).parallel(v))
            return v.relation(s)==3;
        return 2;
    }
    //求两直线的交点
    //要保证两直线不平行或重合
    Point crosspoint(Line v){
        double a1 = (v.e - v.s)^(s - v.s);
        double a2 = (v.e - v.s)^(e - v.s);
        return Point((s.x*a2 - e.x*a1)/(a2 - a1),(s.y*a2 - e.y*a1)/(a2 - a1));
    }
    //点到直线的距离
    double dispointtoline(Point p){
        return fabs((p - s)^(e - s))/length();
    }
    //点到线段的距离
    double dispointtoseg(Point p){
        if(sgn((p - s)*(e - s))<0 || sgn((p - e)*(s - e))<0)
            return min(p.distance(s),p.distance(e));
        return dispointtoline(p);
    }
    //返回线段到线段的距离
    //前提是两线段不相交,相交距离就是 0 了
    double dissegtoseg(Line v){
        return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
    }
    //返回点 p 在直线上的投影
    Point lineprog(Point p){
        return s + ( ((e - s)*((e - s)*(p - s)))/((e - s).len2()) );
    }
    //返回点 p 关于直线的对称点
    Point symmetrypoint(Point p){
        Point q = lineprog(p);
        return Point(2*q.x - p.x,2*q.y - p.y);
    }
};
struct polygon{
    int n;
    Point p[maxp];
    Line l[maxp];
    void input(int _n){
        n = _n;
        for(int i = 0;i < n;i++)
            p[i].input();
    }
    void add(Point q){
        p[n++] = q;
    }
    void getline(){
        for(int i = 0;i < n;i++){
            l[i] = Line(p[i],p[(i+1)%n]);
        }
    }
    struct cmp{
        Point p;
        cmp(const Point &p0){p = p0;}
        bool operator()(const Point &aa,const Point &bb){
            Point a = aa, b = bb;
            int d = sgn((a - p)^(b - p));
            if(d == 0){
                return sgn(a.distance(p) - b.distance(p)) < 0;
            }
            return d > 0;
        }
    };
    //进行极角排序
    //首先需要找到最左下角的点
    //需要重载号好 Point 的 < 操作符 (min 函数要用)
    void norm(){
        Point mi = p[0];
        for(int i = 1;i < n;i++)mi = min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    //得到凸包
    //得到的凸包里面的点编号是 0 ∼ n-1 的
    //两种凸包的方法
    //注意如果有影响,要特判下所有点共点,或者共线的特殊情况
    //测试 LightOJ1203 LightOJ1239
    void getconvex(polygon &convex){
        sort(p,p+n);
        convex.n = n;
        for(int i = 0;i < min(n,2);i++){
            convex.p[i] = p[i];
        }
        if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n-- ;//特判
        if(n <= 2)return;
        int &top = convex.n;
        top = 1;
        for(int i = 2;i < n;i++){
            while(top && sgn((convex.p[top] - p[i])^(convex.p[top - 1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        int temp = top;
        convex.p[++top] = p[n - 2];
        for(int i = n - 3;i >= 0;i -- ){
            while(top != temp && sgn((convex.p[top] - p[i])^(convex.p[top - 1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n-- ;//特判
        convex.norm();//原来得到的是顺时针的点,排序后逆时针
    }
    //得到周长
    double getcircumference(){
        double sum = 0;
        for(int i = 0;i < n;i++){
            sum += p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
};
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        polygon q1,q2;
        q1.input(n);
        q1.getconvex(q2);
        double ans = q2.getcircumference();
        if(n==2){
            printf("%.2f\n",ans/2);
        }
        else{
            printf("%.2f\n",ans);
        }
    }
    return 0;
}
