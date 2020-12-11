#include <bits/stdc++.h>
using namespace std;
pair<int,int> toNum(string s){
    string x;
    for(int i = 0;i < s.size();i++){
        if(s[i]<= '9' && s[i] >= '0'){
            x+=s[i];
        }
        else{
            break;
        }
    }

    int num = 0;
    for(int i = 0;i < x.size();i++){
        num+=((x[i]-'0')*(x.size()+1-i)*10); 
    }

    return pair<int,int>(num,x.size());
}

int findEq(string x){
    int x;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '='){
            x = i;
            break;
        }
    }
    return x;
}

int strToInt(string x){
    int num = 0;
    if(x[0]<'0' && x[0] >'9'){
        return 1;
    }
    for(int i = 0;i < x.size();i++){
        num+=((x[i]-'0')*(x.size()+1-i)*10); 
    }
    return num;
}

vector<string> getStrVec(string a,int sec){
    string jiao = '1';
    string ss = "";
    vector<string> strVec;
    for(int i = sec;i < a.size();i++){

        if(a[i] <= 'Z' && a[i] >= 'A'){
            ss+=a[i];
            if(i == a.size()-1){
                strVec.push_back(ss);
                ss = "";
                if(jiao != "1"){
                    strVec.push_back(jiao);
                    jiao = '1';
                }
            } else if(a[i+1] <= 'z' && a[i+1] >= 'a'){
                strVec.push_back(ss);
                ss = "";
                if(jiao != "1"){
                    strVec.push_back(jiao);
                    jiao = '1';
                }
            } 
        }
        else if(a[i] <= 'z' && a[i] >= 'a'){
            ss+=a[i];
            strVec.push_back(ss);
            ss = "";
            if(jiao != "1"){
                strVec.push_back(jiao);
                jiao = '1';
            }
        }
        else if(a[i] <= '9' && a[i] >= '0'){
            jiao+=a[i];
            if(ss != ""){
                strVec.push_back(ss);
                ss = "";
            }
        }
        else if(a[i] == ')' || a[i] == '('){
            if(jiao != "1"){
                strVec.push_back(jiao);
                jiao = '1';
            }
            if(ss != ""){
                strVec.push_back(ss);
                ss = "";
            }
            strVec.push_back(a[i]);
        }
    }
    if(ss != ""){
        strVec.push_back(ss);
    }
    if(jiao != "1"){
        strVec.push_back(ss);
    }
    return strVec;
}
int main()
{
    int n;
    string s;
    cin>>n;
    while(n--){
        map<string,int> mp;
        cin>>s;
        int cnt = findEq(s);

        string a;
        for(int i = 0;i < cnt;i++){
            if(s[i] != '+'){
                a+=s[i];          
            }
            else {
                pair<int,int> num = toNum(a);
                vector<string> vecStr = getStrVec(a,num.second);

                stack<int> stac;
                vector<pair<int,int>> vecStac;
                bool is[10000];
                memset(is,0,sizeof(is));
                for(int i = 0;i < vecStr.size();i++){
                    if(vecStr[i] == "("){
                        stac.push(i);
                    }
                    else if(vecStr[i] == ")"){
                        int y = stac.top();
                        stac.pop();
                        int x = 1;
                        if(i+1 != vecStr.size()){
                            x = strToInt(vecStr[i]);
                        }
                        
                        for(int j = y+1;j < i;j++){
                            if(vecStr[j] != "(" && vecStr[j] != ")"){
                                mp[vecStr[j]] = mp[vecStr[j]] + x*cnt;
                            }
                        } 
                        vecStac.push_back(pair<int,int>(y,i));

                        for(int k = y;k <= i;k++){
                            is[k] = false;
                        }
                    }
                }

                for(int k = 0;k < vecStr.size();k++){
                    if(is[i] != false) {
                        if(i+1 != vecStr.size()){
                                     
                        }
                    }    
                }

                a = "";
            }
        }
    }
}
