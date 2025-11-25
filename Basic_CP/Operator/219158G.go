package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scanf("%d", &n)

	fmt.Printf("%d\n", n*(n+1)/2)
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
