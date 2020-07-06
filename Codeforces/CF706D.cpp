#include <bits/stdc++.h>
using namespace std;
const int B = 31;
const int N = 2e5;
int q;

int nodecnt, cnt[B * N], trie[B * N][2];

void insert(int x) {
	int node = 0;
	int idx = B - 1;
	while (idx != -1) {
		int i = !!(x & (1 << idx));
		if (!trie[node][i]) {
			trie[node][i] = ++nodecnt;
		}
		node = trie[node][i];
		cnt[node]++;
		idx--;
	}
}

void remove(int x) {
	int node = 0;
	int idx = B - 1;
	while (idx != -1) {
		int i = !!(x & (1 << idx));
		node = trie[node][i];
		cnt[node]--;
		idx--;
	}
}

int query(int x) {
	int node = 0;
	int idx = B - 1;
	int ans = 0;
	while (idx != -1) {
		int i = !(x & (1 << idx));
		if (trie[node][i] && cnt[trie[node][i]]) {
			ans |= (1 << idx);
			node = trie[node][i];
		}
		else {
			node = trie[node][!i];
		}
		idx--;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;

	insert(0);

	int v;
	char op;
	for (int i = 0; i < q; i++) {
		cin >> op >> v;
		if (op == '+') {
			insert(v);
		}
		else if (op == '-') {
			remove(v);
		}
		else {
			cout << query(v) << '\n';
		}
	}

	return 0;
}
