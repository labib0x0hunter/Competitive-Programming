#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			printf("%d\n", i);
		}
	}
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