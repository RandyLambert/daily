package main

import "fmt"

var c chan string
func Pingpong(){
    i:=0
    for {
        fmt.Println(<-c)
        c<-fmt.Sprintf("From Pingpong:Hi,# %d",i)
        i++
    }
}
func main(){

    c = make(chan string)
    go Pingpong() //类似一个线程,运行pingpong函数
    for i := 0;i < 10 ;i++ {
        c <- fmt.Sprintf("From main :Hello,#%d",i)
        fmt.Println(<-c)
    }
}

