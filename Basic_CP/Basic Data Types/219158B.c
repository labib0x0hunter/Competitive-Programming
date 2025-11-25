#include <stdio.h>
#define intll long long

void solution() {
	int a;
	intll b;
	char c;
	float d;
	double e;

	scanf("%d %lld", &a, &b);
	scanf(" %c", &c);
	scanf("%f %lf", &d, &e);	// Here CF is failing to read %lf, why ?

	printf("%d\n", a);
	printf("%lld\n", b);
	printf("%c\n", c);
	printf("%0.2f\n", d);
	printf("%0.1lf\n", e);
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