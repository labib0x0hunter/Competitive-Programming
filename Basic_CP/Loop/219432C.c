#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	int even = 0, odd = 0, pos = 0, neg = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);

		// odd-even
		if (x % 2 == 0) {
			even++;
		} else {
			odd++;
		}

		// positive-negative
		if (x > 0) {
			pos++;
		} else if (x < 0) {
			neg++;
		}
	}

	printf("Even: %d\n", even);
	printf("Odd: %d\n", odd);
	printf("Positive: %d\n", pos);
	printf("Negative: %d\n", neg);
}

int main() {
	// char TEST_CASE = !1;
	int t = 1;
	// if (TEST_CASE == 1) {
	// 	scanf("%d", &t);
	// }

	while (t--) {
		solution();
	}
	return 0;
}