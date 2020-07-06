#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
using pii = pair<int, int>;
int n, k[N], sz[N];
string s;

struct AhoCorasick {
	int trie[N][26];
	int par[N];
	int tran[N];
	int link[N];
	int nodecnt = 1;
	int itn[N];
	bool vis[N];
	vector<int> term[N];

	vector<int> occ[N];

	AhoCorasick() {
		memset(trie, -1, sizeof trie);
		memset(link, -1, sizeof link);
		memset(term, 0, sizeof term);
		memset(vis, 0, sizeof vis);
	}

	void insert(const string &str, int qi) {
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
		term[node].emplace_back(qi);
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

	void endsInNode(int node) {
		if (vis[node]) return;
		vis[node] = true;

		int suff = getLink(node);
		endsInNode(suff);

		for (int x : term[suff]) {
			term[node].emplace_back(x);
		}
	}
} ac;

vector<int> idx[N];

void addOcc(int node, int i) {
	ac.endsInNode(node);
	for (int x : ac.term[node]) {
		idx[x].emplace_back(i);
	}
}

int solve(int qi, int k) {
	if (idx[qi].size() < k) {
		return -1;
	}

	sort(idx[qi].begin(), idx[qi].end());

	int ans = INT_MAX;
	for (int i = k - 1; i < idx[qi].size(); i++) {
		ans = min(ans, idx[qi][i] - idx[qi][i - k + 1] + sz[qi]);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> n;

	string m;
	for (int i = 0; i < n; i++) {
		cin >> k[i] >> m;
		sz[i] = m.size();
		ac.insert(m, i);
	}

	int node = 0;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		node = ac.go(node, c);
		addOcc(node, i);
	}

	for (int qi = 0; qi < n; qi++) {
		cout << solve(qi, k[qi]) << '\n';
	}

	return 0;
}
