#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
const int B = 30;
int cache, n, m, a[N], dsu[N], vis[N];
int trie[30 * N][2], cnt[30 * N], val[30 * N];
vector<int> sets[N];

int dsu_root(int a) {
	while (a != dsu[a]) {
		dsu[a] = dsu[dsu[a]];
		a = dsu[a];
	}
	return a;
}

void dsu_join(int a, int b) {
	int ra = dsu_root(a);
	int rb = dsu_root(b);

	if (ra == rb) return;
	if (sets[ra].size() < sets[rb].size()) {
		swap(ra, rb);
	}

	for (int k : sets[rb]) {
		sets[ra].emplace_back(k);
	}

	dsu[rb] = ra;
}

int triecnt = 1;

void trie_remove(int x) {
	int idx = B;
	int node = 0;
	while (idx >= 0) {
		cnt[node]--;
		int c = (x & (1 << idx)) ? 1 : 0;
		node = trie[node][c];
		idx--;
	}
	cnt[node]--;
}

void trie_insert(int x, int p) {
	int idx = B;
	int node = 0;
	while (idx >= 0) {
		cnt[node]++;
		int c = (x & (1 << idx)) ? 1 : 0;
		if (!trie[node][c]) {
			trie[node][c] = triecnt++;
		}
		node = trie[node][c];
		idx--;
	}
	cnt[node]++;
	val[node] = p;
}

int trie_query(int x) {
	int ans = 0;
	int idx = B;
	int node = 0;
	while (idx >= 0) {
		int c = (x & (1 << idx)) ? 1 : 0;
		if (trie[node][c] && cnt[trie[node][c]]) {
			node = trie[node][c];
		}
		else {
			ans |= (1 << idx);
			node = trie[node][1 - c];
		}
		idx--;
	}
	cache = val[node];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int x;
	set<int> seen;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (seen.count(x)) continue;
		dsu[m] = m;
		sets[m].emplace_back(x);
		a[m] = x;
		seen.insert(x);
		trie_insert(x, m);
		m++;
	}

	long long mst = 0;
	int ccs = m, v = 1;
	while (ccs > 1) {
		vector<pii> edgs;
		vector<int> vals;
		for (int i = 0; i < m; i++) {
			int p = dsu_root(i);
			if (vis[p] == v) continue;
			vis[p] = v;

			for (int k : sets[p]) {
				trie_remove(k);
			}

			int ans = INT_MAX;
			int toJoin = -1;
			for (int k : sets[p]) {
				int tans = trie_query(k);
				if (tans < ans) {
					ans = tans;
					toJoin = cache;
				}
			}
			edgs.push_back({p, toJoin});
			vals.emplace_back(ans);

			for (int k : sets[p]) {
				trie_insert(k, p);
			}
		}

		for (int i = 0; i < edgs.size(); i++) {
			pii e = edgs[i];
			if (dsu_root(e.first) == dsu_root(e.second)) continue;
			dsu_join(e.first, e.second);
			mst += vals[i];
			ccs--;
		}

		v++;
	}

	cout << mst << '\n';
	return 0;
}
