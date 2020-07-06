#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int B = 25;
int t, n, k;

struct Trie {
	Trie* children[2] = {nullptr, nullptr};
	int cnt = 0;

	void insert(int x, int idx) {
		cnt++;
		if (idx == -1) {
			return;
		}

		int c = (x & (1 << idx)) ? 1 : 0;
		if (!children[c]) {
			children[c] = new Trie();
		}
		children[c]->insert(x, idx - 1);
	}

	long long query(int x, int idx) {
		if (idx == -1) {
			return 0;
		}

		int c = (x & (1 << idx)) ? 1 : 0;
		int s = (k & (1 << idx)) ? 1 : 0;

		if (s == 0) {
			return children[c] ? children[c]->query(x, idx - 1) : 0;
		}

		long long ans = 0;
		if (children[c]) {
			ans += (long long) children[c]->cnt;
		}
		if (children[1 - c]) {
			ans += children[1 - c]->query(x, idx - 1);
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;

		Trie* root = new Trie();
		root->insert(0, B);

		int a, pref = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			pref ^= a;
			ans += root->query(pref, B);
			root->insert(pref, B);
		}

		cout << ans << '\n';
	}

	return 0;
}
