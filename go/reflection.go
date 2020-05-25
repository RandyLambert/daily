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

type Manager struct {
    User //匿名字段,如何通过reflect取出?
    title string
}

func main(){
    m := Manager{User: User{1,"ok",12},title: "123"}
    t := reflect.TypeOf(m)
    fmt.Printf("%#v\n",t.Field(0))//通过索引来取匿名字段
    fmt.Printf("%#v\n",t.FieldByIndex([]int{0, 1}))//通过索引来取匿名字段里的字段
    fmt.Printf("%#v\n",t.Field(1))//通过索引来取

    //通过反射修改内容
    x := 123
    v := reflect.ValueOf(&x) //因为要修改所以传指针
    v.Elem().SetInt(999)     //只有传指针才可以setInt
    fmt.Println(x)

    u := User{1,"ok",12}
    v1 := reflect.ValueOf(u)
    mv := v1.MethodByName("Hello")

    args := []reflect.Value{reflect.ValueOf("joe")} //这一步是给hello里加参数
    mv.Call(args)

    Info(u)
}

func (u User) Hello(name string) {//有参数
    fmt.Println("Hello", name ,", my name is",u.Name)
}

func Info(o interface{}){
    t := reflect.TypeOf(o)
    fmt.Println("Type",t.Name())

    if k:=t.Kind(); k != reflect.Struct {
        fmt.Println("XX") //判读是值还是指针
        return 
    }

    v := reflect.ValueOf(o)
    fmt.Println("Fields")

    for i := 0;i < t.NumField(); i++{
        f := t.Field(i) //反射出方法和对象内容
        val := v.Field(i).Interface()
        fmt.Printf("%6s: %v = %v\n",f.Name,f.Type, val)
    }

    for i:=0;i<t.NumMethod();i++{
        m:=t.Method(i)
        fmt.Printf("%6s : %v\n",m.Name,m.Type)
    }
}

func Set(o interface{}) {
    v := reflect.ValueOf(o)

    if v.Kind() == reflect.Ptr &&!v.Elem().CanSet() {
        fmt.Println("XXX")
        return 
    } else {
        v = v.Elem()
    }

    f := v.FieldByName("Name")
    if !f.IsValid() {
        fmt.Println("BAD")
        return 
    }

    if f.Kind() ==reflect.String {
        f.SetString("BYEBYE")
    }
}
