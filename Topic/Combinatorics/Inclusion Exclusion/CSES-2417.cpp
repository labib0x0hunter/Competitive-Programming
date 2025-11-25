// https://vjudge.net/problem/CSES-2417

#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

const int N = int(1e6);

void solution() {

	int n;
	cin >> n;

	vector<int> freq(N + 10);
	vector<int> arr(n);
	for (auto &i : arr)
		cin >> i, freq[i]++;

	vector<intll> gcdd(N + 10);
	for (int i = N; i >= 1; i--) {
		int pairr = 0;
		for (int j = i; j <= N; j += i) pairr += freq[j];
		gcdd[i] = 1ll * pairr * (pairr - 1) / 2;
		for (int j = i + i; j <= N; j += i) gcdd[i] -= gcdd[j];
	}

	cout << gcdd[1] << endl;
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