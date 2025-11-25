package main

import (
	"fmt"
)

func solution() {
	var a, b, c, d int

	fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)
	fmt.Printf("Difference = %d\n", (a*b)-(c*d))
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
