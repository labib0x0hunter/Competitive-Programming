package main

import (
	"fmt"
)

func solution() {

	var a, b int
	fmt.Scanf("%d %d", &a, &b)

	if a >= b {
		fmt.Printf("Yes\n")
	} else {
		fmt.Printf("No\n")
	}
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
