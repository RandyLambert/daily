package main

import (
	"fmt"
	"sync"
	"testing"
	"time"
)

func TestCounter(t *testing.T){
	counter := 0
	for i:= 0;i < 5000;i++{
		go func() {
			counter++
		} ()
	}
	time.Sleep(1 * time.Second)
	fmt.Print(counter)
	counter = 0
	mutex := sync.Mutex{}
	for i:= 0;i < 5000;i++{
		go func() {
			defer mutex.Unlock()
			mutex.Lock()
			counter++
		} ()
	}
	time.Sleep(1 * time.Second)
	fmt.Print(counter)
}

func TestWaitGroup(t *testing.T){

	counter := 0
	mutex := sync.Mutex{}
	var wait sync.WaitGroup // 类似与cdown_lunch
	wait.Add(5000)
	for i:= 0;i < 5000;i++{
		go func() {
			defer mutex.Unlock()
			mutex.Lock()
			counter++
			wait.Done()
		} ()
	}
	wait.Wait()
	fmt.Print(counter)
}
func service() string {
	time.Sleep(time.Millisecond * 500)
	return "down"
}

func otherTask() {
	fmt.Println("working on something else")
	time.Sleep(time.Millisecond * 100)
	fmt.Println("Task is Done.")
}

func TestService(t *testing.T) {
	fmt.Println(service())
	otherTask()
}

func AsyncService() chan string {
	retCh := make(chan string,1)
	go func() {
		ret := service()
		fmt.Println("returned result.")
		retCh <- ret // 调用协程阻塞了
		fmt.Println("service exited.")
	}()
	return retCh
}

func TestAsynService(t *testing.T) {
	retCh := AsyncService()
	otherTask()
	fmt.Println("dada")
	fmt.Println(<-retCh)
	time.Sleep(time.Second * 1)
}

func TestSelect(t *testing.T) {
	select {
	case ret := <-AsyncService():
		t.Log(ret)
	case  <-time.After(1000*time.Millisecond): // 正常
	//case  <-time.After(100*time.Millisecond): // 超时
		t.Error("timeout")
	}
}

func receiver(ch chan int,wg *sync.WaitGroup) {
	go func(){
		for i:= 0;i < 10;i++{
			data := <-ch
			fmt.Println(data)
		}
		wg.Done()
	}()
}

//func send()