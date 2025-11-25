#include <stdio.h>
#define intll long long

void solution() {
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d * %d = %lld\n", a, b, 1ll * a * b);
	printf("%d - %d = %d\n", a, b, a - b);
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