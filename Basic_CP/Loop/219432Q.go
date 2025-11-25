package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scan(&n)

	if n == 0 {
		fmt.Println(n)
		return
	}

	for n > 0 {
		fmt.Printf("%d ", n % 10)
		n /= 10
	}

	fmt.Println()
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
