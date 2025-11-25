#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	char even_found = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			even_found = 1;
			printf("%d\n", i);
		}
	}

	if (even_found == 0) {
		printf("-1\n");
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