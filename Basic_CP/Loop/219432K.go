package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		if n % i != 0 {
			continue
		}

		fmt.Println(i)
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
