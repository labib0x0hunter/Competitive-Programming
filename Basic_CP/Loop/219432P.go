package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		for j := 1; j <= n - i + 1; j++ {
			fmt.Printf("*")
		}
		fmt.Println()
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
