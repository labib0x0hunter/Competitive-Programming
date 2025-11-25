#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T> arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

void build(int node_index, int l, int r, vector<int>& arr);

vector<int> tree;

// 1-index based + init + build
void init(vector<int>& arr) {
	int n = arr.size();
	tree.resize(4 * n);
	build(1, 1, n, arr);
}

// nlog(n)
void build(int node_index, int l, int r, vector<int>& arr) {
	if (l == r) {
		tree[node_index] = arr[l - 1];
		return;
	}

	// index, range
	int left_child = 2 * node_index;
	int right_child = left_child + 1;
	int mid = (l + r) / 2;

	build(left_child, l, mid, arr);
	build(right_child, mid + 1, r, arr);

	// operation
	tree[node_index] = tree[left_child] + tree[right_child];
}


void solution() {

	vector<int> arr = {2, 3, 1, 2, 1, 2, 2, 1};

	init(arr);


	PRINT(tree);
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