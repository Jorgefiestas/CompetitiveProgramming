#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pli = pair<long long, int>;
const int N = 1e5 + 10;
int n, m, p, q;
vector<pii> moves;

struct DSU {
	int par[N];
	long long val[N];

	DSU() {
		for (int i = 0; i < N; i++) {
			par[i] = i;
			val[i] = 0;
		}
	}

	int root(int a) {
		while (a != par[a]) {
			par[a] = par[par[a]];
			a = par[a];
		}
		return a;
	}

	void join(int a, int b) {
		int ra = root(a);
		int rb = root(b);

		if (ra != rb) {
			par[ra] = rb;
			val[rb] += val[ra];
		}
	}
};

DSU dsu;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p >> q;

	int a = 0;
	int b = 0;
	long long w;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;

		dsu.join(a, b);
		int rt = dsu.root(a);
		dsu.val[rt] += w;
	}

	priority_queue<pli> pq;
	set<int> seen;

	for (int i = 1; i <= n; i++) {
		int rt = dsu.root(i);
		if (seen.count(rt)) continue;

		seen.insert(rt);
		pq.push({-dsu.val[rt], rt});
	}

	int cnt = seen.size();
	if (cnt < q || cnt - p > q) {
		cout << "NO\n";
		return 0;
	}

	long long ans = 0;

	while (cnt != q) {
		auto [wu, u] = pq.top();
		pq.pop();
		auto [wv, v] = pq.top();
		pq.pop();


		moves.push_back({u, v});
		a = u, b = v;

		dsu.join(u, v);
		int rt = dsu.root(u);
		dsu.val[rt] += min((long long) 1e9, -wu - wv + 1);

		pq.push({-dsu.val[rt], rt});

		cnt -= 1;
		p -= 1;
	}

	while (p) {
		if (a == 0) {
			cout << "NO\n";
			return 0;
		}

		moves.push_back({a, b});
		p -= 1;
	}

	cout << "YES\n";

	for (auto [u, v] : moves) {
		cout << u << ' ' << v << '\n';
	}

	return 0;
}
