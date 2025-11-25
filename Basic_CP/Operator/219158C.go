package main

import (
	"fmt"
)

func solution() {
	var a, b int

	fmt.Scanf("%d %d", &a, &b)
	fmt.Printf("%d + %d = %d\n", a, b, a+b)
	fmt.Printf("%d * %d = %d\n", a, b, a*b)
	fmt.Printf("%d - %d = %d\n", a, b, a-b)
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
