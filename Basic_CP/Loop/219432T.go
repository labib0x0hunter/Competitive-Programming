package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scan(&n)

	// sapce + star + "*" + star
	space, star := n-1, 0
	for i := 0; i < n; i++ {
		for j := 0; j < space; j++ {
			fmt.Printf(" ")
		}
		for j := 0; j < star; j++ {
			fmt.Printf("*")
		}
		fmt.Printf("*")
		for j := 0; j < star; j++ {
			fmt.Printf("*")
		}
		fmt.Println()

		space--
		star++
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
