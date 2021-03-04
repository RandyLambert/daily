class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> a1;
    stack<int> a2;
    int front;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(a1.empty()){
            front = x;
        }
        a1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(a2.empty()){
            while(!a1.empty()){
                a2.push(a1.top());
                a1.pop();
            }
        }
        int ret = a2.top();
        a2.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if(!a2.empty()){
            return a2.top();
        } else {
            return front;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        // cout<<a1.empty() <<a2.empty();
        return a1.empty() && a2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
