package main

import (
	"fmt"
)

func solution() {

	var n, m int
	fmt.Scan(&n, &m)

	// swap
	if n > m {
		n, m = m, n
	}

	summ := 0
	for i := n + 1; i <= m - 1; i++ {
		if i % 2 == 1 {
			summ += i
		}
	}

	fmt.Println(summ)
}

func main() {
	TEST_CASE := true
	t := 1
	if TEST_CASE {
		fmt.Scanf("%d", &t)
	}

	for t != 0 {
		solution()
		t--
	}
}
