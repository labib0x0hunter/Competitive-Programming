#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

string Multiplication(string s1, string s2) {
	int n1 = s1.size(), n2 = s2.size();
	if (n1 == 0 || n2 == 0)
		return "0";

	int nn = 1, mm = 1;
	if (s1[0] == '-')
		nn = -1;
	if (s2[0] == '-')
		mm = -1;

	int isNeg = nn * mm;

	vector<int> result(n1 + n2, 0);

	int i1 = 0;
	int i2 = 0;

	for (int i = n1 - 1; i >= 0; i--) {
		if (s1[i] == '-')
			continue;
		int carry = 0;
		int n1 = s1[i] - '0';
		i2 = 0;

		for (int j = n2 - 1; j >= 0; j--) {
			if (s2[j] == '-')
				continue;
			int n2 = s2[j] - '0';
			int sum = n1 * n2 + result[i1 + i2] + carry;
			carry = sum / 10;
			result[i1 + i2] = sum % 10;
			i2++;
		}

		if (carry > 0)
			result[i1 + i2] += carry;

		i1++;
	}

	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	if (i == -1)
		return "0";

	string s = "";

	while (i >= 0)
		s += to_string(result[i--]);

	if (isNeg == -1)
		s = "-" + s;

	return s;
}

string Addition(string &s1, string &s2) {
	if (s1.empty()) return s2;
	if (s2.empty()) return s1;

	string result = "";

	int i = s1.length() - 1;
	int j = s2.length() - 1;

	int carry = 0;

	while (i >= 0 || j >= 0 || carry > 0) {

		int digit1 = (i >= 0) ? s1[i] - '0' : 0;
		int digit2 = (j >= 0) ? s2[j] - '0' : 0;

		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		sum %= 10;

		result.push_back(('0' + sum));

		i--;
		j--;
	}

	while (result.size() > 1 && result[result.size() - 1] == '0') {
		result.pop_back();
	}

	reverse(result.begin(), result.end());

	return result;
}

void solution() {

	vector<string> data;
	string s;

	while (cin >> s) {
		data.push_back(s);
	}

	int operand = ranges::count(data, "*") + ranges::count(data, "+");
	vector<string> opData = vector<string>(data.end() - operand, data.end());
	data.resize(data.size() - operand);

	vector<string> ans(operand);

	// set default value, * -> 1, + -> 0
	for (int i = 0; i < operand; i++) {
		ans[i] = (opData[i] == "*" ? "1" : "0");
	}

	// PRINT(data);
	// PRINT(opData);
	// PRINT(ans);

	for (int i = 0; i < data.size(); i += operand) {
		for (int j = 0; j < operand; j++) {
			ans[j] = (opData[j] == "*" ? Multiplication(ans[j], data[i + j]) : Addition(ans[j], data[i + j]));
		}
	}

	string res = "0";
	for (auto a : ans) {
		res = Addition(res, a);
	}

	cout << res << endl;
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