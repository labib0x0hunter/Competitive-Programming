struct node {
	using T = int;
	T val;
};

template<typename T = node>
struct segment_tree_lazy {
	using TT = typename node::T;

	int N;
	vector<T> t;
	vector<TT> lazy;
	TT LazyValue = 0;  // Change LazyValue

	segment_tree_lazy() {}
	segment_tree_lazy(int N) : N(N) {
		t.resize(4 * (N + 1), T{0});   // Set Value
		lazy.resize(4 * (N + 1), LazyValue);
	}
	segment_tree_lazy(vector<int> & arr) {       // ARRAY TYPE
		N = int(arr.size());
		t.resize(4 * (N + 1), T{0});  // Set value
		lazy.resize(4 * (N + 1), LazyValue);
		build(1, 1, N, arr);
	}

	// Out of Range
	T E() {
		return T{0};
	}

	// Operation
	T combine(T a, T b) {
		T res;
		res.val = a.val + b.val;
		return res;
	}

	// Change here if you want to replace each element to x from i to j
	// t[n].summ = lazy[n] * (e - b + 1)
	// lazy[n * 2] = lazy[n]
	void push(int n, int b, int e) {
		// Especially When replacing values
		// also change from Constructor
		if (lazy[n] == LazyValue) return;  // CareFul Here Updaing with LazyValue can leads to bugs
		t[n].val = t[n].val + (TT) lazy[n] * (e - b + 1);
		// t[n].minn = t[n].minn + lazy[n];
		// t[n].maxx = t[n].maxx + lazy[n];
		if (b != e) {
			lazy[n * 2] = lazy[n * 2] + lazy[n];
			lazy[n * 2 + 1] = lazy[n * 2 + 1] + lazy[n];
		}
		lazy[n] = LazyValue;
	}

	void build(int n, int b, int e, vector<int>&a) {    // ARRAY TYPE
		if (b == e) {
			t[n].val = a[b - 1];                      // leaf nodes
			return;
		}
		int mid = (b + e) >> 1, l = n << 1, r = l | 1;
		build(l, b, mid, a);
		build(r, mid + 1, e, a);
		t[n] = combine(t[l], t[r]);
	}

	void update(int n, int b, int e, int i, int j, TT x) {     // UPDATE TYPE
		push(n, b, e);
		if (b > j || e < i) return;
		if (b >= i && e <= j) {
			lazy[n] = x;                                      // add lazy
			push(n, b, e);
			return;
		}
		int mid = (b + e) >> 1, l = n << 1, r = l | 1;
		update(l, b, mid, i, j, x);
		update(r, mid + 1, e, i, j, x);
		t[n] = combine(t[l], t[r]);
	}

	T query(int n, int b, int e, int i, int j) {
		push(n, b, e);
		if (b > j || e < i) return E();                 // appropiate value
		if (b >= i && e <= j) return t[n];
		int mid = (b + e) >> 1, l = n << 1, r = l | 1;
		T L = query(l, b, mid, i, j);
		T R = query(r, mid + 1, e, i, j);
		return combine(L, R);
	}

	int kth(int n, int b, int e, int k) {
		push(n, b, e);
		if (b == e) return b;
		int mid = (b + e) >> 1, l = n << 1, r = l | 1;
		push(l, b, mid);
		int value = t[l].val;                           // left value
		if (k <= value) return kth(l, b, mid, k);
		else return kth(r, mid + 1, e, k - t[l].val);   // goto right child
	};

	template <class F>
	int find_right(int n, int b, int e, int idx, F&& check) {
		push(n, b, e);
		if (b == e) return (check(t[n]) && b >= idx ? b : -1);
		int mid = (b + e) >> 1, l = n << 1, r = l | 1;
		int index = -1;
		push(l, b, mid);
		if (check(t[l]) and mid >= idx) index = find_right(l, b, mid, idx, check);
		if (index == -1) index = find_right(r, mid + 1, e, idx, check);
		return index;
	}

	template <class F>
	int find_left(int n, int b, int e, int idx, F&& check) {
		push(n, b, e);
		if (b == e) return (check(t[n]) && b <= idx ? b : -1);
		int mid = (b + e) >> 1, l = n << 1, r = l | 1;
		int index = -1;
		push(l, b, mid);
		if (check(t[l])) index = find_left(l, b, mid, idx, check);
		if (index == -1) index = find_left(r, mid + 1, e, idx, check);
		return index;
	}

	// position j such_that compare(NODE VALUE x) is TRUE and j >= l
	// position j such that x <= arr[j] and j >= l (maxx segment tree)
	// position j such that x >= arr[j] and j >= l (minn segment tree)
	template <class F>
	int find_right(int l, F&& check) { return find_right(1, 1, N, l, check); }

	// position j such_that compare(NODE VALUE x) is TRUE and j <= l
	// position j such that x <= arr[j] and j <= l (maxx segment tree)
	// position j such that x >= arr[j] and j <= l (minn segment tree)
	template <class F>
	int find_left(int l, F&& check) { return find_left(1, 1, N, l, check); }

	// position of kth element
	int kth(int k) { return t[1].val < k ? -1 : kth(1, 1, N, k); }

	// update
	void update(int l, int r, TT x) { update(1, 1, N, l, r, x); }

	// query
	TT query(int l, int r) { T ans = query(1, 1, N, l, r); return ans.val; }
};

