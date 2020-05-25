package main

import "fmt"
import "runtime"
import "sync"

func main(){

    runtime.GOMAXPROCS(runtime.NumCPU()) 
    //runtime.GOMAXPROCS 是设置程序使用cpu的数量,runtime.NumCPU是返回电脑有的核数
    wg := sync.WaitGroup{}
    wg.Add(10)//先规定10个任务数量,没完成一次减少一个任务数量
    for i := 0; i < 10 ;i++{
        go Go(&wg,i)
    }
    wg.Wait()//同步包,done一次就减一次
}

func Go(wg *sync.WaitGroup,index int) {
    a := 1
    for i :=0 ;i < 10000000;i++{
        a+=i
    }
    fmt.Println(index, a)
    wg.Done()
}

