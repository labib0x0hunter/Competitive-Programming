#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	char is_prime = 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			is_prime = 0;
			break;
		}
	}

	if (is_prime == 1) {
		printf("YES\n");
	} else {
		printf("NO\n");
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