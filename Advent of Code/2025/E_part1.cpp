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

	vector<array<intll, 2>> rangeOfFreshness;
	vector<intll> ingridiant;
	string s;

	while (cin >> s && s.size() != 0) {
		if (find(s.begin(), s.end(), '-') != s.end()) {
			int splitIdx = find(s.begin(), s.end(), '-') - s.begin();
			// cout << splitIdx << " " << s.substr(0, splitIdx) << " " << s.substr(splitIdx + 1, s.size()) << endl;
			array<intll, 2> temp;
			temp[0] = stoll(s.substr(0, splitIdx));
			temp[1] = stoll(s.substr(splitIdx + 1, s.size()));
			rangeOfFreshness.push_back(temp);
		} else {
			ingridiant.push_back(stoll(s));
		}
	}

	// cout << rangeOfFreshness.front()[0] << " " << rangeOfFreshness.front()[1] << endl;
	// cout << ingridiant.front() << endl;

	int ans = 0;
	for (auto ing : ingridiant) {
		for (auto [L, R] : rangeOfFreshness) {
			if (L <= ing && ing <= R) {
				ans++;
				break;
			}
		}
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