#include <stdio.h>
#define intll long long

void solution() {

	int n;
	scanf("%d", &n);

	// sapce + star + "*" + star
	int space = n - 1, star = 0;

	// First half
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

	// Second half
	space = 0, star = n - 1;
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

		space++;
		star--;
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