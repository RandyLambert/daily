// leetcode 1115
class FooBar {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int cnt = 0;
public:
    FooBar(int n) {
        this->n = n;
        cnt = 0;
    }
    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock,[this]{ return cnt%2==0;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            cnt++;
            lock.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock,[this]{ return cnt%2==1;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printBar();
            cnt++;
            lock.unlock();
            cv.notify_one();
        	// printBar() outputs "bar". Do not change or remove this line.

        }
    }
};
