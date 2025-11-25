// https://vjudge.net/problem/Gym-100971B

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

	int n;
	cin >> n;

	vector<int> arr(n);
	for (auto &i : arr)
		cin >> i;

	vector<int> sameIndex;
	for (int i = 0; i < n; i++) {
		if (arr[i] == i + 1) {
			sameIndex.push_back(i);
		}
	}

	if (sameIndex.size() % 2 == 0) {
		cout << sameIndex.size() / 2 << endl;
		for (int i = 0; i < sameIndex.size(); i += 2) {
			cout << sameIndex[i] + 1 << " " << sameIndex[i + 1] + 1 << endl;
		}
	} else {
		cout << sameIndex.size() / 2 + 1 << endl;
		for (int i = 0; i < sameIndex.size() - 1; i += 2) {
			cout << sameIndex[i] + 1 << " " << sameIndex[i + 1] + 1 << endl;
			swap(arr[sameIndex[i]], arr[sameIndex[i + 1]]);
		}

		for (int i = 0; i < n; i++) {
			if (sameIndex.back() == i) {
				continue;
			}
			cout << sameIndex.back() + 1 << " " << i + 1 << endl;
			return;
		}
	}

}

int32_t main() {

	// Test Case
	bool TEST_CASE = !true;

	ios::sync_with_stdio(false) ; cin.tie(0) ;

	int t_c = 1, tt_c = 1;
	if (TEST_CASE) cin >> t_c;

	while (t_c--) {
		// cout << "Case " << tt_c++ << ": ";
		solution();
		// if (t_c) cout << '\n';
	}

	return 0;
}