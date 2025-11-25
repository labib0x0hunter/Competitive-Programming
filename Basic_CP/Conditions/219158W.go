package main

import (
	"fmt"
)

func solution() {

	var a, b, c int
	var op byte
	fmt.Scanf("%d %c %d = %d", &a, &op, &b, &c)

	if op == '+' {
		if a+b == c {
			fmt.Printf("Yes\n")
		} else {
			fmt.Printf("%d\n", a+b)
		}
	} else if op == '-' {
		if a-b == c {
			fmt.Printf("Yes\n")
		} else {
			fmt.Printf("%d\n", a-b)
		}
	} else {
		if a*b == c {
			fmt.Printf("Yes\n")
		} else {
			fmt.Printf("%d\n", a*b)
		}
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
