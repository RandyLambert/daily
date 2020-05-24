package main

import "fmt"
type test struct{}
type person struct{
    Name string
    Age int
}

type person1 struct {
    Name string
    Age  int
    Contact struct { //匿名类型
        Phone, City string
    }
}

type person2 struct {
    string
    int//匿名的
}

type student struct {
    person
    Name string
    Age int
}

type A struct {
    Name string
}

type B struct {
    Name string
}

type TZ int

func main(){
    //go的struct支持指向自身的指针类型成员
    //支持匿名结构,可以用作成员或定义成员变量
    //匿名结构也可以用作map的值
    //可以使用字面值对结构进行初始化
    //允许通过指针进行读写结构成员
    //相同类型的成员可进行直接拷贝赋值
    //支持==与!=比较运算符,单不支持>或<
    //支持匿名字段,本质上是定义了以某个类型名为名称的字段
    //嵌入结构作为匿名字段看起来想继承,但不是继承
    //可以使用匿名字段指针

    // a := person{
    a := &person{
        Name:"yyy",
        Age:12,
    }
    a.Age = 10  //go不通过指针访问
    a.Name = "xxx"
    var b person = *a //可以赋值
    if *a==b { //可以`比较`,但是两个必须是相同的类型,就算值是一样的类型不同无法比较
        fmt.Println(a,b) //通过函数传递默认是值拷贝

    }

    ai := &struct {
        Name string
        Age int
    }{
        Name:"ddd",
        Age:12,
    } 
    fmt.Println(ai)

    aj := person1{Name:"joe",Age:22}
    aj.Contact.Phone = "22233123"
    aj.Contact.City = "toke"
    fmt.Println(aj)

    var c person2 = person2{"dsda",1} //因为是匿名的所以只能这么初始化
    fmt.Println(c)

    ak := &student{Name:"dd",Age: 19, person: person{Name:"xxx",Age: 18}}
    fmt.Println(ak,ak.Name,ak.person.Name)

    fun :=A{}
    fun.Print()
    var i TZ = 1
    i.Print() //两种调用方法
    (*TZ).Print(&i)
}

// 方法method
// go中虽然没有class,但是依旧有method
// 通过显示说明receiver来实现与某个类型的组合
// 只能为同一个包中的类型定义方法
// Receicer可以是类型的值或者指针
// 不存在方法重载可以使用值或者指针来调用方法,编译器会自动完成转换
// 从某种意义上来说,方法是函数的语法糖,因为receiver其实就是方法所接受的第一个参数
// 如果外部结构和嵌入结构存在同名方法,则优先调用外部结构的方法
// 类型别名不会用用底层类型所附带的方法
// 方法可以调用结构中的非公开字段
func (a A) Print(){ //先不写名称,先用一个括号写接受者,在写函数名称
    fmt.Println("A") //方法可以访问结构的私有字段
}
func (b B) Print(){ //先不写名称,先用一个括号写接受者,在写函数名称,这个函数和上面的函数不属于重载
    b.Name = "sda" //实际上不会改变,因为传递的是值
    fmt.Println("B")
}
func (a TZ) Print(){ //先不写名称,先用一个括号写接受者,在写函数名称
    fmt.Println("TZ") //通过方法的绑定,甚至可以给int变量加方法,因此可以
}
