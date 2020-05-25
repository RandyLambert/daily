package main

import "fmt"
import "runtime"
import "sync"

//select
//可处理一个或者多个channel的发送与接受
//同时有多个可用的channel是按随机顺序处理
//可以用空的select来阻塞main函数
//可设置超时
func main(){
    c1,c2 := make(chan int),make(chan string)
    o := make(chan bool,2)
    go func(){ //在select中只要随便关闭一个,则应该退出select
        for{
            select{//select可以作为接受也可以作为发送
            case v,ok:=<c1://select也可以作为定时任务
                if !ok {
                    a = true
                    break
                }
                fmt.Println("c1",v)
            case c,ok:=<c2:
                if !ok{ //关闭就是false
                    b = true
                    break
                }
                fmt.Println("c2",v)
            }
        }
    }()

    c1<-1
    c2<-"hi"
    c1<-3
    c2<-"hello"

    close(c2)
    for i:0;i<2;i++{
        <- 0
    }
}


