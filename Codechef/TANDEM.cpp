#include <bits/stdc++.h>
using namespace std;
const int N = 3e6;
int w, n, cnt[N], nodes[N];

struct AhoCorasick {
	int trie[N][100];
	int par[N];
	char tran[N];
	int link[N];
	int nodecnt = 1;
	bool vis[N];
	vector<int> super[N];
	int cnt[N];

	AhoCorasick() {
		memset(trie, -1, sizeof trie);
		memset(link, -1, sizeof link);
		memset(vis, 0, sizeof vis);
		memset(cnt, 0, sizeof cnt);
	}

	int to_idx(char c) {
		if (c == '-') {
			return 90;
		}
		if ('0' <= c && c <= '9') { 
			return c - '0';
		}
		if ('A' <= c && c <= 'Z') {
			return 10 + (int) (c - 'A');
		}
		return 36 + (int) (c - 'a');
	}

	int insert(const string &str) {
		int node = 0;
		for (char c : str) {
			int i = to_idx(c);
			if (trie[node][i] == -1) {
				tran[nodecnt] = c;
				par[nodecnt] = node;
				trie[node][i] = nodecnt++;
			}
			node = trie[node][i];
		}

		return node;
	}

	int getLink(int node) {
		if (link[node] == -1) {
			if (!node || !par[node]) {
				return link[node] = 0;
			}
			link[node] = go(getLink(par[node]), tran[node]);
			super[link[node]].emplace_back(node);
			return link[node];
		}
		return link[node];
	}

	int go(int node, char c) {
		int i = to_idx(c);
		if (trie[node][i] == -1) {
			trie[node][i] = node ? go(getLink(node), c) : 0;
		}
		return trie[node][i];
	}

	void calc(){
		for (int i = 0; i < nodecnt; i++) {
			getLink(i);
		}
	}

	int count(int node) {
		if (vis[node]) {
			return cnt[node];
		}
		vis[node] = true;

		for (int sl : super[node]) {
			cnt[node] += count(sl);
		}

		return cnt[node];
	}
} ac;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> w;
	
	string str;
	for (int i = 0; i < w; i++) {
		cin >> str;
		nodes[i] = ac.insert(str);
	}
	ac.calc();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		int node = 0;
		for (char c : str) {
			node = ac.go(node, c);
			ac.cnt[node] += 1;
		}
	}

	for (int i = 0; i < w; i++) {
		cout << ac.count(nodes[i]) << '\n';
	}

	return 0;
}
