#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

void solution() {

	int ans = 0;

	string s;
	while (cin >> s) {
		int maxx = 0;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				string tmp = {s[i], s[j]};
				maxx = max(maxx, stoi(tmp));
			}
		}

		ans += maxx;
	}

	cout << ans << endl;
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