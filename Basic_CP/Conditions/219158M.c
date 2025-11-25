#include <stdio.h>
#define intll long long

void solution() {

	char c;
	scanf("%c", &c);

	if (c >= '0' && c <= '9') {
		printf("IS DIGIT\n");
	} else {
		printf("ALPHA\n");
		if (c >= 'a' && c <= 'z') {
			printf("IS SMALL\n");
		} else if (c >= 'A' && c <= 'Z') {
			printf("IS CAPITAL\n");
		}
	}
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