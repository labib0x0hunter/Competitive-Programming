#include <stdio.h>
#define intll long long

void solution() {

	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	a %= 100;
	b %= 100;
	c %= 100;
	d %= 100;
	int last_two_digit = (a * b * c * d) % 100;

	printf("%02d\n", last_two_digit);

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