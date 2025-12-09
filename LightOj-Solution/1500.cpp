// https://lightoj.com/problem/beautiful-blocks-again
#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

template<typename T = int>
vector<int> argsort(const vector<T> &arr) {
	int n = int(arr.size());
	vector<int> ids(n);
	iota(ids.begin(), ids.end(), 0);
	sort(ids.begin(), ids.end(), [&](int i, int j) {
		return (arr[i] == arr[j] ? i < j : arr[i] > arr[j]);
	});
	return ids;
}

template<typename T = int>
vector<int> rearrange(vector<T> &arr, vector<T>& idx) {
	vector<int> brr(int(arr.size()));
	for (int i = 0; i < int(arr.size()); i++)
		brr[i] = arr[idx[i]];
	return move(brr);
}

void solution() {

	int n, m;
	cin >> n >> m;

	vector<array<int, 2>> arr(n * m);
	for (int i = 0; i < n * m; i++) {
		cin >> arr[i][0];
		arr[i][1] = i;
	}

	// arg index = sort + reverse
	auto argIdx = argsort(arr);

	// max sum of n + m - 1
	argIdx.resize(n + m - 1);
	sort(argIdx.begin(), argIdx.end());


	// first contribution idx
	array<int, 2> contIdx = {n - 1, m - 1}, nonContIdx = {n - 1, 0};
	// contribution col name
	int contCol = m, nonContCol = 1;
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<int> ans(n * m);

	auto moveContributionIdx = [&](int idx) {
		// first block fell down
		if (vis[contIdx[0]][contIdx[1]] == 0) {
			vis[contIdx[0]][contIdx[1]] = 1;
			ans[idx] = contCol;
			return;
		}

		// Left 0, -1, if left block is valid and not used, use that one
		if (contIdx[1] - 1 >= 0 && vis[contIdx[0]][contIdx[1] - 1] == 0) {
			contIdx[1]--;
			contCol--;	// left to move
			vis[contIdx[0]][contIdx[1]] = 1;
			ans[idx] = contCol;
		} else if (contIdx[0] - 1 >= 0 && vis[contIdx[0] - 1][contIdx[1]] == 0) { // Up -1, 0, left is invalid or blocked, move to up
			contIdx[0]--;
			// up-no change
			vis[contIdx[0]][contIdx[1]] = 1;
			ans[idx] = contCol;
		} else {
			assert(1 == 2);
			// cout << "SHOULD NOT REACH (Contrib) ::: " << idx << endl;
		}
	};

	auto goToRight = [&]() {
		while (nonContCol == contCol) {	// skipping the contribution column...
			nonContIdx[1]++;
			nonContCol++;
		}

		while (nonContIdx[1] < m && vis[nonContIdx[0]][nonContIdx[1]] == 1) {	// if visited befored...
			nonContIdx[1]++;
			nonContCol++;
		}
	};

	function<void(int)> moveNonContributionIdx = [&](int idx) {
		goToRight();
		if (nonContCol == contCol) {	// now we are at the contribution column..
			goToRight();	// we have to move right, skipping the contribution column...
		}
		if (nonContIdx[1] < m) {	// right has room to fill
			vis[nonContIdx[0]][nonContIdx[1]] = 1;
			ans[idx] = nonContCol;
			return;
		} else if (nonContIdx[0] - 1 >= 0) {	// no way to go to right, move to up to top-left -1, 0
			nonContCol = (nonContIdx[0] - 1 == 0 ? contCol + 1 : 1);
			nonContIdx[0]--;
			nonContIdx[1] = (nonContIdx[0] == 0 ? contCol : 0);
			moveNonContributionIdx(idx);
		} else {
			assert(1 == 2);
			// cout << "SHOULD NOT REACH (non Contrib) ::: " << idx << endl;
		}
	};

	intll summ = 0;
	for (int i = 0, j = 0; i < n * m; i++) {
		// contribution index...
		if (j < n + m - 1 && i == argIdx[j]) {
			moveContributionIdx(i);
			summ += arr[i][0];
			j++;
		} else {
			moveNonContributionIdx(i);
		}
	}

	cout << summ << endl;
	PRINT(ans);
}

int32_t main() {

	// Test Case
	bool TEST_CASE = true;

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