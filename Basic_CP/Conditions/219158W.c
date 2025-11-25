#include <stdio.h>
#define intll long long

void solution() {

	int a, b, c;
	char op;

	scanf("%d %c %d = %d", &a, &op, &b, &c);

	if (op == '+') {
		if (a + b == c) {
			printf("Yes\n");
		} else {
			printf("%d\n", a + b);
		}
	} else if (op == '-') {
		if (a - b == c) {
			printf("Yes\n");
		} else {
			printf("%d\n", a - b);
		}
	} else {
		if (a * b == c) {
			printf("Yes\n");
		} else {
			printf("%d\n", a * b);
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