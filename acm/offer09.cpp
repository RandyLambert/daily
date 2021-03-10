class CQueue {
public:
    CQueue() {

    }
    stack<int> s1;
    stack<int> s2;

    void appendTail(int value) {
        // if(!s1.empty()){
            s1.push(value);
        // }
    }
    
    int deleteHead() {
        int ans = 0;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(s2.size() > 0){
                ans = s2.top();
                s2.pop();
            }  else {
                return -1;
            }
        } else {
            ans = s2.top();
            s2.pop();
        }
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
