#include <bits/stdc++.h>
using namespace std;
const int N = 8e6 + 10;
int m, n, root[N];

struct Node {
	int lc = 0, rc = 0, cnt = 0;
	int& operator[](int i) {
		return i ? rc : lc;
	}
};

struct Trie {
	Node trie[N];
	int nodecnt = 1;

	int add(int root, int i, int x) {
		int nroot = nodecnt++;

		trie[nroot] = trie[root];
		trie[nroot].cnt += 1;

		if (i != -1) {
			int ci = !!(x & (1 << i));
			trie[nroot][ci] = add(trie[root][ci], i - 1, x);
		}

		return nroot;
	}

	int max(int lroot, int rroot, int x) {
		int y = 0;
		for (int i = 20; i >= 0; i--) {
			int ci = !(x & (1 << i));
			int lch = trie[lroot][ci];
			int rch = trie[rroot][ci];

			y <<= 1;
			if (trie[rch].cnt - trie[lch].cnt) {
				lroot = trie[lroot][ci];
				rroot = trie[rroot][ci];
				y |= ci;
			}
			else {
				lroot = trie[lroot][!ci];
				rroot = trie[rroot][!ci];
				y |= !ci;
			}
		}
		return y;
	}

	int leq(int root, int x) {
		int ans = 0;
		for (int i = 20; i >= 0; i--) {
			int ci = !!(x & (1 << i));
			int ch = trie[root][ci];

			if (ci == 1) {
				ans += trie[trie[root][0]].cnt;
			}
			root = trie[root][ci];
		}
		ans += trie[root].cnt;
		return ans;
	}

	int kth(int lroot, int rroot, int k) {
		int y = 0;
		for (int i = 20; i >= 0; i--) {
			int lch = trie[lroot][0];
			int rch = trie[rroot][0];
			int lcnt = trie[rch].cnt - trie[lch].cnt;

			y <<= 1;
			if (lcnt >= k) {
				lroot = trie[lroot][0];
				rroot = trie[rroot][0];
			}
			else {
				k -= lcnt;
				lroot = trie[lroot][1];
				rroot = trie[rroot][1];
				y |= 1;
			}
		}
		return y;
	}
};

Trie trie;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;

	int op, l, r, x, k;
	for (int qi = 0; qi < m; qi++) {
		cin >> op;

		if (op == 0) {
			cin >> x;
			root[n + 1] = trie.add(root[n], 20, x);
			n += 1;
		}

		if (op == 1) {
			cin >> l >> r >> x;
			cout << trie.max(root[l - 1], root[r], x) << '\n';
		}

		if (op == 2) {
			cin >> k;
			n -= k;
		}

		if (op == 3) {
			cin >> l >> r >> x;
			cout << trie.leq(root[r], x) - trie.leq(root[l - 1], x) << '\n';
		}

		if (op == 4) {
			cin >> l >> r >> k;
			cout << trie.kth(root[l - 1], root[r], k) << '\n';
		}
	}

	return 0;
}
