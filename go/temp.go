package main

import "fmt"

type hhhh struct {
    Name string
    Age int
}

type All interface{}
func main() {
    var flist []func()
    for i := 0; i < 3; i++ {
        // i:=i
        defer fmt.Println(i) //以一个普通函数调用,他保存的是值
        flist = append(flist, func() { //以闭包的形式调用,函数保存的的所指向的地址
            fmt.Println(i)
        })

        a:= hhhh{Name:"dddd",Age:12}
        c := All(a)
        fmt.Print(c.(hhhh))
        var x All = a 
        b,ok:=x.(hhhh)
        fmt.Println(b,ok)
    }

    for _, f := range flist {
        f()
    }
}

