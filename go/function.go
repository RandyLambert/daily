package main

import "fmt"

func main(){
    //go函数不支持嵌套重载和默认参数
    //无需声明原型,不定长度变参,多返回值,命名返回值采纳数,匿名函数,闭包

    //定义函数使用关键字func,且左大括号不能另起一行,函数可以作为一种类型使用 

    A(1,2,324,34,35,34,5,43,534,5,34,5,34)
    A(1,'a')
    var x []int
    B(x)
    fmt.Println(x)
    a := A //把函数当做类型来使用
    a(1,2,3)
    b := func(){ //匿名函数,不能放到外面写,得放到里面
        fmt.Println("func a")
    }
    b()

    f := closure(10)
    fmt.Println(f(1))
    fmt.Println(f(2))

    // defer的执行方式类似与其他语言的析构函数,在函数体执行结束之后,
    // 按照调用顺序的相反顺序逐个执行
    // 即使函数发生严重错误也会执行
    // 支持匿名函数的调用
    // 通常用于资源清理,文件关闭,解锁以及记录时间等操作
    // 通过与匿名函数配合可在return之后修改函数计算结果
    // 如果函数体内某个变量作为defer是匿名函数的参数,则
    // 定义defer时即以获得了拷贝,否则是引用某个变量的地址

    // go没有异常机制,但有panic/recover模式来处理错误
    // panic可以在任何地方引发,单recover只有在defer调用的函数中有效
    defer fmt.Println("b")
    defer fmt.Println("c")
    defer fmt.Println("d")
    defer fmt.Println("e") //逆序调用,先定义的后执行


    for i:=0 ;i < 3;i++{
        defer func(){
            fmt.Println(i)
        }() //闭包函数,如果不把值作为值传递进去,他默认的都是穿进去的地址,所以个这个i传的是u的地址,所以一直打印的是3
    }

    D()
    E()
    F()
}

// func A(a int,b string)(int,string)
// func A(a,b,c int) int 
// func A(a,b,c int)(a,b,c int){
func A(a ...int){ //不定长参数,但是不定长参数一定放到函数的最后一个参数,传递的是值类型
    fmt.Println(a)
}
func B(a []int){ //传递的是引用类型
    fmt.Println(a)
}
// func C(a ...*int){ //传递的是地址类型
//     fmt.Println(*a)
// }
func closure(x int) func(int) int{ //闭包
    return func(y int) int{
        return x + y
    }
}

func D(){
    fmt.Println("Func A")
}

func E(){
    defer func(){//无论发生什么事情都会执行,所以把recover放到这个函数里面
        if err:=recover();err!=nil{
            fmt.Println("Recover in B")
        }
    }()
    panic("Panic int B")
}

func F(){
    fmt.Println("Func C")
}
