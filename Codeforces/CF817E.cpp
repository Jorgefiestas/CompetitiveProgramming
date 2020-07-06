#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int B = 26;
int q, trie[N * B][2], cnt[N * B];

int nodecnt = 1;

void insert(int x) {
	int idx = B;
	int node = 0;
	while (idx != -1) {
		int i = !!(x & (1 << idx));
		if (!trie[node][i]) {
			trie[node][i] = nodecnt++;
		}
		node = trie[node][i];
		cnt[node]++;
		idx--;
	}
}

void remove(int x) {
	int idx = B;
	int node = 0;
	while (idx != -1) {
		int i = !!(x & (1 << idx));
		node = trie[node][i];
		cnt[node]--;
		idx--;
	}
}

int query(int p, int l) {
	int idx = B;
	int node = 0;
	int ans = 0;
	while (idx != -1) {
		int i = !!(p & (1 << idx));
		if (l & (1 << idx)) {
			ans += cnt[trie[node][i]];

			if (!trie[node][!i] || !cnt[trie[node][!i]]) {
				break;
			}
			node = trie[node][!i];
		}
		else {
			if (!trie[node][i] || !cnt[trie[node][i]]) {
				break;
			}
			node = trie[node][i];
		}
		idx--;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;

	int op, p, l;
	for (int i = 0; i < q; i++) {
		cin >> op;

		if (op == 1) {
			cin >> p;
			insert(p);
		}
		if (op == 2) {
			cin >> p;
			remove(p);
		}
		if (op == 3) {
			cin >> p >> l;
			cout << query(p, l) << '\n';
		}
	}

	return 0;
}
