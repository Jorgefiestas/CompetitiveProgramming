#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, e[N], s[N];
string t;

struct AhoCorasick {
	int trie[N][26];
	int term[N];
	int par[N];
	int tran[N];
	int link[N];
	int nodecnt = 1;
	bool vis[N];

	AhoCorasick() {
		memset(trie, -1, sizeof trie);
		memset(link, -1, sizeof link);
		memset(term, 0, sizeof term);
		memset(vis, 0, sizeof vis);
	}

	void insert(const string &str) {
		int node = 0;
		for (char c : str) {
			int i = c - 'a';
			if (trie[node][i] == -1) {
				tran[nodecnt] = c;
				par[nodecnt] = node;
				trie[node][i] = nodecnt++;
			}
			node = trie[node][i];
		}
		term[node]++;
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
		int i = c - 'a';
		if (trie[node][i] == -1) {
			trie[node][i] = node ? go(getLink(node), c) : 0;
		}
		return trie[node][i];
	}

	int count(int node) {
		if (!node || vis[node]) {
			return term[node];
		}
		vis[node] = true;
		term[node] += count(getLink(node));
		return term[node];
	}

} ac, acr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t >> n;

	string si;
	for (int i = 0; i < n; i++) {
		cin >> si;
		ac.insert(si);
		reverse(si.begin(), si.end());
		acr.insert(si);
	}

	int node = 0;
	for (int i = 0; i < t.size(); i++) {
		char c = t[i];
		node = ac.go(node, c);
		e[i] = ac.count(node);
	}

	node = 0;
	for (int i = t.size() - 1; i >= 0; i--) {
		char c = t[i];
		node = acr.go(node, c);
		s[i] = acr.count(node);
	}

	long long ans = 0;
	for (int i = 0; i < t.size() - 1; i++) {
		ans += (long long) e[i] * s[i + 1];
	}

	cout << ans << '\n';

	return 0;
}
