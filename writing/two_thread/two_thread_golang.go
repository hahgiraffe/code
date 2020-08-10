/*
 * @Author: haha_giraffe
 * @Date: 2020-08-05 17:13:13
 * @Description: 
 */
package main

import (
	"time"
	"fmt"
)
func main(){
	ch := make(chan struct{})
	ch2 := make(chan struct{})
	go func(){
		for{
			fmt.Println(1)
			ch <- struct{}{}
			time.Sleep(1 / 10 * time.Second)
			<-ch2
		}
	}()

	go func(){
		for{
			<-ch
			fmt.Println(2)
			ch2<- struct{}{}
			time.Sleep(1 / 10 *time.Second)
		}
	}()

	time.Sleep(1 * time.Second)
}