package main

import (
	"fmt"
)

func solution() {
	var a int
	var b int64
	var c byte
	var d float32
	var e float64

	fmt.Scanf("%d %d %c %f %f", &a, &b, &c, &d, &e)
	fmt.Printf("%d\n", a)
	fmt.Printf("%d\n", b)
	fmt.Printf("%c\n", c)
	fmt.Printf("%0.2f\n", d)
	fmt.Printf("%0.1f\n", e)
}

func main() {
	TEST_CASE := !true
	t := 1
	if TEST_CASE {
		fmt.Scanf("%d", &t)
	}

	for t != 0 {
		solution()
		t--
	}
}