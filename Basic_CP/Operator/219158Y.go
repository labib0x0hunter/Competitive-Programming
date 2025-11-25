package main

import (
	"fmt"
)

func solution() {

	var a, b, c, d int
	fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)

	a %= 100
	b %= 100
	c %= 100
	d %= 100
	lastTwoDigit := (a * b * c * d) % 100

	fmt.Printf("%02d\n", lastTwoDigit)
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
