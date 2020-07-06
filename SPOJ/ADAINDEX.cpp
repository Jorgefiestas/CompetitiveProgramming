#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, q;

int nodecnt, trie[N][26], cnt[N];

void insert(const string &str) {
	int node = 0;
	for (char c : str) {
		int i = c - 'a';
		if (!trie[node][i]) {
			trie[node][i] = ++nodecnt;
		}
		node = trie[node][i];
		cnt[node]++;
	}
}

int query(const string &str) {
	int node = 0;
	for (char c : str) {
		int i = c - 'a';
		if (!trie[node][i]) {
			return 0;
		}
		node = trie[node][i];
	}
	return cnt[node];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		insert(str);
	}

	for (int i = 0; i < q; i++) {
		cin >> str;
		cout << query(str) << '\n';
	}

	return 0;
}
