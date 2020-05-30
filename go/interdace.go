package main

import "fmt"
import "reflect"
//接口
//接口是一个或者多个方法签名的集合
//只要某类型拥有了该接口的所有方法签名,即算实现了该接口,无需显示声明实现了那个接口
//这称为structural typing
//接口只有方法声明,没有实现和数据
//接口可以匿名嵌入其他接口与,或嵌入结构中
//将对象复制给接口时,会发生拷贝,而接口内部存储的是指向这个复制品的指针,即无法修改复制品的状态,也无法获取指针
//只有当接口存储的类型和对象都为nil是,接口才等于nil
//接口调用不会做receiver的自动转换
//接口同样会支持匿名字段的方法
//接口也可以实现类似oop中的多态
//空接口可以组委任何类型数据的容器

type empty interface{

}
//go语言里,只要你有该接口的方法,就相当于实现了相关接口
type USB interface {
    Name() string
    Connecter
}
type Connecter interface {
    Connect()
}

type PhoneConnecter struct {
    name string
}

func (pc PhoneConnecter) Name() string {
    return pc.name
}

func (pc PhoneConnecter) Connect() {
    fmt.Println("Connected",pc.name)
}

func main(){
    var a USB
    // var a Connecter因为实现了接口,所以可以这样调用 
    a = PhoneConnecter{"nnecter"}
    a.Connect()
    Disconnect(a)


    //只有当接口存储的类型和对象都为nil是,接口才等于nil
    var x interface{}
    fmt.Println(x == nil)

    var p *int = nil
    x = p
    fmt.Println(x == nil)

    var c float64 = 12.44
    var d string = "12.44"

    value := reflect.ValueOf(c)
    value1 := reflect.ValueOf(d)
    fmt.Println(value)
    fmt.Println(value.Interface().(float64))
    fmt.Println(value1)
    fmt.Println(value1.Interface())

}

// func Disconnect(usb USB){
func Disconnect(usb interface{}){ //空接口所以都实现了
    //;里面可以写switch case
    //类型断言的ok pattern可以判断接口中的数据类型
    //使用type switch则可以针对空接口进行比较全面的类型判断

    //接口转换
    //可以将拥有超集的接口转换为子集的接口

    if pc ,ok:=usb.(PhoneConnecter); ok{
        fmt.Println("Disconnected.",pc.name)
        return
    }
    fmt.Println("Unknown")
}

