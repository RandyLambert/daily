#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 50010;
int father[N];
int in[N];
vector<pair<int,int>> dayu;
vector<int>G[N];

int find(int x) {
    if (father[x] == -1)
        return x;
    return father[x] = find(father[x]);
}

void judge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y){
        father[x] = y;
    }
}

void setZero(){
    for(int & i : father){
        i = -1;
    }
    memset(in,0,sizeof(in));
    for(auto & i : G){
        i.clear();
    }
    dayu.clear();
}

bool topo(){
    queue<int>Q;
    int sum=0;
    for(int i=0;i<N;i++){
        if(in[i]==0)
            Q.push(i);
    }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        sum++;
        for(int v : G[u]){
            --in[v];
            if(in[v]==0)
                Q.push(v);
        }
    }
    return sum==N;
}

int main()
{
    int n,m;
        scanf("%d%d",&n,&m);
        char op;
        int x,y;
        string ans{"consistent"};
//        setZero();
        for(int i = 0;i < m;i++){
            scanf("%d %c %d",&x,&op,&y);
//            cout<<x<<op<<y<<endl;
            if(op == '='){
                judge(x, y);
            }
            else if(op == '>'){
                dayu.emplace_back(x,y);
            }
        }
        for(auto const&value : dayu){
            if(find(value.first) == find(value.second)) {
                ans = "inconsistent";
                break;
            }else{
                G[find(value.first)].push_back(find(value.second));
                in[find(value.second)]++;
            }
            if(topo()==1){
                ans = "consistent";
            }
            else{
                ans = "inconsistent";
            }
        }
        cout<<ans<<endl;
    return 0;
}



//
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1000;
//vector<int>G[maxn];
//int n,m;
//int in[maxn];
//bool topo(){
//    queue<int>Q;
//    int sum=0;
//    for(int i=1;i<=n;i++){
//        if(in[i]==0)
//            Q.push(i);
//    }
//    while(!Q.empty()){
//        int u=Q.front();
//        Q.pop();
//        sum++;
//        for(int i=0;i<G[u].size();i++){
//            int v=G[u][i];
//            --in[v];
//            if(in[v]==0)
//                Q.push(v);
//        }
//    }
//    return sum==n;
//}
//int main()
//{
//    int u,v;
//    while(scanf("%d%d",&n,&m)!=EOF){
//        if(n==0 && m==0)
//            break;
//        memset(in,0,sizeof(in));
//        for(int i=1;i<=n;i++){
//            G[i].clear();
//        }
//        for(int i=1;i<=m;i++){
//            scanf("%d%d",&u,&v);
//            u++;
//            v++;///标号从1开始
//            G[u].push_back(v);
//            in[v]++;
//        }
//        if(topo()==1){
//            puts("YES");
//        }
//        else{
//            puts("NO");
//        }
//    }
//    return 0;
//}
//



//using ll = long long;
//const int N = 200010;
//int father[N];
//char person[N];
//int ans;
//int find(int x) {
//    if (father[x] == -1)
//        return x;
//    return father[x] = find(father[x]);
//}
//
//void judge(int x, int y) {
//    x = find(x);
//    y = find(y);
//    if (x != y){
//        father[x] = y;
//        ans++;
//    }
//}
//
//void setZero(){
//    for(int i = 0;i < 200010;i++){
//        father[i] = -1;
//    }
//}
//int main2() {
//
//    int xx;
//    scanf("%d",&xx);
//    while(xx--){
//        ans = 0;
//        setZero();
//        int peopleNum,n,m;
//        scanf("%d",&peopleNum);
//        memset(person,0,sizeof(person));
//        scanf("%s",person);
//        getchar();
//        scanf("%d%d", &n, &m);
//        for (int i = 1; i <= m; i++) {
//            int x, y;
//            scanf("%d%d", &x, &y);
//            judge(x, y);
//        }
//
////        int cnt = 0;
////        for (int i = 0; i < n; i++)
////            if (find(i) == i)
////                cnt++;
//        if(person[(m-ans)%peopleNum] == '1')
//            printf("%d\n"/*, cnt*/,2);
//        else
//            printf("%d\n",1);
//    }
//
//    return 0;
//}

int main1() {
    ll allday,n,year,month,day;
    ll allday2,year2,month2,day2;
    string week;
    map<ll,string> mpstring{{0,"Monday"},
                            {1,"Tuesday"},
                            {2,"Wednesday"},
                            {3,"Thursday"},
                            {4,"Friday"}};

    map<string,ll> mpint{{"Monday",0},
                         {"Tuesday",1},
                         {"Wednesday",2},
                         {"Thursday",3},
                         {"Friday",4}};
//    scanf("%d",&n);
    ios::sync_with_stdio(false);
    cin>>n;
    //    getchar();
    while(n--){
        cin>>year>>month>>day>>week;
//        scanf("%d%d%d%s",&year,&month,&day,&week);
//        getchar();
        allday = year*360+month*30+day;
//        scanf("%d%d%d%s",&year2,&month2,&day2);
//        getchar();
        cin>>year2>>month2>>day2;
        allday2 = year2*360+month2*30+day2;
//        cout<<allday<<" "<<allday2<<endl;
        if(allday2 >= allday){
            cout<<mpstring[(allday2-allday+mpint[week])%5]<<"\n";
        }
        else{
            ll x = (mpint[week]);
            ll y = (allday-allday2)%5;
            ll ans;
            if(x >= y){
                ans = x-y;
            }
            else{
                ans = x+5-y;
            }
            cout<<mpstring[ans]<<"\n";
        }
    }
    return 0;
}
