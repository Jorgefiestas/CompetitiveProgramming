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
};
