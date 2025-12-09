#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

template<typename Out> void split(const string &s, char delim, Out result) {
	stringstream ss; ss.str(s); string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

vector<string> split(const string &s, char delim) {
	vector<string> elems; split(s, delim, back_inserter(elems));
	return elems;
}

string Addition(string a, string b) {
	int n = a.size(), m = b.size();
	if (n > m) {
		swap(n, m);
		swap(a, b);
	}

	string temp = "";
	ranges::reverse(a);
	ranges::reverse(b);
	int carry = 0;
	for (int i = 0; i < n; i++) {
		int aa = a[i] - '0';
		int bb = b[i] - '0';
		temp += to_string((aa + bb + carry) % 10);
		carry = (aa + bb + carry) / 10;
	}

	for (int i = n; i < m; i++) {
		int bb = b[i] - '0';
		temp += to_string((bb + carry) % 10);
		carry = (bb + carry) / 10;
	}
	if (carry) {
		temp += to_string(carry);
	}
	ranges::reverse(temp);
	return temp;
}

void solution() {

	string s;
	cin >> s;

	vector<array<intll, 2>> range;
	for (auto rng : split(s, ',')) {
		auto tmp = split(rng, '-');
		string l = tmp[0], r = tmp[1];
		range.push_back(array<intll, 2> {stoll(l), stoll(r)});
	}

	// for (auto [x, y] : range) {
	// 	cout << x << " " << y << endl;
	// }

	string ans = "0";
	for (int i = 1; i <= 1e7; i++) {
		intll tmp = stoll(to_string(i) + to_string(i));
		for (auto [x, y] : range) {
			if (x <= tmp && tmp <= y) {
				ans = Addition(ans, to_string(tmp));
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