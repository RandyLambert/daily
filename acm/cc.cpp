#include<iostream>
using namespace std;
const int maxn=101;
bool a[maxn];//a数组负责存储硬币的状态
int n;//n枚硬币
int main()
{
    cin>>n;
    cout<<n<<endl;//因为相当于只翻一枚，所以翻n次即可
    for(int i=1;i<=n;i++){//i表示这是第几次翻
        for(int j=1;j<=n;j++){//表示当前翻得是第几枚硬币
            if(j!=i){//如果不为第i枚
                if(a[j])a[j]=0;//1变成0
                else a[j]=1;//0变成1
            }
            cout<<a[j];//输出当前状态
        }
        cout<<endl;//别忘了换行
    }
    return 0;
}
