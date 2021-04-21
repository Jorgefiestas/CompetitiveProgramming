#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, q;

struct BipartiteMatching {
	int n, match[N];
	bool used[N];
	vector<int> adjList[N];

	void reset() {
		for (int i = 0; i <= n; i++) {
			adjList[i].clear();
			match[i] = -1;
			used[i] = false;
		}
	}

	bool kuhn(int v) {
		if (used[v])
			return false;

		used[v] = true;
		for (int u : adjList[v]) {
			int mt = match[u];
			if (mt == -1 || kuhn(mt)) {
				match[u] = v;
				return true;
			}
		}

		return false;
	}

	int operator()() {
		for (int i = 1; i <= n; i++) {
			kuhn(i);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (match[i] == -1) continue;
			ans += 1;
		}

		return ans;
	}
};

BipartiteMatching bm;
vector<int> adjList[N];
bool full;

bool query() {
	int m;
	cin >> m;

	if (m == 0) {
		return !full;
	}

	bm.reset();

	int x;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		for (int u : adjList[x]) {
			bm.adjList[x].emplace_back(u);
		}
	}

	int mm = bm();
	return mm == m;
}

void solve() {
	full = false;

	int b;
	for (int i = 1; i <= n; i++) {
		cin >> b;
		full = full || (b == n);

		int a;
		for (int j = 1; j <= b; j++) {
			cin >> a;
			adjList[a].emplace_back(i);
		}
	}

	bm.n = n;

	for (int i = 0; i < q; i++) {
		string out = query() ? "Y\n" : "N\n";
		cout << out;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> q) {
		for (int i = 0; i <= n; i++) {
			adjList[i].clear();
		}

		solve();
	}

	return 0;
}
