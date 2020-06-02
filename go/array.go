package main

import "fmt"

func fun (arr *[2]int) bool{
    arr[1] = 2;
    arr[0] = 2;
    fmt.Println(arr)
    return true;

}
func main(){

    var arr = [...]int{1,3}
    fun(&arr)
    fmt.Println(arr)
}

