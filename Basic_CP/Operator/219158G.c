#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	printf("%lld\n", 1ll * n * (n + 1) / 2);

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