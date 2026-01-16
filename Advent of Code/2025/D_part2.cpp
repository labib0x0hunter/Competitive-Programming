#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

// first 4 are D, U, L, R
// last 4 are diagonal
vector<int> dx{1, -1, 0, 0, -1, -1, 1, 1};
vector<int> dy{0, 0, -1, 1, -1, 1, -1, 1};

void solution() {

	vector<string> grid, temp;
	string s;
	while (cin >> s) {
		grid.push_back(s);
	}

	int n = grid.size(), m = grid.front().size();

	auto valid = [&](int i, int j) -> bool {
		if (i >= 0 && j >= 0 && i < n && j < m) {
			return (grid[i][j] == '@');
		}
		return false;
	};

	int ans = 0;
	auto removeRoll = [&]() -> bool {
		temp = grid;
		bool removed = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int I = i, J = j;
				if (grid[I][J] == '.') continue;
				// check 8-diagonal
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					if (valid(I + dx[k], J + dy[k])) {
						cnt += (grid[I + dx[k]][J + dy[k]] == '@');
					}
				}
				ans += (cnt < 4);
				if (cnt < 4) {
					temp[I][J] = '.';
					removed = true;
				}
			}
		}
		grid = temp;
		return removed;
	};

	while (removeRoll()) {}

	cout << ans << endl;

	// // debug
	// for (auto x : temp) {
	// 	cout << x << endl;
	// }

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