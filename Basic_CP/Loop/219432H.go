package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scan(&n)

	isPrime := true
	for i := 2; i < n; i++ {
		if n%i == 0 {
			isPrime = false
			break
		}
	}

	if isPrime {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
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
