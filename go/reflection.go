package main

import "fmt"
import "reflect"

//反射
//反射可大大提高程序的灵活性,是interface()有更大的发挥余地
//反射使用typeof和valueof函数从接口中获取目标对象的信息
//反射会将匿名字段作为独立字段(匿名字段本质)
//想要利用反射修改对象状态,前提是interface.data是settable,即pointer-interface
//通过反射可以"动态"调整方法

type User struct {
    Id int
    Name string
    Age int
}

func(u User) Hello() {
    fmt.Println("Hello world.")
}
func main(){
    u := User{1,"ok",12}
    Info(u)
}

func Info(o interface{}){
    t := reflect.TypeOf(o)
    fmt.Println("Type",t.Name())

    v := reflect.ValueOf(0)
    fmt.Println("Fields")

    for i := 0;i < t.NumField(); i++{
        f := t.Field(i) //反射处方法和对象内容
        val := v.Field(i).Interface()
        fmt.Printf("%6s: %v = %v\n",f.Name,f.Type, val)
    }

    for i:=0;i<t.NumMethod();i++{
        m:=t.Method(i)
        fmt.Printf("%6s:%v\n",m.Name,m.Type)
    }
}

