#include <stdio.h>
#define intll long long

char is_prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void solution() {

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		if (is_prime(i)) {
			printf("%d ", i);
		}
	}

}

int main() {
	char TEST_CASE = 0;
	int t = 1;
	if (TEST_CASE == 1) {
		scanf("%d", &t);
	}

	while (t--) {
		solution();
	}
	return 0;
}