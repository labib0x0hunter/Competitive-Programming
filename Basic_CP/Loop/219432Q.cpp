#include <iostream>
using namespace std;

#define intll long long
#define endl '\n'

void solution() {

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0 << endl;
		return;
	}

	while (n) {
		cout << n % 10 << " ";
		n /= 10;
	}

	cout << endl;
}

int32_t main() {

	// Test Case
	bool TEST_CASE = true;

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