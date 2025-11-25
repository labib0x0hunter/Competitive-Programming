#include <stdio.h>
#define intll long long

void swap(int *a, int *b) {
	int temp = a;
	a = b;
	b = temp;
}

void solution() {

	int a, b;
	scanf("%d %d", &a, &b);

	swap(&a, &b);
	printf("%d %d\n", a, b);
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