#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const int N = 5005;
int n, m, w, q;
vector<pii> stores[N];
vector<int> adjList[N];
bool vis[N];

struct Set {
	multiset<pii> st;
	long long cap = 0;
	long long cnt = 0;
	long long sum = 0;

	Set(int c) {
		cap = c;
	}
	
	void add(long long k, long long p) {
		st.insert({p, k});
		cnt += k;
		sum += k * p;

		while (sum > cap) {
			auto [lp, lk] = *prev(st.end());
			st.erase(prev(st.end()));

			cnt -= lk;
			sum -= lk * lp;

			long long nk = max((cap - sum) / lp, 0LL);

			if (nk > 0) {
				cnt += nk;
				sum += nk * lp;
				st.insert({lp, nk});
			}
		}
	}
};

int query(int g, long long r, long long a) {
	memset(vis, 0, sizeof vis);
	queue<pii> q;
	Set st(a);

	q.push({g, 0});
	vis[g] = true;

	while (!q.empty()) {
		int v = q.front().first;
		int d = q.front().second;
		q.pop();

		for (auto [k, p] : stores[v]) {
			st.add(k, p);
		}
		if (st.cnt >= r) {
			return d;
		}

		for (int u : adjList[v]) {
			if (vis[u]) continue;
			vis[u] = true;
			q.push({u, d + 1});
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	cin >> w;

	int ci;
	long long ki, pi;
	for (int i = 0; i < w; i++) {
		cin >> ci >> ki >> pi;
		stores[ci].push_back({ki, pi});
	}

	cin >> q;

	int gi;
	long long ri, ai;
	for (int qi = 0; qi < q; qi++) {
		cin >> gi >> ri >> ai;
		cout << query(gi, ri, ai) << '\n';
	}

	return 0;
}
