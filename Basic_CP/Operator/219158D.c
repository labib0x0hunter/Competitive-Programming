#include <stdio.h>
#define intll long long

void solution() {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("Difference = %lld\n", (1ll * a * b) - (1ll * c * d));

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