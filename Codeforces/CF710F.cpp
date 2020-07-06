#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 100;
const int LOGN = 20;
int m;

struct AhoCorasick {
	int nodecnt = 0;

	int trie[N][26];
	int term[N];
	int par[N];
	int tran[N];
	int link[N];
	bool vis[N];

	AhoCorasick() {
		memset(trie, -1, sizeof trie);
		memset(link, -1, sizeof link);
		memset(term, 0, sizeof term);
		memset(vis, 0, sizeof vis);
	}

	int newRoot() {
		return nodecnt++;
	}

	void insert(int node, const string &str) {
		for (char c : str) {
			int i = c - 'a';
			if (trie[node][i] == -1) {
				tran[nodecnt] = c;
				par[nodecnt] = node;
				trie[node][i] = nodecnt++;
			}
			node = trie[node][i];
		}
		term[node] += 1;
	}

	int getLink(int node, int root) {
		if (link[node] == -1) {
			if (node == root || par[node] == root) {
				return link[node] = root;
			}
			return link[node] = go(getLink(par[node], root), tran[node], root);
		}
		return link[node];
	}

	int go(int node, char c, int root) {
		int i = c - 'a';
		if (trie[node][i] == -1) {
			if (node == root) {
				trie[node][i] = node;
			}
			trie[node][i] = go(getLink(node, root), c, root);
		}
		return trie[node][i];
	}

	int count(int node, int root) {
		if (node == root || vis[node]) {
			return term[node];
		}
		vis[node] = true;
		term[node] += count(getLink(node, root), root);
		return term[node];
	}

	int query(int root, const string &str) {
		int ans = 0;
		
		int node = root;
		for (char c : str) {
			node = go(node, c, root);
			ans += count(node, root);
		}
		return ans;
	}
};

struct Block {
	AhoCorasick ac;

	int root[LOGN];
	int block[LOGN];
	int size[LOGN];

	Block() {
		for (int i = 0; i < LOGN; i++) {
			root[i] = -1;
			size[i] = 0;
			block[i] = ac.newRoot();
		}
	}

	void insert(const string &str) {
		for (int i = 0; i < LOGN; i++) {
			ac.insert(block[i], str);
			size[i] += 1;

			if (size[i] == (1 << i)) {
				root[i] = block[i];
				block[i] = ac.newRoot();
				size[i] = 0;
				for (int j = 0; j < i; j++) {
					root[j] = -1;
				}
			}

		}
	}

	int query(const string &str) {
		int ans = 0;
		for (int i = 0; i < LOGN; i++) {
			if (root[i] == -1) continue;
			ans += ac.query(root[i], str);
		}
		return ans;
	}
};

Block addBlock, remBlock;

int query(const string &str) {
	return addBlock.query(str) - remBlock.query(str);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;

	int op;
	string str;
	for (int qi = 0; qi < m; qi++) {
		cin >> op >> str;

		if (op == 1) {
			addBlock.insert(str);
		}
		else if (op == 2) {
			remBlock.insert(str);
		}
		else {
			cout << query(str) << endl;
		}
	}

	return 0;
}
