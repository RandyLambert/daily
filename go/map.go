package main

import "fmt"
import "sort"

func main(){
    var m map[int]string = make(map[int]string)
    m1  := make(map[int]string)
    m[1] = "ok"
    delete(m,1)
    a,ok := m[1]
    fmt.Println(a,m1)
    /*****************************/
    //复杂map,二维map
    var m2 map[int]map[int]string
    m2 = make(map[int]map[int]string)
    a,ok = m2[2][1]
    if !ok {
        m2[2] = make(map[int]string)
    }

    m2[2][1] = "good"
    a,ok=m2[2][1]
    fmt.Println(a,ok)

    var arr []int = []int{1,2,34,55324,24}
    sort.Ints(arr)
    fmt.Println(arr)

    for i,j := range m2 {
        fmt.Println(m2[i],j)
    }

    /****************************/
    sm := make([]map[int]string, 5)
    for _, v := range sm {
        v = make(map[int]string, 1)
        v[1] = "ok"
        //v是临时的赋值改变不会对sm内影响
        fmt.Println(v)
    }
    fmt.Println(sm)

}

