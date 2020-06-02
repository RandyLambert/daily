package main

import "fmt"

func main(){
    var a []int = []int{1,2,3}
    fmt.Println(len(a),cap(a))
    var b []int
    fmt.Println(len(b),cap(b))
    a = append(a,10)
    fmt.Println(len(a),cap(a))
    b = make([]int,1,2)
    copy(b,a)
    fmt.Println(len(b),cap(b),b)
    c := [...]int{1,2,3,45,6,67,7}
    var d []int = c[1:4]
    fmt.Println(d)



}

