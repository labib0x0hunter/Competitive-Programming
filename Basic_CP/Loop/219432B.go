package main

import (
	"fmt"
)

func solution() {

	var n int
	fmt.Scanf("%d", &n)

	evenFound := false
	for i := 1; i <= n; i++ {
		if i%2 == 0 {
			evenFound = true
			fmt.Println(i)
		}
	}

	if evenFound == false {
		fmt.Println(-1)
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
