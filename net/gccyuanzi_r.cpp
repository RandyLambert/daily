#include <iostream>
#include <unistd.h>
using namespace std;

template<typename T>
class AtomicIntegerT 
{
public:
    AtomicIntegerT()
        : value_(0)
    {
    }

    // uncomment if you need copying and assignment
    //
    // AtomicIntegerT(const AtomicIntegerT& that)
    //   : value_(that.get())
    // {}
    //
    // AtomicIntegerT& operator=(const AtomicIntegerT& that)
    // {
    //   getAndSet(that.get());
    //   return *this;
    // }

    T get()
    {
        // in gcc >= 4.7: __atomic_load_n(&value_, __ATOMIC_SEQ_CST)
        return __sync_val_compare_and_swap(&value_, 0, 0);
    }

    T getAndAdd(T x)
    {
        // in gcc >= 4.7: __atomic_fetch_add(&value_, x, __ATOMIC_SEQ_CST)
        return __sync_fetch_and_add(&value_, x);
    }

    T addAndGet(T x)
    {
        return getAndAdd(x) + x;
    }

    T incrementAndGet()
    {
        return addAndGet(1);
    }

    T decrementAndGet()
    {
        return addAndGet(-1);
    }

    void add(T x)
    {
        getAndAdd(x);
    }

    void increment()
    {
        incrementAndGet();
    }

    void decrement()
    {
        decrementAndGet();
    }

    T getAndSet(T newValue)
    {
        // in gcc >= 4.7: __atomic_store_n(&value, newValue, __ATOMIC_SEQ_CST)
        return __sync_lock_test_and_set(&value_, newValue);
    }

private:
    volatile T value_;
};
/* AtomicIntegerT<int> q; */

int q = 0;
void *arg(void *ag){
    /* q.add(10); */
    q+=10;
    /* cout<<"-------"<<pthread_self()<<"-------"<<q.get()<<"-----"<<endl; */
    return NULL;
}

int main(){
    /* const char *a = "sdasdsadsa"; */
    /* char b = __sync_fetch_and_add(const_cast<char *>(a),6); */
    /* cout<<b<<endl; */
    /* int *c = new int; */
    /* *c = 10; */
    /* int c = 1; */
    /* int d = __sync_fetch_and_add(&c,10); */
    /* cout<<c<<endl; */
    /* cout<<d<<endl; */
    
    /* cout<<q.get()<<endl; */
    /* q.addAndGet(10); */
    /* cout<<q.get()<<endl; */
    /* q.increment(); */
    /* cout<<q.get()<<endl; */
    pthread_t pid[5];
    for(int i = 0;i < 5;i++){
        pthread_create(&pid[i],NULL,arg,NULL);
    }

    pthread_join(pid[0],NULL);
    pthread_join(pid[1],NULL);
    pthread_join(pid[2],NULL);
    pthread_join(pid[3],NULL);
    pthread_join(pid[4],NULL);
    /* cout<<q.get()<<endl; */
    cout<<q<<endl;

    return 0;
}

