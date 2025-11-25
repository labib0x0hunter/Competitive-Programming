#include <iostream>
#include <cmath>
using namespace std;

#define intll long long
#define endl '\n'

void solution() {

	int a, b;
	cin >> a >> b;

	cout << "floor " << a << " / " << b << " = " << floor((double) a / b) << endl;
	cout << "ceil " << a << " / " << b << " = " << ceil((double) a / b) << endl;
	cout << "round " << a << " / " << b << " = " << round((double) a / b) << endl;
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