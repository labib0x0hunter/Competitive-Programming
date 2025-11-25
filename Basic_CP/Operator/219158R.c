#include <stdio.h>
#define intll long long

void solution() {

	int year = 365, month = 30;

	int total_day;
	scanf("%d", &total_day);

	printf("%d years\n", total_day / year);

	total_day %= year;
	printf("%d months\n", total_day / month);

	total_day %= month;
	printf("%d days\n", total_day);

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