package main

import (
	"fmt"
)

func solution() {

	var a, b int
	fmt.Scan(&a, &b)

	func() {
		if a < b {
			a, b = b, a
		}
		for b != 0 {
			a %= b
			if a < b {
				a, b = b, a
			}
		}
	}()

	fmt.Println(a)
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
