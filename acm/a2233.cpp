#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main()
{

    int h1,m1,s1,h2,m2,s2;
    int t = 0;
    cin>>h1>>m1>>s1;
    cin>>h2>>m2>>s2;

    while(h1 != h2 || m1 != m2 || s1 != s2){
//        cout<<h1 <<" "<<m1<<" "<<s1<<endl;
//        usleep(1000);
        if(s1+1 != 60){
            s1++;
            t++;
        }
        else{
            t++;
            s1 = 0;

            if(m1+1 != 60){
                m1++;
            }
            else{
                m1 = 0;
                if(h1+1 != 24){
                    h1++;
                }
                else{
                    h1 = 0;
                }
            }
        }
    }
    int hour =t/60/60;
    int min = t/60 - hour*60;
    int second = t - hour*60*60 - min*60;
    cout<<hour<<" "<<min<<" "<<second<<endl;
    return 0;
}
