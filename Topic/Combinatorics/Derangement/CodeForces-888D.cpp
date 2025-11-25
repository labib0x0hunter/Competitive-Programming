// https://vjudge.net/problem/CodeForces-888D

#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

vector<int> demnt;
void derangement(int n) {
	demnt.resize(n + 1);
	demnt[0] = 1;
	demnt[1] = 0;
	for (int i = 2; i <= n; i++)
		demnt[i] = (i - 1) * (demnt[i - 1] + demnt[i - 2]);
}


void solution() {

	int n, m;
	cin >> n >> m;

	derangement(m + 10);

	auto NCR = [](int n, int r) {
		intll ans = 1;
		for (int i = n; i > n - r; i--)
			ans *= i;
		for (int i = 1; i <= r; i++)
			ans /= i;
		return ans;
	};

	intll ans = 0;
	for (int i = 0; i <= m; i++) {
		ans += 1ll * NCR(n, i) * demnt[i];
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