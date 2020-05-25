package main

import "fmt"

//channel
//channel 是goroutine沟通的桥梁,大都是阻塞同步的
//通过make创建,close关闭
//channel是引用类型
//可以设置单向或者双向通道
//可以设置缓存大小,在未被填满之前不会发生阻塞
func main(){
    c := make(chan bool)
    // c := make(chan bool,1) //有无缓存,有缓存就可以实现异步
    go func(){
        fmt.Println("GO GO GO!!!")
        c <- true //通过channel来通知主线程执行完毕
        close(c)  //chan必须在某个地方关闭,不然就死锁了
    }()
    for  v := range c{
        fmt.Println(v)
    }
     // <- c等待取chan,如果没有的话,就一直等待,因此main函数不会退出
}


