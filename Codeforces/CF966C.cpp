#include <bits/stdc++.h>
using namespace std;
const int N = 8e6 + 10;

struct Trie {
	int trie[N][2];
	int cnt[N];
	vector<int> valid[N];

	void add(long long x) {
		int node = 0;
		for (int i = 60; i >= 0; i--) {
			int bi = !!(x & (1LL << i));

			if (!trie[node][bi]) {
				trie[node][bi] = nodecnt++;
			}
			node = trie[node][bi];
			cnt[node] += 1;
		}
	}

	void 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin n;

	long long bi;
	for (int i = 1; i <= n; i++) {
		cin >> bi;
		trie.insert(bi);
	}

	for (int bi = 60; bi >= 0; bi--) {
		for (int i = 0; i < n; i++) {

		}
	}

	return 0;
}
