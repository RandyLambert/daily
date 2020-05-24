package main

import (
     "fmt"
)

//声明一个USB的接口
type USB interface {
     Name() string
     Connect()
}

//声明一个PhoneConnect的结构去实现USB接口
type PhoneConnecter struct {
     name string
}

func (pc PhoneConnecter) Name() string {
     return pc.name
}

func (pc PhoneConnecter) Connect() {
     fmt.Println(pc.Name(), "已经成功连接")
}

//注意：我们所说的首字母大小写的公私有权限问题，是针对包外的，即除了该main包意外的包，而在包里不管大小写都是可以访问的
func main() {
     var a USB                   //声明a的类型是USB类型
     a = PhoneConnecter{"森森的电脑"} //成功实现USB接口
     a.Connect()
}
