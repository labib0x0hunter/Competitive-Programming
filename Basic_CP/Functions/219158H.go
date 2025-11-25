package main

import (
	"fmt"
)

func ceil(a, b int) int {
	add := 0
	if a % b != 0 {
		add++
	}
	return (a / b) + add
}

func floor(a, b int) int {
	return a / b
}

func round(a, b int) int {
	fl := float32(floor(a, b))
	diff := float32(a) / float32(b) - fl
	add := 0
	if diff >= float32(0.5) {
		add++
	}
	return int(fl) + add
}

func solution() {

	var a, b int
	fmt.Scan(&a, &b)

	fmt.Println("floor", a, "/", b, "=", floor(a, b))
	fmt.Println("ceil", a, "/", b, "=", ceil(a, b))
	fmt.Println("round", a, "/", b, "=", round(a, b))

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
