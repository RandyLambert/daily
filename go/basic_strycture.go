//当前程序的包名
package main

//导入其他的包
import "fmt"
//go变量声明了就得使用

//常量的定义
//常量的值在编译是就已经确定了
//常量的定义格式与变量基本相同
const PI = 3.14
const a int = 1
const aaa,bbb,ccc = 1,2,3
const (
    da string = "dsa" 
    //等号右侧必须是常量或者常量表达式
    aqq  = "dsaadsad"
    //常量表达是中的函数必须是内置函数
    length = len(da) //da要是常量,只能用常量给常量赋值,编译器就要有结果 
    num = length*20
    //等号右侧必须是常量或者常量表达式
    xa 
    //常量可以为空,默认是上一个值,所以也可以这么写
    xxx, yyy = 1,"2"
    zzz, iii //zzz=  1,yyy="2"但是使用这个初始化规则,上下必须匹配
    
)

//常量初始化规则与枚举
//在定义常量组的时候,如果不提供初始值,则表示使用上行的表达式
//使用相同的表达式不代表具有相同的值
//iota是常量的计数器,从0开始,组中每定义一个常量自动递增1
// 通过初始化规则和iota可以达到枚举的效果
//没遇到一个const关键字,iota就会被重置为0
//常量使用规范:尽量全部使用大写,如果不想让外部使用,可以在前面加上_
const (
    //a与b都是"a"
    ai = "a"
    bi 
    ci = iota //ci为2
    di // di的值为3
)

const (
    ei = iota //第一个常量必须有一个常量表达式,不可以省略
    fi //fi的值为1
    fj //fj的值为1
    fk //fk的值为1
)


//全局变量的声明与赋值,可以使用类型推断
//全局变量的声明可以使用var()的方式简写
var name = "gopher"
var (
    nam = "dsdsa"
    // 使用常规的方式
    dda = "dssad"
    //使用并航的方式以及类型推断
    sss, zzzz = 1,2
    // ccc := 3 //不可省略var的写法
    dasda = "dasdsa"
)
// ccc := 3 //不可省略var的写法

//一般类型声明
type newType int
type (
    dsadad int
    xdasdaa float32
    xdsdsa = byte
)

//结构的声明
type gopher struct{}

//接口的声明
type golang interface{}

//由main函数作为程序的入口
func main(){

    fmt.Println("Hello world!")
    fmt.Println(da)
    fmt.Println(a)
    fmt.Println(xa)
    //局部变量 可以使用类型推断
    var a int  //变量的声明
    a = 123    //变量的赋值

    //变量声明的同时赋值
    var b int = 321
    //上行的格式可省略变量类型,有系统推断
    var c = 321
    //变量声明与复制的最简写法,省略var
    d := 456
    //局部变量不可以使用var()的方式简写,只能使用并行方式
    //var (
    //    nam = "dsdsa"
    //    // 使用常规的方式
    //    dda = "dssad"
    //    //使用并航的方式以及类型推断
    //    sss, bbb = 1,2
    //    // ccc != 3 //不可省略var的写法
    //    dasda = "dasdsa"
    //)
    
    //多个变量的声明
    var a1, b1, c1, d1 int
    //多个变量的赋值
    a1, b1, c1, d1 = 1, 2, 3, 4

    //多个变量的声明同时赋值
    var e1,f1,g1,h1 = 9, 10, 11, 12
    //多个变量声明与赋值的最简写法
    i,m,n,o:=13,14,15,16
    xyz,_ :=1,2 //空白符号删除

    //go不存在隐式转换,所有的类型转换必须显示声明
    //转换只能发生在两种相互兼容的类型之间
    //类型转换的格式:
    //在相互兼容的两种类型之间进行转换
    var a2 float32 = 1.1
    b2:= int(a2)
    var c2 = int(a2)
    var d2 int
    d2 = int(a2)

    // 以下表达式无法通过编译
    // var c bool = true
    // d:= int(c)


    

}

