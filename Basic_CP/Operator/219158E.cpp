#include <iostream>
#include <iomanip>
using namespace std;

#define intll long long
#define endl '\n'

void solution() {

	double PI = 3.141592653;
	double r;

	cin >> r;

	cout << fixed << setprecision(9) << PI * r * r << endl;

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