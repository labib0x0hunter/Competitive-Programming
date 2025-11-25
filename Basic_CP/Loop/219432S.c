#include <stdio.h>
#define intll long long

void solution() {

	int n, m;
	scanf("%d %d", &n, &m);

	// swap n, m
	if (n > m) {
		int temp = n;
		n = m;
		m = temp;
	}

	intll summ = 0;
	for(int i = n + 1; i <= m - 1; i++) {
		if (i % 2 == 1) {
			summ += i;
		}
	}

	printf("%lld\n", summ);
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