#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

int call_no = 0;

int dnc(int l, int r) {
	++call_no;
	int temp = call_no;
	cout << "Call: " << call_no << " " << "dividing (range): " << l << " " << r << endl;

	if (l == r) return call_no;
	int mid = l + (r - l) / 2;

	// divide

	int left = dnc(l, mid);
	int right = dnc(mid + 1, r);

	// conquer

	cout << "Call: " << temp << " " << "merging (range): " << l << " " << r << " Call: " << left << " " << right << endl;
	return temp;
}

void solution() {

	dnc(1, 10);

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