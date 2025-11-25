package main

import (
	"fmt"
)

func solution() {
	var r float64
	PI := 3.141592653

	fmt.Scanf("%f", &r)
	fmt.Printf("%0.9f\n", PI*r*r)
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
