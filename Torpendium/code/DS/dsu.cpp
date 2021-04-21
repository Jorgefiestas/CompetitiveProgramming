struct DSU {
	int n;
	vector<int> par;
	vector<int> rank;

	DSU(int n): n(n), par(n), rank(n, 0) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	int root(int idx) {
		while (idx != par[idx]) {
			par[idx] = par[par[idx]];
			idx = par[idx];
		}
		return idx;
	}

	void join(int a, int b) {
		a = root(a);
		b = root(b);

		if (rank[a] < rank[b])
			swap(a, b);

		par[b] = a;
		if (rank[a] == rank[b])
			rank[a]++;
	}
};
