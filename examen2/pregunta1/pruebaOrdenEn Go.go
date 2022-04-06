package main

import "fmt"

var a int = 1

func f(b int) int {
	a += b
	return a;
}

func g(b int) int{
	a*=b
	return a
}

func main() {

	fmt.Println( f(a)+g(a) )
}
