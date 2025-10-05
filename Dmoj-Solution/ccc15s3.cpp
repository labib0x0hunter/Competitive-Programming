// https://dmoj.ca/problem/ccc15s3

#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

struct fast_Bitset {
#define uintll unsigned long long

	static constexpr unsigned B = 64;
	int N, lg;
	vector<vector<uintll>> seg;
	fast_Bitset() {}
	fast_Bitset(int _n) : N(_n) {
		do {
			seg.push_back(vector<uintll>((_n + B - 1) / B));
			_n = (_n + B - 1) / B;
		} while (_n > 1);
		lg = int(seg.size());
	}

	int bsr(uintll x) {
		return 63 - __builtin_clzll(x);
	}
	int bsf(uintll x) {
		return __builtin_ctzll(x);
	}

	bool operator[](int i) const {
		return (seg[0][i / B] >> (i % B) & 1) != 0;
	}

	void insert(int i) {
		for (int h = 0; h < lg; h++) {
			seg[h][i / B] |= 1ULL << (i % B);
			i /= B;
		}
	}

	void erase(int i) {
		for (int h = 0; h < lg; h++) {
			seg[h][i / B] &= ~(1ULL << (i % B));
			if (seg[h][i / B]) break;
			i /= B;
		}
	}

	int next(int i) {
		if (i < 0) i = 0;
		if (i >= N) return N + 1;
		for (int h = 0; h < lg; h++) {
			if (i / B == seg[h].size()) break;
			uintll d = seg[h][i / B] >> (i % B);
			if (!d) {
				i = i / B + 1;
				continue;
			}

			// find
			i += bsf(d);
			for (int g = h - 1; g >= 0; g--) {
				i *= B;
				i += bsf(seg[g][i / B]);
			}
			return i;
		}
		return N + 1;
	}

	int previous(int i) {
		if (i < 0) return -1;
		if (i >= N) i = N - 1;
		for (int h = 0; h < lg; h++) {
			if (i == -1) break;
			uintll d = seg[h][i / B] << (63 - i % 64);
			if (!d) {
				i = i / B - 1;
				continue;
			}

			// find
			i += bsr(d) - (B - 1);
			for (int g = h - 1; g >= 0; g--) {
				i *= B;
				i += bsr(seg[g][i / B]);
			}
			return i;
		}
		return -1;
	}

	// [l, r)
	template <typename F>
	void enumerate(int l, int r, F f) {
		int x = l - 1;
		while (1) {
			x = next(x + 1);
			if (x >= r)
				break;
			f(x);
		}
	}

	void debugg() {
		string s;
		for (int i = 0; i < N; ++i)
			s += ((*this)[i] ? '1' : '0');
		cout << s << endl;
	}
};
// Be Careful
// prev(i) -> -1
// next(i) -> n + 1

void solution() {

	int g, p;
	cin >> g >> p;

	vector<int> arr(p);
	for (int &i : arr) {
		cin >> i;
	}

	fast_Bitset st(g + 1);
	for (int i = 0; i <= g; i++) {
		st.insert(i);
	}

	int ans = 0;
	for (int a : arr) {
		int prev = st.previous(a);
		if (prev == 0) {
			break;
		}
		st.erase(prev);
		ans++;
	}

	cout << ans << endl;
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