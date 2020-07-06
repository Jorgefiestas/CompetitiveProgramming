#include <bits/stdc++.h>
using namespace std;
const int M = 65;
const int N = 2e5 + 100;
int n, m, k;
int trie[N * M][2];
long long cnt[N * M];
bool term[N * M];

int exp(int x) {
	return (1LL << (long long) x);
}

int nodecnt;
void insert(const string &x) {
	int idx = 0;
	int node = 0;
	while (idx < m && x[idx] != '*') {
		int i = (x[idx] == '1');

		if (!trie[node][i]) {
			trie[node][i] = ++nodecnt;
		}

		idx++;
	}
	term[node] = true;
}

void connect(int node, int link, int idx) {
	if (term[node]) {
		link = node;
	}

	if (trie[node][0]) {
		connect(trie[node][0], link, idx + 1);
	}
	else {
		cnt[link] += exp(m - idx - 1);
	}

	if (trie[node][1]) {
		connect(trie[node][1], link, idx + 1);
	}
	else {
		cnt[link] += exp(m - idx - 1);
	}
}

long long query(const string &x) {
	int idx = 0;
	int node = 0;
	while (idx < m && x[idx] != '*') {
		int i = (x[idx] == '1');

		if (!trie[node][i]) {
			break;
		}

		idx++;
	}

	return (long long) cnt[node] * (1LL << (long long) (m - idx));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m) {
		memset(trie, 0, sizeof trie);
		cnt[0] = 2;
		nodecnt = 0;

		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			insert(str);
		}

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> str;
			cout << query(str) << '\n';
		}
	}

	return 0;
}
