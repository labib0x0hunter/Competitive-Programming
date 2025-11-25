#include <stdio.h>
#define intll long long

#define PI 3.141592653

void solution() {
	float r;

	scanf("%f", &r);
	printf("%0.9f\n", PI * r * r);

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