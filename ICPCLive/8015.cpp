#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m, trie[10 * N][26];
vector<string> alice;

int nodecnt, cnt[10 * N];

void insert(const string &str) {
	int node = 0;
	cnt[node]++;
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
	int d = 0;
	int mx = cnt[0] + 1;
	for (char c : str) {
		int i = c - 'a';
		if (!trie[node][i]) break;
		node = trie[node][i];
		d++;
		mx--;
		mx = min(mx, cnt[node]);
		if (mx == 1) break;
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m) {
		memset(trie, 0, sizeof trie);
		memset(cnt, 0, sizeof cnt);
		alice.clear();
		nodecnt = 0;

		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			alice.push_back(str);
		}
		for (int i = 0; i < m; i++) {
			cin >> str;
			insert(str);
		}

		long long ans = 0;
		for (string s : alice) {
			ans += (long long) query(s);
		}

		cout << ans << '\n';
	}

	return 0;
}
