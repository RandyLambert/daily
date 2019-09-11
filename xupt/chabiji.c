#include <iostream>
using namespace std;
const int N = 10010;

int f[N];

/*
 * 将表示朋友圈的数组初始化，即将所有人的“朋友祖先”都设置为自己的 id ，
 * 于是就有了 n 个不同的朋友圈 
 */
void init(int n) {
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
}

// 得到 id 为 v 的人的“朋友祖先”的 id 
int getFriend(int v) {  
    if(f[v] == v) {
        return v;
    }
    /*
     * 如果发现“朋友祖先”不是自己，那么他肯定被合并到别的朋友圈里面去了，
     * 那么继续调用这个函数来找这个朋友圈里面的“朋友祖先”，
     * 并且在这个过程中将找到的人都设置为同一个“朋友祖先”（因为都在同一个朋友圈里面） 
     */
    return f[v] = getFriend(f[v]);
}

// 将两个人所在的两个朋友圈合并为一个朋友圈 
void merge(int a, int b) {
    int t1 = getFriend(a); // 得到左边的人的“朋友祖先” 
    int t2 = getFriend(b); // 得到右边的人的“朋友祖先” 
    /* 这里我们制定一个“靠左原则”：一旦发现两个人的“朋友祖先”不一样，
     * 那么右边那个人的“朋友祖先”的“朋友祖先”设置为左边的人的“朋友祖先”，
     * 当然，也可以制定“靠右原则” 
     */ 
    if(t1 != t2) {  
        f[t2] = t1;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    init(n);

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        merge(x, y);
    }

    /*
     * 输出合并之后的数组情况
     */
    for(int i = 1; i <= n; i++) {
        if(i != 1) {
            cout << " ";
        }
        cout << f[i];
    }
    cout << endl;

    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        // 如果两个人的“朋友祖先”不相同，证明他们不在同一个朋友圈内，也就不是朋友
        if(getFriend(x) != getFriend(y)) {
            cout << "no" << endl; 
        } else {
            cout << "yes" << endl;
        }
    }

    return 0;

} 

