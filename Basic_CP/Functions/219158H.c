#include <stdio.h>
#define intll long long

#define EPS 1e-9

int floor(int a, int b) {
	return a / b;
}

int ceil(int a, int b) {
	return (a + (b - 1)) / b;
}

int round(int a, int b) {
	return (double) a / b + 0.5;
}

void solution() {

	int a, b;
	scanf("%d %d", &a, &b);

	printf("floor %d / %d = %d\n", a, b, floor(a, b));
	printf("ceil %d / %d = %d\n", a, b, ceil(a, b));
	printf("round %d / %d = %d\n", a, b, round(a, b));
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