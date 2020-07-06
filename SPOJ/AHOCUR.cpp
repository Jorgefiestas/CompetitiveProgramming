#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pcd = pair<char, ld>;
const int N = 900;
int t, k, n, l;
ld dp[105][N];

struct AhoCorasick {
	int trie[N][65];
	int par[N];
	int tran[N];
	int link[N];
	int nodecnt = 1;
	bool term[N];
	bool vis[N];

	int getIndex(char c) {
		if ('0' <= c && c <= '9') {
			return c - '0';
		}
		if ('a' <= c && c <= 'z') {
			return 10 + c - 'a';
		}
		return 36 + c - 'A';
	}

	AhoCorasick() {
		memset(trie, -1, sizeof trie);
		memset(link, -1, sizeof link);
		memset(term, 0, sizeof term);
		memset(vis, 0, sizeof vis);
	}

	void insert(const string &str) {
		int node = 0;
		for (char c : str) {
			int i = getIndex(c);
			if (trie[node][i] == -1) {
				tran[nodecnt] = c;
				par[nodecnt] = node;
				trie[node][i] = nodecnt++;
			}
			node = trie[node][i];
		}
		term[node] = true;
	}

	int getLink(int node) {
		if (link[node] == -1) {
			if (!node || !par[node]) {
				return link[node] = 0;
			}
			return link[node] = go(getLink(par[node]), tran[node]);
		}
		return link[node];
	}

	int go(int node, char c) {
		int i = getIndex(c);
		if (trie[node][i] == -1) {
			trie[node][i] = node ? go(getLink(node), c) : 0;
		}
		return trie[node][i];
	}

	bool isTerm(int node) {
		if (!node || vis[node]) {
			return term[node];
		}
		vis[node] = true;
		return term[node] = term[node] || isTerm(getLink(node));
	}
};

ld solve() {
	cin >> k;

	AhoCorasick ac;

	string pat;
	for (int i = 0; i < k; i++) {
		cin >> pat;
		ac.insert(pat);
	}

	cin >> n;

	ld p;
	char c;
	vector<pcd> sigma;

	for (int i = 0; i < n; i++) {
		cin >> c >> p;
		sigma.push_back({c, p});
	}

	cin >> l;

	ld ans = 1;

	dp[1][0] = 1.0;
	for (int i = 1; i <= l + 1; i++) {
		for (int s = 0; s < ac.nodecnt; s++) {
			if (dp[i][s] == 0 || ac.isTerm(s)) {
				ans -= dp[i][s];
				continue;
			}

			for (pcd p : sigma) {
				int nxt = ac.go(s, p.first);
				dp[i + 1][nxt] += dp[i][s] * p.second;
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	cout << fixed << setprecision(6);
	for (int i = 1; i <= t; i++) {
		memset(dp, 0, sizeof dp);
		ld ans = solve();
		cout << "Case #" << i << ": " << ans << '\n';
	}

	return 0;
}
