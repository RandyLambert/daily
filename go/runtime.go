package main

import "fmt"
import "runtime"

func main(){

    runtime.GOMAXPROCS(runtime.NumCPU()) 
    //runtime.GOMAXPROCS 是设置程序使用cpu的数量,runtime.NumCPU是返回电脑有的核数
    c := make(chan bool,10) 
    for i := 0; i < 10 ;i++{
        go Go(c,i)
    }
    for i :=10;i<10;i++{
        <-c
    }
}

func Go(c chan bool,index int) {
    a := 1
    for i :=0 ;i < 10000000;i++{
        a+=i
    }
    fmt.Println(index, a)
    c <- true
}

