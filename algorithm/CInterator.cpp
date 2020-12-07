/*
 * @Date: 2020-12-01 15:08:03
 * @LastEditors: OBKoro1
 * @LastEditTime: 2020-12-01 16:56:03
 * @FilePath: /LibraryCodeComments/coroutine/CInterator.cpp
 * @Auther: SShouxun
 * @GitHub: https://github.com/RandyLambert
 */
#include <string>
#include <iostream>
using namespace std;
class CIterator {
public:
    
    CIterator():it(nullptr),index(0) {}
    CIterator(const std::string *sp):it(sp),index(0){}
    CIterator(const CIterator &rhs):it(rhs.it),index(0){} 
    // char operator*(){return *(it->data() + index); }

    const string next() {
        int idx = findSplit();
        int right,left = -1;
        if(idx != -1) {
            bool flag = false;
            if ((*it)[idx+1] == '[') {
                while(idx < (*it).size()) {
                    idx ++;
                    if((*it)[idx] == '[' && (*it)[idx+1] != '['){
                        left = idx+1;    
                        break;
                    }
                }

                while (idx < (*it).size()) {
                    idx ++;
                    if((*it)[idx] == ',' || (*it)[idx] == ']'){
                        right = idx-1;
                        break;
                    }
                }
            } else if((*it)[idx+1] != '[') {
                left = idx+1;
                index = left;
                while (idx < (*it).size()) {
                    idx ++;
                    if((*it)[idx] == ',' || (*it)[idx] == ']'){
                        right = idx-1;
                        break;
                    }
                }
            }
            
            cout<<right<<" "<<left<<endl;
            if(right != -1 && left != -1) {
                // cout<<(*it)[right]<<endl
                index = left;
                return (*it).substr(left, right - left + 1);
            } else {
                return nullptr;
            }
        } else {
            return nullptr;
        }
    }
    bool hasNext() {
        if(findSplit() != -1){
            return true;
        }
        return false;
    }
private:
    int findSplit() {
        for(int i = index;i < (*it).size(); i++){
            if((*it)[i] == ','){
                return i;
            }
        }
        return -1;
    }
    const std::string* it;
    int index;
};

int main(){

    string a("[a,[[[b]],c],[[c]]]");
    // string a("[a,b,c],[[c]]]");
    // string a("[a]");
    CIterator it(&a);
    cout << it.hasNext() << endl;
    cout << it.next() << endl;
    cout << it.next() << endl;
    cout << it.next() << endl;
    return 0;
}