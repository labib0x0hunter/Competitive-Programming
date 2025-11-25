#include <iostream>
using namespace std;

#define intll long long
#define endl '\n'

void solution() {

	int n;
	cin >> n;

	int even = 0, odd = 0, pos = 0, neg = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		// odd-even
		even += (x % 2 == 0);
		odd += (x % 2 == 1) || (x % 2 == -1);

		// positive-negative
		pos += (x > 0);
		neg += (x < 0);
	}

	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;
	cout << "Positive: " << pos << endl;
	cout << "Negative: " << neg << endl;
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