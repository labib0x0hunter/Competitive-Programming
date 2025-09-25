#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T> arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

vector<int> arr;

vector<int> dnc(int l, int r) {
	if (l == r) {
		return vector<int> {arr[l]};
	}
	
	int mid = l + (r - l) / 2;

	// divide
	vector<int> a = dnc(l, mid);
	vector<int> b = dnc(mid + 1, r);

	// merge
	int n = a.size(), m = b.size();
	vector<int> ans(n + m);

	int i = 0, j = 0, I = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j]) {
			ans[I++] = a[i++];
		} else {
			ans[I++] = b[j++];
		}
	}

	while (i < n) {
		ans[I++] = a[i++];
	}

	while (j < m) {
		ans[I++] = b[j++];
	}

	return ans;
}

void solution() {

	arr.resize(4);
	arr = {3, 2, 3, 1};

	auto ans = dnc(0, arr.size() - 1);

	PRINT(ans);

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