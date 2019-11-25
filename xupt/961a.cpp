#include <iostream>//输入输出流库
#include <cstring>//memset库
using namespace std;
int main(){
    int s[1001]/*桶*/,n,m,a,minn=1000/*统计最小的*/;
    memset(s,0,sizeof(s));//清零
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        s[a]++;//往桶里面填充
    }
    for(int i=1;i<=n;i++)
        if(s[i]<minn) minn=s[i];//比较，寻找最小
    cout<<minn<<endl;
    return 0;//一道CF水题就这么结束了
}
