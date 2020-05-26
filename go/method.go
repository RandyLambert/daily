package main

import "fmt"

type TZ int

func main(){
    var a TZ 
    (*TZ).fun(&a,8) //两种方法methodexp
    a.fun(19)       //method value

}

func (a *TZ) fun(b int){
    *a = TZ(b)
    fmt.Println(*a)
}
