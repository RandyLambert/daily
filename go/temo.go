package main

// import "fmt"
import (
    "fmt"
    "math"
    "sort"
)
type (
    文本 string
)

var (
    aaa = "hello"
    sss , bbb = 1, 2
)
var    ssss , bbbb = 1, 2
func main(){
    var a [1]bool
    var b []bool
    var c bool
    var d [2]bool
    var e string
    var f int
    var g 文本
    var i uint
    var j uint8
    var h byte
    var k uintptr
    var l float32
    fmt.Println(a)
    fmt.Println(b)
    fmt.Println(c)
    fmt.Println(d)
    fmt.Println(e)
    fmt.Println(f)
    fmt.Println(g)
    fmt.Println(i)
    fmt.Println(j)
    fmt.Println(h)
    fmt.Println(k)
    fmt.Println(l)
    fmt.Println(math.MaxInt32)
    f = 10
    var p *int = &f
    fmt.Println(*p)
    f++
    // f = f++//错误


    if m:=1;m<1{
        fmt.Println("hhhhhhhhhhh")
        //if不能加括号,m是局部变量,同时隐藏外部变量
    }

    //for的三种写法,代替了while语句
    for {
        i++
        if i > 3{
            break
        }
        fmt.Println(i)
    }

    for i < 9 {
        i++
        fmt.Println(i)
    } 

    for i:=0;i<3;i++{
        fmt.Println(i)
    }

    //switch
    //可以使用任何类型或表达式作为条件语句
    //不需要写break,一旦条件符合自动终止
    //如希望继续执行下一个case,需使用fallthrough语句
    // 支持一个初始化表达是可能是并行方式,右侧需跟分号
    // 左大括号必须和条件语句在同一行
    //以下是三种写法
    i = 1
    switch i {
    case 0:
        fmt.Println("i=0")
    case 1:
        fmt.Println("i=1")
    }

    switch {
    case i >= 0:
        fmt.Println("i>=0")
    case i>=1:
        fmt.Println("i>=1")
    }

    switch i = 10;{
    case i >= 0:
        fmt.Println("i>=0")
        fallthrough
    case i >= 1:
        fmt.Println("i>=1")
    }

    //跳转语句goto,break,continue

    //三个语法都可以配合标签使用
    //标签名区分大小写,若不使用会造成编译错误
    //break与contunue配合标签可以用于多层循环的跳出
    //goto是调整执行位置,与其他2个语句配合标签的结果并不相同

    LABEL1:
    for{
        for i:=0;i<10;i++{
            if i>3{
            break LABEL1
            //break是跳出到label1同级的
            //continue是重复label1同级的循环
            //goto是跳到标签的位置,改变执行位置
          }
       }
    }

    //数组array
    //定义数组的格式:var<varName>[n]<type , n> = 0
    // 数组的长度也是类型的一部分,因此具有不同长度的数组为不同类型,
    // 注意区分指向数组的指针和指针数组
    // 数组在go中为值类型
    // 数组之间可以使用==或者!=进行比较,但不可以使用<或>
    // 可以使用new来创建数组,此方法返回一个指向数组的指针
    // go支持多维数组

    a1:=[2]int{1,2}
    var b1 [2]int = a1
    fmt.Println(a1)
    fmt.Println(b1)
    
    a2:= [20]int{19:1}
    fmt.Println(a2)

    a3:= [...]int{0:1,1:2,2:3}
    fmt.Println(a3)

    var p1 *[3]int = &a3 //指向a3的指针p1
    fmt.Println(p1) 
    var p2 [3]*int //存int指针类型的数组
    p2[1] = &f

    p3:=new([10]int)
    fmt.Println(p3) //指向数组的指针p2
    p3[1] = 10

    p4:=[2][3]int{
        {1,1,1},
        {2,2,2}}
    fmt.Println(p4)

    //切片slice
    //其本身并不是数组,他指向底层的数组
    //作为变长数组的替代方案,可以关联底层数组的局部或全部
    //为引用类型
    //可以直接创建或从底层数组获取生成
    //使用len()获取元素个数,cap()获取容量
    //一般使用make()创建
    // 如果使用多个slice指向相同底层数组,其中一个的值改变会影响全部

    // make([]T,len,cap)
    // 其中cap可以省略,则和len的值相同
    // len表示存数的元素个数,cap表示容量

    var s1 []int
    fmt.Println(s1);
    a4 := [10]int{1,2,3,4,5,6,7,8,9}
    fmt.Println(a4)
    // fmt.Println(string(a4))
    s1 = a4[5:10]
    s1 = a4[5:len(a4)]
    s1 = a4[5:]//三个一样
    fmt.Println(s1)

    /********************/
    s2:=make([]int,3,10) //3为初始化的元素数量,10为s2的大小,go使用2倍扩容
    fmt.Println(len(s2),cap(s2),s2)

    //切片重新分配内存
    s3 := a4[2:4]
    s4 := a4[2:5]
    fmt.Println(s3,s4)
    s4[1]=222
    fmt.Println(s3,s4)
    s4 = append(s4,1,2,3,45,67,5,4,342,423,432,3,423,432,42,4324,32,423)
    s4[1] = 321321//在这里改变s4已经不会改变s3了
    fmt.Println(s3,s4)

    //长复制短的,只有短的部分被覆盖
    //短复制长的,只复制长度短的部分
    copy(s3,s4)
    fmt.Println(s3,s4)
    copy(s4,s3)
    fmt.Println(s3,s4)
    sort.Ints(s4)
    fmt.Println(s4)

}    
