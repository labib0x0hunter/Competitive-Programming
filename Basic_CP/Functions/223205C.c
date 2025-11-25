#include <stdio.h>
#define intll long long

char is_odd(int n) {
	if (n % 2 == 1) return 1;
	return 0;
}

char is_palindrome(int n) {
	int digits[32];
	int idx = 0;
	while (n > 0) {
		digits[idx++] = n % 2;
		n /= 2;
	}
	for (int i = 0; i < idx / 2; i++) {
		if (digits[i] != digits[idx - i - 1]) {
			return 0;
		}
	}
	return 1;
}

void solution() {

	int n;
	scanf("%d", &n);

	if (is_odd(n) == 0 || is_palindrome(n) == 0) {
		printf("NO\n");
		return;
	}

	printf("YES\n");

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