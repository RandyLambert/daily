#include<bits/stdc++.h>
using namespace std;
class Plusandjian{
public:
	int n,m,shuzu,data,ans[21][21];
	vector<pair<int,int> >mp[21];
	
	Plusandjian(int n_,int m_){
		this->m = m_;
		this->n = n_;
		memset(ans,0,sizeof(ans));
	}
	
	Plusandjian(){
		printf("请先输入矩阵的宽和长：");
		scanf("%d %d",&m,&n);
	}
	
	void init(){
		
		int data;
		printf("请按按照行优先进行输入,空白处输入0\n");
		
		printf("请输入矩阵\n"); 
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				scanf("%d",&data);
				if(data != 0){
					pair<int,int> b;
					b.first = j;
					b.second = data;
					mp[i].push_back(b);
				}
			}
		}
	}
	
	void print(){
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				printf("%d ",ans[i][j]);
			}
			putchar('\n');
		}
	}
	
	Plusandjian operator+(Plusandjian &b){
		size_t cnt,cnt1;
		for(int i = 0;i < m;i++){
			cnt = 0,cnt1 = 0;
			for(int j = 0;j < n;j++){
				if(this->mp[i][cnt].first == j && b.mp[i][cnt1].first == j){
					ans[i][j] = this->mp[i][cnt].second + b.mp[i][cnt1].second;
					if(cnt < this->mp[i].size())
						cnt++;
					if(cnt1 < b.mp[i].size())
						cnt1++;
				}
				else if(this->mp[i][cnt].first == j){
					ans[i][j] = this->mp[i][cnt].second;
					if(cnt < this->mp[i].size())
						cnt++;
				}
				else if(b.mp[i][cnt1].first == j){
					ans[i][j] = b.mp[i][cnt1].second;
					if(cnt1 < b.mp[i].size())
						cnt1++;
				}
			}
		}
        return *this;
	}
	
	Plusandjian operator-(Plusandjian &b){
		size_t cnt,cnt1;
		for(int i = 0;i < m;i++){
			cnt = 0,cnt1 = 0;
			for(int j = 0;j < n;j++){
				if(this->mp[i][cnt].first == j && b.mp[i][cnt1].first == j){
					ans[i][j] = this->mp[i][cnt].second - b.mp[i][cnt1].second;
					if(cnt < this->mp[i].size())
						cnt++;
					if(cnt1 < b.mp[i].size())
						cnt1++;
				}
				else if(this->mp[i][cnt].first == j){
					ans[i][j] = this->mp[i][cnt].second;
					if(cnt < this->mp[i].size())
						cnt++;
				}
				else if(b.mp[i][cnt1].first == j){
					ans[i][j] = -b.mp[i][cnt1].second;
					if(cnt1 < b.mp[i].size())
						cnt1++;
				}
			}
		}
        return *this;
	}		
};
int main()
{
	Plusandjian a;
	a.init();
	Plusandjian b;
	b.init();
	Plusandjian c = a+b;
    Plusandjian d = a-b;
    printf("加法：\n");
	c.print();
    printf("减法：\n");
    d.print();
	return 0;
}

