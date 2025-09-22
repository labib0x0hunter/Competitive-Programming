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
void init(int n) {
	tree.resize(4 * n);
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

// log(n)
void update(int node_index, int l, int r, int index, int value) {
	if (l > R || r < L) return;
	if (l == r && l == index) {
		// value replace
		tree[node_index] = value;

		// // value operation
		// tree[node_index] += value;
		return;
	}

	// index, range
	int left_child = 2 * node_index;
	int right_child = left_child + 1;
	int mid = (l + r) / 2;

	update(left_child, l, mid, arr);
	update(right_child, mid + 1, r, arr);

	// operation
	tree[node_index] = tree[left_child] + tree[right_child];
}

// logn
int query(int node_index, int l, int r, int L, int R) {

	cout << node_index << " " << l << " " << L << " " << r << " " << R << endl;

	// out of range
	if (l > R || r < L) return 0; // appropiate value

	// fall-through range
	if (l >= L && r <= R) return tree[node_index];

	// range er moddhe asi
	int left_child = 2 * node_index;
	int right_child = left_child + 1;
	int mid = (l + r) / 2;

	int left_value = query(left_child, l, mid, L, R);
	int right_value = query(right_child, mid + 1, r, L, R);

	return left_value + right_value;
}


void solution() {

	vector<int> arr = {2, 3, 1, 2, 1, 2, 2, 1};

	// init(array size)
	init(arr.size());

	// build(root_index, root_index_i, root_index_j, arr);
	build(1, 1, arr.size(), arr);

	int L = 2, R = 10;
	cout << query(1, 1, arr.size(), L, R) << endl;

	update(1, 1, arr.size(), 7, 10);


	// PRINT(tree);
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