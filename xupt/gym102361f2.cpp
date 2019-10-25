#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
using namespace std;
int u, v, n, m, path[maxn], vis[maxn];
LL ans = 1, cnt, mod = 998244353, sum = 0;
vector<int> g[maxn];

LL qpow(LL x) {
    LL res = 1, temp = 2;
    while (x) {
        if (x & 1) {
            res = (res * temp) % mod;
        }
        temp = (temp * temp) % mod;
        x >>= 1;
    }
    return res % mod;
}

/* void dfs1(int now,int pre){ */
/*     vis[now] = 1; */
/*     for(auto to : g[now]){ */
/*         if(to == pre) */
/*             continue; */
/*         else{ */
/*             if(vis[to] == 0){ */
/*                 path[to] = now; */               
/*                 dfs1(to,now); */
/*             } */
/*             else if(vis[to] == 2){ */
/*                 continue; */
/*             } */
/*             else{ */
/*                 int temp = now; */
/*                 while(temp != to){ */
/*                     cnt++; */
/*                     temp = path[temp]; */
/*                 } */
                
/*             } */
/*         } */
/*     } */
/*     vis[now] = 2; */
/* } */





void dfs(int now, int pre) {
    vis[now] = 1;
    for (size_t i = 0; i < g[now].size(); ++i) {
        int to = g[now][i];
        if (to == pre)
            continue;
        if (vis[to] == 0) {
            path[to] = now;
            dfs(to, now);
        }
        else if (vis[to] == 2) {
            continue;
        }
        else {
            int temp = now;
            cnt = 1;
            while (temp != to) {
                ++cnt;
                temp = path[temp];
            }
            sum += cnt;
            ans = (ans * (qpow(cnt) - 1)) % mod;
        }
    }
    vis[now] = 2;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            dfs(i, 0);
        }
    }

    printf("%lld\n", qpow(m - sum) * ans % mod);
}
