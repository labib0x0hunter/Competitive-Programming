package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scan(&n)

	for i := 1; i <= 12; i++ {
		fmt.Println(n, "*", i, "=", i*n)
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
