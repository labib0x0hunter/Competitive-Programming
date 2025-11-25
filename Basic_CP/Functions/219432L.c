#include <stdio.h>
#define intll long long

void swap(int *a, int *b) {
	int temp = a;
	a = b;
	b = temp;
}

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	while (b != 0) {
		a %= b;
		if (a < b) {
			swap(a, b);
		}
	}
	return a;
}

void solution() {

	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", gcd(a, b));
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