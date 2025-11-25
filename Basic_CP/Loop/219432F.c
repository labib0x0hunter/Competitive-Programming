#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 12; i++) {
		printf("%d * %d = %d\n", n, i, i * n);
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