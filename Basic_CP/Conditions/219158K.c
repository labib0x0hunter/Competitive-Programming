#include <stdio.h>
#define intll long long

void solution() {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int maxx, minn;
	if(a >= b && a >= c) {
		maxx = a;
	} else if (b >= a && b >= c) {
		maxx = b;
	} else {
		maxx = c;
	}

	if(a <= b && a <= c) {
		minn = a;
	} else if (b <= a && b <= c) {
		minn = b;
	} else {
		minn = c;
	}

	printf("%d %d\n", minn, maxx);
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