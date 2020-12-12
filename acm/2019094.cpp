#include <bits/stdc++.h>
using namespace std;
struct node{
    int zhong;
    int id;
    int score;
    node(int zhong_,int id_,int score_):zhong(zhong_),id(id_),score(score_){}
    bool operator<(const node &r) const{
        if(score == r.score){
            if(zhong == r.zhong){
                return id < r.id;
            }
            return zhong < r.zhong;
        }
        return score > r.score;
    }
};
set<node> all_;
vector<map<int,int>> vec(100);
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i = 1;i <= n;i++){
        int id,score;
        cin>>id>>score;
        for(int j = 0;j < m;j++){
            vec[j].insert(pair<int,int>(id,score));
            all_.insert(node(j,id,score));
        }
    }
    int opnum = 0;
    cin>>opnum;
    for(int i = 0;i < opnum;i++){
        int op;
        int tid,tscore,lei,K;
        cin>>op;
        if(op == 1){
            cin>>lei>>tid>>tscore;
            all_.insert(node(lei,tid,tscore));
            vec[lei].insert(pair<int,int>(tid,tscore));
        }else if(op == 2){
            cin>>lei>>tid;
            tscore = vec[lei][tid];
            all_.erase(node(lei,tid,tscore));
            vec[lei].erase(lei);
        }else if(op == 3){
            map<int,int> ks;
            int ans[1000];
            memset(ans,0,sizeof(ans));
            int k;
            cin>>K;
            for(int i = 0;i < m;i++){
                cin>>k;
                ks[i] = k;
            }

            for(set<node>::iterator it = all_.begin();it!=all_.end();it++){
                if(ks[it.zhong] > 0 && ans.size() < K){
                    ans.push_back(it.);
                }
            }
        }
    }
    return 0;
}
