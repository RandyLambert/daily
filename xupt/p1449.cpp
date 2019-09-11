#include <bits/stdc++.h>
using namespace std;

stack <int> q;

int main(){
   char a;
   int s = 0;
    while(a!='@'){
        scanf("%c",&a);
        if(a == '+'){
            int temp1 = q.top();
            q.pop();
            int temp2 = q.top();
            q.pop();
            int temp3 = temp1 + temp2;
            q.push(temp3);
        }
        else if(a == '-'){
            int temp1 = q.top();
            q.pop();
            int temp2 = q.top();
            q.pop();
            q.push(temp2 - temp1);
        }
        else if(a == '*'){
            int temp1 = q.top();
            q.pop();
            int temp2 = q.top();
            q.pop();
            q.push(temp2 * temp1);
        }
        else if(a == '/'){
            int temp1 = q.top();
            q.pop();
            int temp2 = q.top();
            q.pop();
            int temp3 = temp2 / temp1;
            q.push(temp3);
        }
        else if(a == '.'){
            q.push(s);
            s = 0;
        }
        else{
            s = s*10 + a - '0';
        }
    }
    printf("%d\n",q.top());
    return 0;
}
