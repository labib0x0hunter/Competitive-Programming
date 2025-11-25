package main

import (
	"fmt"
)

func solution() {

	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)

	var maxx, minn int
	if a >= b && a >= c {
		maxx = a
	} else if b >= a && b >= c {
		maxx = b
	} else {
		maxx = c
	}

	if a <= b && a <= c {
		minn = a
	} else if b <= a && b <= c {
		minn = b
	} else {
		minn = c
	}

	fmt.Printf("%d %d\n", minn, maxx)
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
