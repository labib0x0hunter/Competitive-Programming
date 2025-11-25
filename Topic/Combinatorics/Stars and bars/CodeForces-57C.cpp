// https://vjudge.net/problem/CodeForces-57C

#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

template <intll mod>
struct modular {
	intll value;
	modular(intll x = 0) {
		value = x % mod;
		if (value < 0) value += mod;
	}
	modular& operator+=(const modular& other) {
		if ((value += other.value) >= mod) value -= mod;
		return *this;
	}
	modular& operator-=(const modular& other) {
		if ((value -= other.value) < 0) value += mod;
		return *this;
	}
	modular& operator*=(const modular& other) {
		value = value * other.value % mod;
		return *this;
	}
	modular& operator/=(const modular& other) {
		intll a = 0, b = 1, c = other.value, m = mod;
		while (c != 0) {
			intll t = m / c;
			m -= t * c;
			swap(c, m);
			a -= t * b;
			swap(a, b);
		}
		a %= mod;
		if (a < 0) a += mod;
		value = value * a % mod;
		return *this;
	}
	friend modular operator+(const modular& lhs, const modular& rhs) { return modular(lhs) += rhs; }
	friend modular operator-(const modular& lhs, const modular& rhs) { return modular(lhs) -= rhs; }
	friend modular operator*(const modular& lhs, const modular& rhs) { return modular(lhs) *= rhs; }
	friend modular operator/(const modular& lhs, const modular& rhs) { return modular(lhs) /= rhs; }
	modular& operator++() { return *this += 1; }
	modular& operator--() { return *this -= 1; }
	modular operator++(int) {
		modular res(*this);
		*this += 1;
		return res;
	}
	modular operator--(int) {
		modular res(*this);
		*this -= 1;
		return res;
	}
	modular operator-() const { return modular(-value); }
	bool operator==(const modular& rhs) const { return value == rhs.value; }
	bool operator!=(const modular& rhs) const { return value != rhs.value; }
	bool operator<(const modular& rhs) const { return value < rhs.value; }
};
template <intll mod>
string to_string(const modular<mod>& x) {
	return to_string(x.value);
}
template <intll mod>
intll to_int(const modular<mod>& x) {
	return x.value;
}
template <intll mod>
ostream& operator<<(ostream& stream, const modular<mod>& x) {
	return stream << x.value;
}
template <intll mod>
istream& operator>>(istream& stream, modular<mod>& x) {
	stream >> x.value;
	x.value %= mod;
	if (x.value < 0) x.value += mod;
	return stream;
}

constexpr intll mod1 = int(1e9 + 7);
constexpr intll mod2 = int(998244353);
using mint1e97 = modular<mod1>;
using mint9982 = modular<mod2>;

using mint = mint1e97;

// (x^y) % mod
mint expo(intll x, intll y) {
	mint ans = mint(1);
	mint xx = mint(x);
	if (xx == 0) return mint(0);
	while (y > 0) {
		if (y & 1) ans *= xx;
		y = y >> 1;
		xx *= xx;
	}
	return ans;
}

mint mod_inverse(int x) { return mint(1) / mint(x); }
mint mod_inverse(mint x) { return mint(1) / mint(x); }

vector<mint> fact, cat, inv_fact, demnt;
void factorial(int n) {
	fact.resize(n + 1);
	fact[0] = fact[1] = mint(1);
	for (int i = 2; i <= n; i++)
		fact[i] = mint(i) * fact[i - 1];
}
void catalan(int n) {
	cat.resize(n + 1);
	cat[0] = mint(1);
	for (int i = 0; i < n; i++)
		cat[i + 1] = mint(4 * i + 2) * cat[i] / mint(i + 2);
}
void inverse_fact(int n) {
	inv_fact.resize(n + 1);
	inv_fact[0] = inv_fact[1] = mod_inverse(1);
	for (int i = 2; i <= n; i++)
		inv_fact[i] = inv_fact[i - 1] * mod_inverse(i);
}
mint nCr(int n, int r) {
	assert(!fact.empty());
	assert(!inv_fact.empty());
	if (n < r) return mint(0);
	return fact[n] * inv_fact[r] * inv_fact[n - r];
}

void derangement(int n) {
	demnt.resize(n + 1);
	demnt[0] = mint(1);
	demnt[1] = mint(0);
	for (int i = 2; i <= n; i++)
		demnt[i] = mint(i - 1) * (demnt[i - 1] + demnt[i - 2]);
}

mint StartAndBars(int n, int k) {
	return nCr(n + k - 1, k - 1);
}

void solution() {

	int n, k;
	cin >> n;

	k = n;

	cout << mint(StartAndBars(n, k) + StartAndBars(n, k) - n) << endl;

}

int32_t main() {

	factorial(int(2e6) + 10);
	inverse_fact(int(2e6) + 10);

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