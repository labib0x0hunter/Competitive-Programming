#include <stdio.h>
#define intll long long

void solution() {

	int a, b;
	scanf("%d %d", &a, &b);

	if (a % b == 0 || b % a == 0) {
		printf("Multiples\n");
	} else {
		printf("No Multiples\n");
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