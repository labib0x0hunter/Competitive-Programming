#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	int space = n - 1, star = 0;
	// sapce + star + "*" + star
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < space; j++) {
			printf(" ");
		}
		for (int j = 0; j < star; j++) {
			printf("*");
		}
		printf("*");
		for (int j = 0; j < star; j++) {
			printf("*");
		}
		printf("\n");

		space--;
		star++;
	}
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