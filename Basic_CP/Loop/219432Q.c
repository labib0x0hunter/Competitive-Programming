#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	if (n == 0) {
		printf("0\n");
		return;
	}

	while (n) {
		printf("%d ", n % 10);
		n /= 10;
	}
	printf("\n");
}

int main() {
	char TEST_CASE = 1;
	int t = 1;
	if (TEST_CASE == 1) {
		scanf("%d", &t);
	}

	while (t--) {
		solution();
	}
	return 0;
}