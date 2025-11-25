package main

import (
	"fmt"
)

func solution() {

	year, month := 365, 30

	var totalDay int
	fmt.Scanf("%d", &totalDay)

	fmt.Printf("%d years\n", totalDay/year)

	totalDay %= year
	fmt.Printf("%d months\n", totalDay/month)

	totalDay %= month
	fmt.Printf("%d days\n", totalDay)
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
