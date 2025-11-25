package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scanf("%d", &n)

	even, odd, pos, neg := 0, 0, 0, 0
	for i := 1; i <= n; i++ {
		var x int
		fmt.Scan(&x)

		// odd-even
		if x%2 == 0 {
			even++
		} else {
			odd++
		}

		// positive-negative
		if x > 0 {
			pos++
		} else if x < 0 {
			neg++
		}
	}

	fmt.Printf("Even: %d\n", even)
	fmt.Printf("Odd: %d\n", odd)
	fmt.Printf("Positive: %d\n", pos)
	fmt.Printf("Negative: %d\n", neg)
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
