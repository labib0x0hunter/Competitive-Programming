#include <iostream>
#include <iomanip>
using namespace std;

#define intll long long
#define endl '\n'

void solution() {

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	a %= 100;
	b %= 100;
	c %= 100;
	d %= 100;
	int last_two_digit = (a * b * c * d) % 100;

	cout << setw(2) << setfill('0') << last_two_digit << endl;
}

int32_t main() {

	// Test Case
	bool TEST_CASE = !true;

	ios::sync_with_stdio(false) ; cin.tie(0) ;

	int t_c = 1, tt_c = 1;
	if (TEST_CASE) cin >> t_c;

	// cin.ignore(); // In Case getline(cin, s)

	while (t_c--) {
		// cout << "Case " << tt_c++ << ": ";
		solution();
		// if (t_c) cout << '\n';
	}

	return 0;
}