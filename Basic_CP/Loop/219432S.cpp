#include <iostream>
#include <algorithm>
using namespace std;

#define intll long long
#define endl '\n'

void solution() {

	int n, m;
	cin >> n >> m;

	// swap n, m
	if (n > m) {
		swap(n, m);
	}

	intll summ = 0;
	for(int i = n + 1; i <= m - 1; i++) {
		if (i & 1) {
			summ += i;
		}
	}

	cout << summ << endl;
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