package main

import "fmt"
import "time"

func main(){
    now :=time.Now()
    fmt.Printf("type = %T val = %v\n",now,now)
    
    //2.通过now可以获得
    fmt.Printf("%v \n",now.Year())
    fmt.Printf("%v \n",now.Month())
    fmt.Printf("%v \n",now.Day())

    //格式化日期时间
    fmt.Printf(now.Format("2006/01/02 15:04:05")) //只能是这个时间

    var a[] int = make([]int,0)
    a = append(a,100)
    a = append(a,10)
    fmt.Println(a)

    b := []int{1,2,3,4}
    b = append(b,10)
    fmt.Println(b,len(b),cap(b))
}

