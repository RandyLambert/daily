//当前程序的包名
package main

//导入其他的包
import "fmt"

//常量的定义
const PI = 3.14
const (
    da = "dsa" 
    a  = "dsaadsad"
    xa
)

//全局变量的声明与赋值
var name = "gopher"
var (
    nam = "dsdsa"
    dda = "dssad"
    dasda = "dasdsa"
)

//一般类型声明
type newType int
type (
    dsad = 1
    xdasda = 2
    xdsdsa = 4
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
}

