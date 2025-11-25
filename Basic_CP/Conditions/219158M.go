package main

import (
	"fmt"
	"unicode"
)

func solution() {

	var c rune
	fmt.Scanf("%c", &c)

	if unicode.IsDigit(c) {
		fmt.Printf("IS DIGIT\n")
	} else {
		fmt.Printf("ALPHA\n")
		if unicode.IsLower(c) {
			fmt.Printf("IS SMALL\n")
		} else if unicode.IsUpper(c) {
			fmt.Printf("IS CAPITAL\n")
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
