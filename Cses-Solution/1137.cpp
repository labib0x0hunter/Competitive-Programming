// https://cses.fi/problemset/task/1137/

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
struct binary_index_tree {
#define LSONE(x) ((x) & -(x))

	int N;
	vector<T> t;

	binary_index_tree() {}
	binary_index_tree(int n) : N(n) {
		t.resize(N + 1);
	}
	binary_index_tree(vector<int>& arr) {
		N = int(arr.size());
		t.resize(N + 1);

		for (int i = 1; i <= N; i++)
			update(i, arr[i - 1]);
	}

	void update(int i, T x) {
		while (i <= N) {
			t[i] += x;
			i += LSONE(i);
		}
	}

	T query(int i) {
		T summ = 0;
		while (i > 0) {
			summ += t[i];
			i -= LSONE(i);
		}
		return summ;
	}

	void range_update(int l, int r, T x) {
		update(l, x);
		update(r + 1, -x);
	}

	// Find first index x such that summ(x) >= s
	int find_first(T s) {
		// Find last index x such that summ(x) < s
		int index = 0;
		int k = 0;

		while (1 << (k + 1) <= N)
			k++;
		while (k >= 0) {
			int next_index = index + (1 << k);
			if (next_index <= N and t[next_index] < s) {
				index = next_index;
				s -= t[index];
			}
			k--;
		}
		return index + 1;
	}
};

// Range Update Range Query
// Add to every element
template<typename T = int>
struct RURQ {

	binary_index_tree<T> rupq, purq;
	RURQ() {}
	RURQ(int m) {
		rupq = binary_index_tree<T>(m);
		purq = binary_index_tree<T>(m);
	}
	RURQ(vector<int>& arr) {
		rupq = binary_index_tree<T>(int(arr.size()));
		purq = binary_index_tree<T>(int(arr.size()));
		for (int i = 1; i <= int(arr.size()); i++)
			range_update(i, i, arr[i - 1]);
	}

	void range_update(int i, int j, T x) {
		rupq.range_update(i, j, x);
		purq.update(i, 1ll * x * (i - 1));
		purq.update(j + 1, -1ll * x * j);
	}

	// Range Query
	T query(int i) {
		return 1ll * rupq.query(i) * i - purq.query(i);
	}
};


vector<vector<int>> graph;

void init(int n) {
	graph.clear();

	graph.resize(n + 1);
}

void add_edge(int u, int v) {
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void graph_input(int n) {
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}
}

void graph_input_line(int n) {
	for (int i = 2; i <= n; i++) {
		int u;
		cin >> u;
		add_edge(u, i);
	}
}

void solution() {

	int n, q;
	cin >> n >> q;

	vector<int> value(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}

	init(n);
	graph_input(n - 1);

	vector<int> in(n + 1), out(n + 1);
	int tour_time = 1;

	function<void(int, int)> dfs = [&](int s, int p) {
		in[s] = tour_time++;
		for (int u : graph[s]) {
			if (u != p) dfs(u, s);
		}
		// both are AC
		out[s] = tour_time++;
		// out[s] = tour_time - 1;
	};

	dfs(1, 0);

	// PRINT(in);
	// PRINT(out);

	binary_index_tree<intll> bt(n + n + 10);
	for (int i = 1; i <= n; i++) {
		bt.update(in[i], value[i]);
	}

	while (q--) {
		int idx, u, x;
		cin >> idx;

		if (idx == 1) {
			cin >> u >> x;
			bt.update(in[u], -value[u]);
			bt.update(in[u], x);
			value[u] = x;
		} else {
			cin >> u;
			cout << bt.query(out[u]) - bt.query(in[u] - 1) << endl;
		}
	}
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