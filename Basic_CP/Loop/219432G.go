package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scan(&n)

	fact := 1
	for i := 1; i <= n; i++ {
		fact *= i
	}

	fmt.Println(fact)
}

func main() {
	TEST_CASE := true
	t := 1
	if TEST_CASE {
		fmt.Scanf("%d", &t)
	}

	for t != 0 {
		solution()
		t--
	}
}
