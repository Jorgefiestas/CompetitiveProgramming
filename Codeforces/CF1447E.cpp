#include <bits/stdc++.h>
using namespace std;
const int N = 5e6;
const int L = 32;
int n, cnt[L];

struct Trie {
	int trie[N][2];
	int cnt[N];
	int dp[N];
	int nodecnt = 1;

	Trie() {
		memset(trie, 0, sizeof trie);
		memset(cnt, 0, sizeof cnt);
		memset(dp, 0, sizeof dp);
	}

	void add(int x) {
		int node = 0;
		for (int i = 31; i >= 0; i--) {
			int idx = !!(x & (1 << i));

			if (!trie[node][idx]) {
				trie[node][idx] = nodecnt;
				nodecnt += 1;
			}
			node = trie[node][idx];
			cnt[node] += 1;
		}
	}

	void calc(int node) {
		int lc = trie[node][0];
		int rc = trie[node][1];

		if (lc) calc(lc);
		if (rc) calc(rc);

		int can1 = max(cnt[lc] - 1, 0) + dp[rc];
		int can2 = max(cnt[rc] - 1, 0) + dp[lc];

		dp[node] = min(can1, can2);
	}
};

Trie trie;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		trie.add(ai);
	}

	trie.calc(0);
	cout << trie.dp[0] << '\n';

	return 0;
}
